// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"

class UProgressBar;
/**
 * 
 */
UCLASS()
class GPE230_BONOFIGLIO_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()

public:
	// Must match the name in the widget in order to bind

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> HealthBar;
	
};
