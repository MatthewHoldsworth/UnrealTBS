// Fill out your copyright notice in the Description page of Project Settings.


#include "TBSBlueprintFunctionLibrary.h"

#include "Attribute/TBSAbilitySystemComponent.h"
#include "Attribute/TBSAttributeSet.h"
#include "Character/TBSCharacter.h"
#include "Game/TBSGameModeBase.h"
#include "Game/TBSGameStateBase.h"
#include "GameFramework/GameModeBase.h"
#include "Grid/Tile/TileActor.h"
#include "Kismet/GameplayStatics.h"
#include "UI/TBSUserWidget.h"

UTBSWidgetController* UTBSBlueprintFunctionLibrary::GetWidgetController(UUserWidget* ControlledWidget)
{
	return CastChecked<UTBSUserWidget>(ControlledWidget)->WidgetController;
}

const UTBSAttributeSet* UTBSBlueprintFunctionLibrary::GetTBSAttributeSet(UAbilitySystemComponent* AbilitySystemComponent)
{
	// UTBSAbilitySystemComponent* test1 =  Cast<UTBSAbilitySystemComponent>(AbilitySystemComponent);
	// const UTBSAttributeSet* test2 = Cast<UTBSAttributeSet>(test1->GetAttributeSet(UTBSAttributeSet::StaticClass()));
	return Cast<UTBSAttributeSet>(
		Cast<UTBSAbilitySystemComponent>(AbilitySystemComponent)->
		GetAttributeSet(UTBSAttributeSet::StaticClass())
		);
}

UTBSAbilitySystemComponent* UTBSBlueprintFunctionLibrary::GetTBSAbilitySystemComponent(ACharacter* Character)
{
	return Cast<UTBSAbilitySystemComponent>(
		Cast<ATBSCharacter>(Character)->GetAbilitySystemComponent()
		);
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
