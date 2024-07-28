// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TBSPlayerController.generated.h"

class ATBSCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEntitySelected, ATBSCharacter*, Entity);

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
	
	UPROPERTY(BlueprintAssignable, Category="Attributes")
	FOnEntitySelected OnEntitySelected;
protected:
	UFUNCTION(BlueprintCallable)
	AActor* GetEntityUnderCursor();
};
