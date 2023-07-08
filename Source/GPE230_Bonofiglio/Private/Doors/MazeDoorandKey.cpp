// Fill out your copyright notice in the Description page of Project Settings.


#include "Doors/MazeDoorandKey.h"


AMazeDoorandKey::AMazeDoorandKey()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>("Scene Root");
	RootComponent = SceneRoot;
	
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("Door Mesh");
	DoorMesh->SetupAttachment(GetRootComponent());
}

void AMazeDoorandKey::BeginPlay()
{
	Super::BeginPlay();	
}

