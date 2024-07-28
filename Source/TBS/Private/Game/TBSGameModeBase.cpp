// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/TBSGameModeBase.h"

#include "Grid/GridManager.h"

void ATBSGameModeBase::InitialiseGame()
{
	GridManager = GetWorld()->SpawnActor<AGridManager>();
	GridManager->GridX = 10;
	GridManager->GridY = 10;
	GridManager->InitGrid();
}
