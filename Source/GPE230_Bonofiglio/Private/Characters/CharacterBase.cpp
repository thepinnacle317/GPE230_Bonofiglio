// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CharacterBase.h"
#include "Components/InputComponent.h"
#include "Components/HealthComponent.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterBase::HandleDamage(float DamageAmount)
{
	if (HealthComponent)
	{
		HealthComponent->RecieveDamage(DamageAmount);
	}
}
