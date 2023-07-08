// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MazeGameInstance.generated.h"


UENUM(BlueprintType)
enum EKeyTypes
{
	None UMETA(DisplayName = "No Key"),
	Cell_Block_D UMETA(DisplayName = "Cell Block D Key"),
	Cell_Block_C UMETA(DisplayName = "Cell Block C Key"),
	Utility_Room UMETA(DisplayName = "Utility Room Key"),
	Yard UMETA(DisplayName = "Yard Key"),
	Isolation UMETA(DisplayName = "Isolation Key"),
	Intake UMETA(DisplayName = "Intake Key")
};

/**
 * 
 */
UCLASS()
class GPE230_BONOFIGLIO_API UMazeGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	
};
