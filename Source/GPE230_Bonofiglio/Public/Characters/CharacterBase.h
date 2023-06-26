// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "GameFramework/SpringArmComponent.h"
#include "CharacterBase.generated.h"


// Forward Declarations
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class GPE230_BONOFIGLIO_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	ACharacterBase();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Jump() override;

	/* Player Attributes */
	UPROPERTY(EditAnywhere, Category="Player Attributes")
	float maxHealth;

protected:
	
	virtual void BeginPlay() override;

	/* Player Attributes */
	float currentHealth;

	/* Callback for Player Inputs */
	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* PlayerContext;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MovementAction;
	
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* JumpAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	virtual void Die();
	

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(EditAnywhere)
	UAnimSequence* deathAnimation;
	
	bool isDead = false;
	
};
