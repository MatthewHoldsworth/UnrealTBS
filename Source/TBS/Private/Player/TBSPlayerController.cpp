// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TBSPlayerController.h"

#include "Character/TBSCharacter.h"
#include "AbilitySystemComponent.h"
#include "Attribute/TBSAbilitySystemComponent.h"
#include "Game/TBSGameStateBase.h"
#include "Grid/Tile/TileActor.h"
#include "Interfaces/EntityInterface.h"

ATBSPlayerController::ATBSPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bLockLocation = false;

	//Cast<ATBSGameStateBase>(GetWorld()->GetGameState())->CombatStateChanged;
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