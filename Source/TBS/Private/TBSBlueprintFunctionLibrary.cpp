// Fill out your copyright notice in the Description page of Project Settings.


#include "TBSBlueprintFunctionLibrary.h"

#include "Game/TBSGameModeBase.h"
#include "Game/TBSGameStateBase.h"
#include "GameFramework/GameModeBase.h"
#include "Grid/Tile/TileActor.h"
#include "Kismet/GameplayStatics.h"
#include "UI/TBSUserWidget.h"

UTBSWidgetController* UTBSBlueprintFunctionLibrary::GetWidgetController(UUserWidget* ControlledWidget)
{
	return CastChecked<UTBSUserWidget>(ControlledWidget)->Controller;
}

ATileActor* UTBSBlueprintFunctionLibrary::GetTileAt(FIntVector Vector)
{
	return nullptr;
}

AGridManager* UTBSBlueprintFunctionLibrary::GetGridManager(UObject* WorldObject)
{
	return Cast<ATBSGameModeBase>(UGameplayStatics::GetGameMode(WorldObject))->GridManager;
}

FIntVector UTBSBlueprintFunctionLibrary::WorldToGridCoordinates(FVector Location)
{
	//roundf()
	return FIntVector(roundf(Location.X*0.01f),roundf(Location.Y*0.01f),0.0f);
}

FVector UTBSBlueprintFunctionLibrary::GridToWorldCoordinates(FIntVector Position)
{
	return FVector(Position.X * 100.0f, Position.Y * 100.0f, Position.Z * 100.0f);
}
