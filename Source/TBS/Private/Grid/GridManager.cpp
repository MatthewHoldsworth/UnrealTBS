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
			FName SpawnName = FName(("Tile_" + std::to_string(j) + '_' + std::to_string(i)).c_str());
			SpawnParameters.Name = SpawnName;
			FVector SpawnVector = FVector((i - CentreOffsetX) * 100.0f, (j - CentreOffsetY) * 100.0f, 0.0f);
			TileMap.Add( FIntVector(i- CentreOffsetX, j- CentreOffsetY, 0),GetWorld()->SpawnActor<ATileActor>(TileClass, SpawnVector,FRotator(), SpawnParameters));
			TileMap.Find(FIntVector(i- CentreOffsetX, j- CentreOffsetY, 0))->Get()->SetActorLabel(SpawnName.ToString());
		}
	}

	GenerateTileMapNeighbours();
}

ATileActor* AGridManager::TileAt(int X, int Y)
{
	return *TileMap.Find(FIntVector(X, Y,0));
}

TArray<ATileActor*> AGridManager::GetTilesInRange(ATileActor* Origin, int Range)
{
	
	return TArray<ATileActor*>();
}

void AGridManager::GenerateTileMapNeighbours()
{
	for (const auto Element : TileMap)
	{
		Element.Value->GenerateNeighbours();
	}
}
