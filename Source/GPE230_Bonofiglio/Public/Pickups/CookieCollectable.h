// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/PickupBase.h"
#include "CookieCollectable.generated.h"

class AMazeCharacter;
/**
 * 
 */
UCLASS()
class GPE230_BONOFIGLIO_API ACookieCollectable : public APickupBase
{
	GENERATED_BODY()

public:

	ACookieCollectable();

	UPROPERTY(EditAnywhere, Category="Pickup Properties")
	float Cookie = 0;
protected:
	
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
};
