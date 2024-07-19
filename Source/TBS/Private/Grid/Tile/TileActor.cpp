// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/Tile/TileActor.h"

ATileActor::ATileActor()
{
	CubeComponent = CreateDefaultSubobject<UStaticMeshComponent>("Cube");
	SetRootComponent(CubeComponent);
}
