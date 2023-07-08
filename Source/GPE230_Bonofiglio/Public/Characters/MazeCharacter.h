// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "InputActionValue.h"
#include "Pickups/PickupInterface.h"
#include "MazeCharacter.generated.h"

class UPlayerOverlay;
class UHealthComponent;
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
class UNiagaraFunctionLibrary;
class UNiagaraComponent;
class UNiagaraSystem;

/**
 * 
 */
UCLASS()
class GPE230_BONOFIGLIO_API AMazeCharacter : public ACharacterBase, public IPickupInterface
{
	GENERATED_BODY()

public:

	AMazeCharacter();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Jump() override;

protected:

	virtual void BeginPlay() override;
	/* Callback for Player Inputs */
	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* PlayerContext;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MovementAction;
	
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category= Input)
	UInputAction* StunAction;

	UPROPERTY(EditAnywhere, Category= Input)
	UInputAction* DodgeAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	virtual void Die();
	
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> ViewCamera;

	UPROPERTY(EditAnywhere, Category = "Player Animations")
	TObjectPtr<UAnimSequence> DeathAnimation;

	UPROPERTY(EditDefaultsOnly, Category = "Player Animations")
	UAnimMontage* DodgeMontage;

	UPROPERTY(EditAnywhere, Category = "Player Effects")
	TObjectPtr<UNiagaraSystem> StunSystem;

	UFUNCTION(BlueprintCallable)
	void ActivateStunParticleSystem();

	UFUNCTION(BlueprintCallable)
	void Dodge();

	void PlayMontage(UAnimMontage* Montage);

	UPROPERTY(VisibleAnywhere, Category = "Overlay")
	TObjectPtr<UPlayerOverlay> PlayerOverlay;
	
	void SetHUDHealth() const;
	void InitializePlayerOverlay();
	
};
