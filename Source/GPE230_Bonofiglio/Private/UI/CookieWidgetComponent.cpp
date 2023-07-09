// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CookieWidgetComponent.h"
#include "Kismet/KismetTextLibrary.h"
#include "Components/TextBlock.h"
#include "UI/CookieWidget.h"

void UCookieWidgetComponent::SetCookieCollectables(int32 NewValue)
{
	if (CookieWidget == nullptr)
	{
		CookieWidget = Cast<UCookieWidget>(GetUserWidgetObject());
	}

	if (CookieWidget && CookieWidget->CookieText)
	{
		CookieWidget->CookieText->SetText(UKismetTextLibrary::Conv_IntToText(NewValue));
	}
}
