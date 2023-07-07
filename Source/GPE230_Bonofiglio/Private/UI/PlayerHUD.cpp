// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/PlayerOverlay.h"

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();
	UWorld* World = GetWorld();

	if (World)
	{
		// Get the player controller of the first spawned player.  Single player only.
		APlayerController* PlayerController = World->GetFirstPlayerController();
		
		if (PlayerController && PlayerOverlayClass)
		{
			/* Create the widget from the PlayerOverlayClass set in BP and assign it to the first player controller.
			Then add it to the players viewport. */
			PlayerOverlay = CreateWidget<UPlayerOverlay>(PlayerController, PlayerOverlayClass);
			PlayerOverlay->AddToViewport();
		}
	}
}
