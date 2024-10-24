// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TBSPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Character/TBSCharacter.h"
#include "AbilitySystemComponent.h"
#include "Abilities/TBSGameplayAbility.h"
#include "Attribute/TBSAbilitySystemComponent.h"
#include "Game/TBSGameModeBase.h"
#include "Game/TBSGameStateBase.h"
#include "Grid/GridManager.h"
#include "Grid/Tile/TileActor.h"
#include "Interfaces/EntityInterface.h"

ATBSPlayerController::ATBSPlayerController(): bIsAbilitySelected(false), AbilityRadius(0)
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bLockLocation = false;

	//Cast<ATBSGameStateBase>(GetWorld()->GetGameState())->CombatStateChanged;
}

void ATBSPlayerController::RegenerateTilesInRange()
{
	if(!PlayerSelectedAbility.IsValid())
		return;
	bool t = true;
	const ATBSCharacter* TBSCharacter = Cast<ATBSCharacter>(SelectedEntity.GetObject());
	AGridManager* GridManager = Cast<ATBSGameModeBase>(GetWorld()->GetAuthGameMode())->GridManager;
	const UTBSGameplayAbility* TBSAbility = Cast<UTBSGameplayAbility>(UAbilitySystemBlueprintLibrary::GetGameplayAbilityFromSpecHandle(TBSCharacter->GetAbilitySystemComponent(), PlayerSelectedAbility, t));

	GridManager->RemoveHighlightTiles(TilesInRange);
	GridManager->RemoveHighlightTiles(TilesInAbilityRadius);

	TilesInAbilityRadius.Empty();
	
	AbilityRadius = TBSAbility->Radius;
	AbilityHasPath = TBSAbility->bHasPath;
	SelectedAbilityTargetParams = TBSAbility->TargetParameters;
	
	TilesInRange = GridManager->GetTilesInRange(SelectedEntity->EntityLocation, TBSAbility->Range);
	GridManager->CalculateDistances(SelectedEntity->EntityLocation, TilesInRange);
	GridManager->AddHighlightTiles(TilesInRange);
}

void ATBSPlayerController::SelectedAbility(FGameplayAbilitySpecHandle AbilitySelected)
{
	PlayerSelectedAbility = AbilitySelected;
	bIsAbilitySelected = true;
	
	RegenerateTilesInRange();
	//GridManager->SetHighlightTiles(TilesInRange);
}

void ATBSPlayerController::ClearAbility()
{
	AbilityRadius = 0;
	AbilityHasPath = false;
	SelectedAbilityTargetParams = FTargetParams();

	AGridManager* GridManager = Cast<ATBSGameModeBase>(GetWorld()->GetAuthGameMode())->GridManager;
	GridManager->RemoveHighlightTiles(TilesInRange);
	GridManager->RemoveHighlightTiles(TilesInAbilityRadius);

	TilesInRange.Empty();
	TilesInAbilityRadius.Empty();
	//AbilityPath.Empty();
}

TScriptInterface<IEntityInterface> ATBSPlayerController::GetEntityUnderCursor(bool bSelectEntity) const
{
	if(FHitResult HitResult; GetHitResultUnderCursor(ECC_WorldDynamic,false,HitResult))
	{
		if(HitResult.GetActor()->Implements<UEntityInterface>())
		{
			if(bSelectEntity)
				OnEntitySelected.Broadcast(HitResult.GetActor());
			return HitResult.GetActor();
		}
	}
	if(bSelectEntity)
		OnEntitySelected.Broadcast(nullptr);
	return nullptr;
}

ATileActor* ATBSPlayerController::GetTileUnderCursor() const
{
	FHitResult HitResult;
	
	if(GetHitResultUnderCursor(ECC_WorldDynamic,false,HitResult))
	{
		if(ATileActor* HitTile = Cast<ATileActor>(HitResult.GetActor()))
		{
			OnTileSelected.Broadcast(HitTile);
			return HitTile;
		}
	}
	return nullptr;
}


bool ATBSPlayerController::ExecuteSelectedAbility(UTBSAbilitySystemComponent* Source)
{
	GetEntityUnderCursor(false).GetObject();
	Source->TryActivateAbility(PlayerSelectedAbility);
	GetPawn();
	return true;
}