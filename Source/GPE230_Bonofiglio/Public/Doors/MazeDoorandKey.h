// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MazeDoorandKey.generated.h"

class UStaticMeshComponent;

UCLASS()
class GPE230_BONOFIGLIO_API AMazeDoorandKey : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMazeDoorandKey();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Door")
	TObjectPtr<UStaticMeshComponent> DoorMesh;

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Door")
	TObjectPtr<USceneComponent> SceneRoot;
	
};
