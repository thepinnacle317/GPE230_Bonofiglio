// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GPE230_BONOFIGLIO_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UHealthComponent();

	void RecieveDamage(float Damage);
	bool IsAlive();
	float GetHealthPercent();

protected:

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Attributes")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, Category="Attributes")
	float MaxHealth;
	
};
