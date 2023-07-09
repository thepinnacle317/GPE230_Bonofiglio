// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/HealthPickup.h"
#include "Characters/MazeCharacter.h"
#include "Components/HealthComponent.h"
#include "Pickups/PickupInterface.h"

AHealthPickup::AHealthPickup()
{
}

void AHealthPickup::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	if (PickupInterface)
	{
		AMazeCharacter* MazeCharacter = Cast<AMazeCharacter>(OtherActor);
		PickupInterface->SetOverlappingItem(this);
		SpawnPickupSound();
		UHealthComponent* HealthComponent = MazeCharacter->AddHealth();
		if (HealthComponent && MazeCharacter)
		{
			HealthComponent->AddHealth(Health);
			MazeCharacter->SetHUDHealth();			
		}
		Destroy();
	}
}
