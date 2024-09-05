// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TBSPlayerController.h"

#include "Character/TBSCharacter.h"
#include "AbilitySystemComponent.h"
#include "Attribute/TBSAbilitySystemComponent.h"
#include "Grid/Tile/TileActor.h"
#include "Interfaces/EntityInterface.h"

ATBSPlayerController::ATBSPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bLockLocation = false;
	
}

TScriptInterface<IEntityInterface> ATBSPlayerController::GetEntityUnderCursor(bool SelectEntity) const
{
	if(FHitResult HitResult; GetHitResultUnderCursor(ECC_WorldDynamic,false,HitResult))
	{
		if(HitResult.GetActor()->Implements<UEntityInterface>())
		{
			if(SelectEntity)
				OnEntitySelected.Broadcast(HitResult.GetActor());
			return HitResult.GetActor();
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

ATileActor* ATBSPlayerController::GetTileUnderCursor()
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
