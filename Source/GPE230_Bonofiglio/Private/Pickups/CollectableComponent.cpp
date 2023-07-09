// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/CollectableComponent.h"


UCollectableComponent::UCollectableComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UCollectableComponent::AddCollectable(int32 NewValue)
{
	CurrentCookies += NewValue;
}

void UCollectableComponent::BeginPlay()
{
	Super::BeginPlay();
}
