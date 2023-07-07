// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HealthBarComponent.h"

#include "Components/ProgressBar.h"
#include "UI/HealthBar.h"

void UHealthBarComponent::SetHealthPercent(float Percent)
{
	if (HealthBarWidget == nullptr)
	{
		HealthBarWidget = Cast<UHealthBar>(GetUserWidgetObject());
	}

	if (HealthBarWidget && HealthBarWidget->HealthBar)
	{
		HealthBarWidget->HealthBar->SetPercent(Percent);
	}
}
