// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/NPCEnemy.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"

// Sets default values
ANPCEnemy::ANPCEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPCEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void ANPCEnemy::DetectHit()
{
	bool canDamage = true;

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
	FString ownerName = this->GetName();

	// If there is a valid hit
	if (Hit)
	{
		for (const FHitResult HitResult : HitArray)
			if (canDamage)
			{
				FString hitActorName = HitResult.GetActor()->GetName();

				UE_LOG(LogTemp, Log, TEXT("NPCEnemy actor \"%s\" hit other actor \"%s\", dealing %f damage."), *ownerName, *hitActorName, HitDamage);

				// Apply damage to the hit actor
				UGameplayStatics::ApplyDamage(HitResult.GetActor(), HitDamage, GetController(), this, UDamageType::StaticClass());

				canDamage = false;
			}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("NPCEnemy actor \"%s\" did not detect any hit"))
	}
}

// Called every frame
void ANPCEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

