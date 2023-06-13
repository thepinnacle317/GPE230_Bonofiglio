// Fill out your copyright notice in the Description page of Project Settings.


#include "LockAndKey.h"
#include "Characters/CharacterBase.h"

ALockAndKey::ALockAndKey()
{
	OnActorBeginOverlap.AddDynamic(this, &ALockAndKey::CheckActorType);
}

void ALockAndKey::CheckActorType(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(ACharacterBase::StaticClass()))
	{
		OpenTheDoor();
	}
}

void ALockAndKey::OpenTheDoor()
{
	this->Destroy();
}
