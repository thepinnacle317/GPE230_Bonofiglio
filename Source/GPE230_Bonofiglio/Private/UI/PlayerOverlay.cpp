// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerOverlay.h"

#include "Components/ProgressBar.h"

void UPlayerOverlay::SetHealthBarPercent(float Percent)
{
	if (HealthProgressBar)
	{
		HealthProgressBar->SetPercent(Percent);
	}
}
