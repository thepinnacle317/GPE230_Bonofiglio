// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

// Forward Declarations
class UHealthComponent;

UCLASS()
class GPE230_BONOFIGLIO_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

protected:
	virtual void BeginPlay() override;
	virtual void HandleDamage(float DamageAmount);

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UHealthComponent> HealthComponent;
};
