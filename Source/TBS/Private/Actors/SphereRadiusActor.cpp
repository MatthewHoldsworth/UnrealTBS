// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SphereRadiusActor.h"

// Sets default values
ASphereRadiusActor::ASphereRadiusActor()
{
	SphereComponent = CreateDefaultSubobject<UStaticMeshComponent>("Sphere");
	SetRootComponent(SphereComponent);
	//SetActorHiddenInGame(true);
	SphereComponent->SetVisibility(false);
}

void ASphereRadiusActor::ShowSphereAt(const FVector NewLocation, int32 NewRadius = 1, const FColor Colour)
{
	//SetActorHiddenInGame(false);
	SphereComponent->SetVisibility(true);
	SetActorLocation(NewLocation);
	SetActorScale3D(FVector(NewRadius * 2.0f));
	SphereComponent->SetVectorParameterValueOnMaterials("SphereColour", FVector(Colour));
}

void ASphereRadiusActor::HideSphere()
{
	//SetActorHiddenInGame(true);
	SphereComponent->SetVisibility(false);
}