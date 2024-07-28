// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TBSGameModeBase.generated.h"

class AGridManager;
/**
 * 
 */
UCLASS()
class TBS_API ATBSGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	
	
protected:

	UFUNCTION(BlueprintCallable)
	void InitialiseGame();
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AGridManager> GridManager;
private:
};
