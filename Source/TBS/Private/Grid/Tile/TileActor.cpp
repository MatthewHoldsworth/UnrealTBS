// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/Tile/TileActor.h"

#include "Character/TBSCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

ATileActor::ATileActor()
{
	CubeComponent = CreateDefaultSubobject<UStaticMeshComponent>("Cube");
	SetRootComponent(CubeComponent);
}

bool ATileActor::SetOccupant(ATBSCharacter* NewOccupant)
{
	if(!Occupant)
	{
		Occupant = NewOccupant;
		//NewOccupant->SetActorLocation(GetActorLocation() + FVector(0.0f,0.0f,100.0f));
	}
	return false;
}

void ATileActor::GenerateNeighbours()
{
	TArray<AActor*> OverlappedActors;
	UKismetSystemLibrary::SphereOverlapActors(this, GetActorLocation(),51.0f, TArray<TEnumAsByte<EObjectTypeQuery>>(), ATileActor::StaticClass(),{this},OverlappedActors);
	for (auto OverlappedActor : OverlappedActors)
	{
		Neighbours.AddUnique(Cast<ATileActor>(OverlappedActor));
	}
}
