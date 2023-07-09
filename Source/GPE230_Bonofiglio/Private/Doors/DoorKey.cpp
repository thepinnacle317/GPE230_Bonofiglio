// Fill out your copyright notice in the Description page of Project Settings.


#include "Doors/DoorKey.h"
#include "Components/BoxComponent.h"

ADoorKey::ADoorKey()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>("Scene Root");
	RootComponent = SceneRoot;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxComponent->SetupAttachment(GetRootComponent());
	
	KeyMesh = CreateDefaultSubobject<UStaticMeshComponent>("Key Static Mesh");
	KeyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	KeyMesh->SetCollisionResponseToChannels(ECR_Ignore);
	KeyMesh->SetupAttachment(BoxComponent);
}

void ADoorKey::BeginPlay()
{
	Super::BeginPlay();
}
