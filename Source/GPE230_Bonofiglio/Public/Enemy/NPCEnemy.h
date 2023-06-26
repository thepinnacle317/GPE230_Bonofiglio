// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCEnemy.generated.h"

UCLASS()
class GPE230_BONOFIGLIO_API ANPCEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;
	// Sets default values for this character's properties
	ANPCEnemy();
protected:
	// Called when the game starts or when spawned
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
