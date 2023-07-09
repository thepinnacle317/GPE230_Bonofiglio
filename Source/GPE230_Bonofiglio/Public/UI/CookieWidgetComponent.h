// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "CookieWidgetComponent.generated.h"

class UCookieWidget;
/**
 * 
 */
UCLASS()
class GPE230_BONOFIGLIO_API UCookieWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	void SetCookieCollectables(int32 NewValue);
	
private:
	UPROPERTY()
	TObjectPtr<UCookieWidget> CookieWidget;
	
};
