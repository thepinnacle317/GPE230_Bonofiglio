// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "Characters/CharacterBase.h"
#include "GameFramework/GameModeBase.h"
#include "MazeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_BONOFIGLIO_API AMazeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void InitGameState() override;

private:
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<ACharacterBase> DefaultPlayerCharacter = ACharacterBase::StaticClass();
	
};
