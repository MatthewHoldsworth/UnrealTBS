// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/Tile/TileActor.h"

#include "Character/TBSCharacter.h"

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
