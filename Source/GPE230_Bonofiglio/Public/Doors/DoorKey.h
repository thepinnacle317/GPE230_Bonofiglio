// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorInterface.h"
#include "GameFramework/Actor.h"
#include "DoorKey.generated.h"


class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class GPE230_BONOFIGLIO_API ADoorKey : public AActor, public IDoorInterface
{
	GENERATED_BODY()
	
public:	
	ADoorKey();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Key")
	TObjectPtr<UBoxComponent> BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Key")
	TObjectPtr<UStaticMeshComponent> KeyMesh;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Key")
	TObjectPtr<USceneComponent> SceneRoot;
};
