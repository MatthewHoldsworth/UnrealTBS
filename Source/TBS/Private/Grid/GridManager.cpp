// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/GridManager.h"
#include "IntVectorTypes.h"
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
	UE_LOG(LogTemp, Warning, TEXT("Get Tiles in Range iterations STARTED"));
	int Iteration = Range;
	TArray<ATileActor*> Total =Origin->Neighbours;
	Total.Add(Origin);
	TArray<ATileActor*> Completed;// = TArray<ATileActor*>();
	ATileActor* Head;

	while (Range > 0)
	{
		while (Total.Num() > 0)
		{
			Head = Total[0];
			//Head->Highlight();
			if (!Completed.Contains(Head))
			{
				//Head->Distance = 1000.0f;//float.MaxValue;
				Completed.Add(Head);
			}
			Total.RemoveAt(0);
		}
		for (const auto& It : Completed)
		{
			for (auto& Jt : It->Neighbours)
			{
				if (!Total.Contains(Jt) && !Completed.Contains(Jt))
				{
					//jt->Highlight();
					Total.Add(Jt);
				}
			}
		}
		Range--;
	}
	UE_LOG(LogTemp, Warning, TEXT("Get Tiles in Range iterations: %d"), Iteration);
	//CalculateDistances(Origin, Completed);
	UE_LOG(LogTemp, Warning, TEXT("Get Tiles in Range iterations ENDED"));
	return Completed;
	//return TArray<ATileActor*>();
}

void AGridManager::SetHighlightTiles(const TArray<ATileActor*> Tiles)
{
	for (const auto& It: HighlightedTiles)
		It->UnHighlight();
	HighlightedTiles = Tiles;
	for (const auto& It: HighlightedTiles)
		It->Highlight();
}

void AGridManager::AddHighlightTiles(const TArray<ATileActor*> Tiles)
{
	for (const auto& It: Tiles)
	{
		It->Highlight();
		HighlightedTiles.AddUnique(It);
	}
}

void AGridManager::AddTileToPath(ATileActor* Tile)
{
	if(Tile)
		TilePath.AddUnique(Tile);
}

void AGridManager::TileHovered(ATileActor* Tile)
{
	OnTileHovered.Broadcast(Tile);
}

void AGridManager::CalculateDistances(ATileActor* Origin, TArray<ATileActor*> Tiles)
{
	TArray<ATileActor*> ToDo = TArray<ATileActor*>(Tiles);
	for (auto& it : ToDo)
	{
		it->Distance = 1000.f;
	}
	Origin->Distance = 0;

	while (ToDo.Num() > 0)
	{
		for (auto& it : ToDo[0]->Neighbours)
		{
			if (it->Distance + 1 < ToDo[0]->Distance && it->Distance != -1.0f)
				ToDo[0]->Distance = it->Distance + 1.0f;
		}
		ToDo.RemoveAt(0);
	}
}

TArray<ATileActor*> AGridManager::CalculatePath(ATileActor* Start, ATileActor* Goal)
{
	TArray<ATileActor*> path;
	if (Goal->Neighbours.Num() == 0)
		return TArray<ATileActor*>();
	path.Add(Goal);
	float ShortestDist = 1000.0f; //I don't see this coming to back to bite me
	ATileActor* ClosestTile = path[path.Num() - 1]->Neighbours[0];
	//foreach (TileD n in path[path.Count - 1].Neighbours)
	//{
	//    if (n.distance == -1f)
	//    {

	//    }
	//    else if (n.distance < shortestDist && !path.Contains(n))
	//    {
	//        shortestDist = n.distance;
	//        closestTile = n;
	//    }
	//}
	int count =1;
	//Debug.Log("Dijkstra iteration: " + count);
	while (!path[path.Num()-1]->Neighbours.Contains(Start))
	{
		for (auto i : path[path.Num() - 1]->Neighbours)
		{
			if (i->Distance == -1.0f)
			{

			}
			else if (i->Distance < ShortestDist && !path.Contains(i))
			{
				ShortestDist = i->Distance;
				ClosestTile = i;
			}
		}
		path.Add(ClosestTile);
		count++;
		//Debug.Log("Dijkstra iteration: " + count);
	}
	Algo::Reverse(path);
	//path.Reverse();
	return path;
}


void AGridManager::GenerateTileMapNeighbours()
{
	for (const auto Element : TileMap)
	{
		Element.Value->GenerateNeighbours();
	}
}
