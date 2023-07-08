// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MazeCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/HealthComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "UI/PlayerHUD.h"
#include "UI/PlayerOverlay.h"


AMazeCharacter::AMazeCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

	// Ensures that the mouse movement will not be rotating the character mesh and only used to manipulate the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	

	// Creates the object and assigns it a name.  Then attaches the Spring Arm to the root component with a length of 350 units.
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 350.f;

	// Creates the Camera object and attaches it to the Spring Arm
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("View Camera"));
	ViewCamera->SetupAttachment(SpringArm);

	// Make the character move in a forward facing movement state
	GetCharacterMovement()->bOrientRotationToMovement = true;
	// Sets the rate at which the character can rotate
	GetCharacterMovement()->RotationRate = FRotator(0.f, 380.f, 0.f);
}

void AMazeCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PlayerContext, 0);
		}
	}
	
	InitializePlayerOverlay();
}

void AMazeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &AMazeCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMazeCharacter::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMazeCharacter::Jump);
		EnhancedInputComponent->BindAction(DodgeAction, ETriggerEvent::Triggered, this, &AMazeCharacter::Dodge);
		EnhancedInputComponent->BindAction(StunAction, ETriggerEvent::Triggered, this, &AMazeCharacter::ActivateStunParticleSystem);
	}
}

void AMazeCharacter::Jump()
{
	Super::Jump();
}

void AMazeCharacter::Move(const FInputActionValue& Value)
{
	const FVector2d MovementVector = Value.Get<FVector2d>();

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, MovementVector.Y);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDirection, MovementVector.X);
}

void AMazeCharacter::Look(const FInputActionValue& Value)
{
	const FVector2d LookAxisVector = Value.Get<FVector2d>();
	AddControllerPitchInput(LookAxisVector.Y);
	AddControllerYawInput(LookAxisVector.X);
}

void AMazeCharacter::ActivateStunParticleSystem()
{
	if (StunSystem)
	{
		USceneComponent* AttachComp = GetDefaultAttachComponent();

		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(StunSystem, AttachComp, NAME_None,
			FVector(0), FRotator(0), EAttachLocation::Type::KeepRelativeOffset, true);

		NiagaraComp->Activate();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player attempted to use the stun ability but not particle system was found."));
	}
}

void AMazeCharacter::PlayMontage(UAnimMontage* Montage)
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && Montage)
	{
		AnimInstance->Montage_Play(Montage);
	}
}

void AMazeCharacter::SetHUDHealth() const
{
	if (PlayerOverlay && HealthComponent)
	{
		PlayerOverlay->SetHealthBarPercent(HealthComponent->GetHealthPercent());
	}
}

void AMazeCharacter::InitializePlayerOverlay()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		APlayerHUD* PlayerHUD = Cast<APlayerHUD>(PlayerController->GetHUD());
		if (PlayerHUD)
		{
			PlayerOverlay = PlayerHUD->GetPlayerOverlay();
			if (PlayerOverlay && HealthComponent)
			{
				PlayerOverlay->SetHealthBarPercent(HealthComponent->GetHealthPercent());
				/* Can initialize various other attributes or in game counters here */
			}
		}
	}
}

void AMazeCharacter::Die()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	GetMesh()->PlayAnimation(DeathAnimation, false);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	/* Keeps the player from moving in the DeathPose */
	DisableInput(PlayerController);
}

void AMazeCharacter::Dodge()
{
	PlayMontage(DodgeMontage);
}

/* Apply the incoming damage to the player and check if the player was killed */
float AMazeCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	if (HealthComponent->IsAlive())
	{
		HandleDamage(DamageAmount);
		SetHUDHealth();
		if (HealthComponent->GetHealthPercent() <= 0)
			Die();
		return DamageAmount;
	}
	else
		return 0;
}
