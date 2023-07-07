// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/MazeEnemy.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"

AMazeEnemy::AMazeEnemy()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMazeEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void AMazeEnemy::DetectHit()
{
	// Get location of the fist
	const FVector PunchLocation = GetMesh()->GetSocketLocation(PunchingHandSocketName);

	// Do not detect this actor or its controller in the sphere trace
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	ActorsToIgnore.Add(GetOwner());

	// Array for actors hit by the sphere trace
	TArray<FHitResult> HitArray;

	// Sphere trace around fist for overlapped actors - true if there are any hits, false if there are no hits
	const bool Hit = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), PunchLocation, PunchLocation, TraceRadius, UEngineTypes::ConvertToTraceType(ECC_Camera), false,
		 ActorsToIgnore, EDrawDebugTrace::ForDuration, HitArray, true, FLinearColor::Red, FLinearColor::Green, 2.f);

	// Name of this actor
	FString OwnerName = this->GetName();

	
	// If there is a valid hit
	if (Hit)
	{
		bool CanDamage = true;
		for (const FHitResult HitResult : HitArray)
			if (CanDamage)
			{
				FString HitActorName = HitResult.GetActor()->GetName();

				UE_LOG(LogTemp, Log, TEXT("NPCEnemy actor \"%s\" hit other actor \"%s\", dealing %f damage."), *OwnerName, *HitActorName, HitDamage);

				// Apply damage to the hit actor
				UGameplayStatics::ApplyDamage(HitResult.GetActor(), HitDamage, GetController(), this, UDamageType::StaticClass());

				CanDamage = false;
			}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("NPCEnemy actor \"%s\" did not detect any hit"))
	}
}
