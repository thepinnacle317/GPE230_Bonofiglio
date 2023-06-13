// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/MazeGameMode.h"

void AMazeGameMode::InitGameState()
{
	Super::InitGameState();
	// If there is no override for the default pawn
	if (DefaultPawnClass == ADefaultPawn::StaticClass())
	{
		// Sets the default pawn to CharacterBase
		DefaultPawnClass = DefaultPlayerCharacter;
	}
}
