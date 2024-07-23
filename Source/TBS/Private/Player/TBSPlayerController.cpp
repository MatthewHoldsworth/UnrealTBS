// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TBSPlayerController.h"

#include "Character/TBSCharacter.h"
#include "Interfaces/EntityInterface.h"

ATBSPlayerController::ATBSPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bLockLocation = false;
	
}

AActor* ATBSPlayerController::GetEntityUnderCursor()
{
	FHitResult HitResult;
	
	if(GetHitResultUnderCursor(ECC_WorldDynamic,false,HitResult))
	{
		if(HitResult.GetActor()->Implements<UEntityInterface>())
		{
			OnEntitySelected.Broadcast(Cast<ATBSCharacter>(HitResult.GetActor()));
			return HitResult.GetActor();
		}
	}

	
	return nullptr;
}
