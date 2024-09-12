// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TreeSlotController.h"
#include "UI/WidgetController/TBSWidgetController.h"
#include "LevelTreeWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class TBS_API ULevelTreeWidgetController : public UTBSWidgetController
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite)
	TMap<FIntVector, TObjectPtr<UTBSUserWidget>> TreeSlotsMap;

	UFUNCTION(BlueprintCallable)
	void ShowAllAvailable();
};
