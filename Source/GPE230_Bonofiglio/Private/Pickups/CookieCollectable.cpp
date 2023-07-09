// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/CookieCollectable.h"
#include "Pickups/PickupInterface.h"
#include "Characters/MazeCharacter.h"
#include "Pickups/CollectableComponent.h"

ACookieCollectable::ACookieCollectable()
{
}

void ACookieCollectable::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                         UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	if (PickupInterface)
	{
		AMazeCharacter* MazeCharacter = Cast<AMazeCharacter>(OtherActor);
		PickupInterface->SetOverlappingItem(this);
		SpawnPickupSound();
		
		UCollectableComponent* CollectableComponent = MazeCharacter->AddCookies();
		if (CollectableComponent && MazeCharacter)
		{
			CollectableComponent->AddCollectable(Cookie);
			MazeCharacter->SetHUDCookies();			
		}
		Destroy();
	}	
}

