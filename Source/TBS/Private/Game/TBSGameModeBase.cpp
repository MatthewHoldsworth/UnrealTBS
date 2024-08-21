// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/TBSGameModeBase.h"

#include "Grid/GridManager.h"
#include "Grid/Tile/TileActor.h"
#include "Kismet/GameplayStatics.h"

ATBSGameModeBase::ATBSGameModeBase()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGridManager::StaticClass(), FoundActors);
	GridManager = Cast<AGridManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AGridManager::StaticClass()));
}

void ATBSGameModeBase::InitialiseGame()
{
	GridManager = GetWorld()->SpawnActor<AGridManager>();
	GridManager->GridX = 10;
	GridManager->GridY = 10;
	GridManager->InitGrid();
}
