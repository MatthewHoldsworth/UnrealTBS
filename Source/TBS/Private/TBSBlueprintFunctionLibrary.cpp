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
