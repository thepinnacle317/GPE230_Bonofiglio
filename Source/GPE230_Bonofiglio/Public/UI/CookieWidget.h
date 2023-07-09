// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CookieWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class GPE230_BONOFIGLIO_API UCookieWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	// Must match the name in the widget in order to bind
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> CookieText;
};
