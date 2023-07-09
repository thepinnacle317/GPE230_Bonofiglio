// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CollectableComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GPE230_BONOFIGLIO_API UCollectableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UCollectableComponent();
	
	UPROPERTY(EditAnywhere, Category="Collectables")
	int32 CurrentCookies;
	
	void AddCollectable(int32 NewValue);

protected:
	
	virtual void BeginPlay() override;

	
			
};
