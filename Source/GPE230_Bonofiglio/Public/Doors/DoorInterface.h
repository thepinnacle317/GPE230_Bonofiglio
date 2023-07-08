// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DoorInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDoorInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GPE230_BONOFIGLIO_API IDoorInterface
{
	GENERATED_BODY()

public:

	virtual void SetOverlappingItem(class ADoorKey* DoorKey);
};
