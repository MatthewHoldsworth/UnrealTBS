// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TBSGameModeBase.generated.h"

class ATileActor;
class AGridManager;
/**
 * 
 */
UCLASS()
class TBS_API ATBSGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ATBSGameModeBase();
	
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AGridManager> GridManager;

	UFUNCTION(BlueprintCallable)
	void SetHighlightTiles(TArray<ATileActor*> Tiles);
protected:

	UFUNCTION(BlueprintCallable)
	void InitialiseGame();

	UPROPERTY(BlueprintReadWrite)
	TArray<ATileActor*> HighlightedTiles;
private:
};
