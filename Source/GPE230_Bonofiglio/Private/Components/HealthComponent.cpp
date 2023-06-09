// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHealthComponent::ReceiveDamage(float Damage)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.f, MaxHealth);
}

void UHealthComponent::AddHealth(float Health)
{
	CurrentHealth += Health;
}

bool UHealthComponent::IsAlive()
{
	return CurrentHealth > 0.f;
}

float UHealthComponent::GetHealthPercent()
{
	return CurrentHealth / MaxHealth; 
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}
