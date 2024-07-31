// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/GridManager.h"

#include "Components/SphereComponent.h"
#include "Grid/Tile/TileActor.h"

AGridManager::AGridManager()
{
 	DebugSphere = CreateDefaultSubobject<USphereComponent>("DebugSphere");
	
}

void AGridManager::InitGrid()
{
	const int CentreOffsetX = GridX * 0.5f;
	const int CentreOffsetY = GridY * 0.5f;
	GridOffsetValueX = CentreOffsetX;
	GridOffsetValueY = CentreOffsetY;
	
	FActorSpawnParameters SpawnParameters;
	//SpawnParameters.Owner = this;
	//SpawnParameters.Instigator = GetInstigator();
	for(int i =0; i < GridY; i++)
	{
		for(int j =0; j < GridX; j++)
		{
			SpawnParameters.Name = ("TileActor_" + std::to_string(j - CentreOffsetY) + '_' + std::to_string(i - CentreOffsetX)).c_str();
			FVector SpawnVector = FVector((i - CentreOffsetX) * 100.0f, (j - CentreOffsetY) * 100.0f, 0.0f);
			TileMap.Add( FIntVector(i- CentreOffsetX, j- CentreOffsetY, 0),GetWorld()->SpawnActor<ATileActor>(TileClass, SpawnVector,FRotator(), SpawnParameters));
		}
	}
}

ATileActor* AGridManager::TileAt(int X, int Y)
{
	return *TileMap.Find(FIntVector(X, Y,0));
}


