// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupBase.generated.h"

class USphereComponent;
class UNiagaraComponent;

UCLASS()
class GPE230_BONOFIGLIO_API APickupBase : public AActor
{
	GENERATED_BODY()
	
public:	
	
	APickupBase();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	virtual void SpawnPickupSound();
	virtual void SpawnPickupSystem();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USphereComponent* Sphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* ItemMesh;
	
	UPROPERTY(EditAnywhere, Category="Pickup Sound")
	USoundBase* PickupSound;

	UPROPERTY(EditAnywhere, Category="Effects")
	UNiagaraComponent* ItemEffect;

	UPROPERTY(EditAnywhere, Category="Effects")
	FVector Location = GetActorLocation() - FVector(0.f, 0.f, 0.f);

private:

	UPROPERTY(EditAnywhere, Category="Effects")
	class UNiagaraSystem* PickupEffect;
};
