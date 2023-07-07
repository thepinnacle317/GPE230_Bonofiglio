// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "MazeEnemy.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_BONOFIGLIO_API AMazeEnemy : public ACharacterBase
{
	GENERATED_BODY()

public:
	AMazeEnemy();
	
protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category="Collision")
	void DetectHit();
	
private:

	UPROPERTY(EditAnywhere)
	float TraceRadius = 500.f;
	UPROPERTY(EditAnywhere)
	FName PunchingHandSocketName;
	UPROPERTY(EditAnywhere)
	float HitDamage;
};
