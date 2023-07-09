// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerOverlay.h"
#include "Kismet/KismetTextLibrary.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UPlayerOverlay::SetHealthBarPercent(float Percent)
{
	if (HealthProgressBar)
	{
		HealthProgressBar->SetPercent(Percent);
	}
}

void UPlayerOverlay::SetCookieCollectables(int32 NewValue)
{
	if (CookieText)
	{
		CookieText->SetText(UKismetTextLibrary::Conv_IntToText(NewValue));
	}
}
