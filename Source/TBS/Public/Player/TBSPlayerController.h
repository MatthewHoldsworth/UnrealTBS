// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TBSPlayerController.generated.h"

class IEntityInterface;
/**
 * 
 */
UCLASS()
class TBS_API ATBSPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATBSPlayerController();

protected:
	UFUNCTION(BlueprintCallable)
	AActor* GetEntityUnderCursor();

	UPROPERTY(BlueprintReadWrite, Category="PlayerState")
	bool bInCombat = false;

};
