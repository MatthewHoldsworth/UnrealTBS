// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TBSGameStateBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCombatStateChanged, const bool, InCombat);

/**
 * 
 */
UCLASS()
class TBS_API ATBSGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void EnterCombat();
	
	UFUNCTION(BlueprintCallable)
	void ExitCombat();

	UFUNCTION(BlueprintCallable)
	bool IsInCombat() const {return bInCombat;}
	
	UPROPERTY(BlueprintAssignable)
	FCombatStateChanged CombatStateChanged;
protected:
	
	UPROPERTY(BlueprintReadWrite)
	bool bPlayerTurn = true;
	
	UPROPERTY(BlueprintReadWrite)
	bool bInCombat = false;
};
