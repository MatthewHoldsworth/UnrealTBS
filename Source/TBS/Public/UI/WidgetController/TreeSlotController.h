// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/TBSWidgetController.h"
#include "TreeSlotController.generated.h"

/**
 * 
 */
UCLASS()
class TBS_API UTreeSlotController : public UTBSWidgetController
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	bool HasUnlocked;
	
	UPROPERTY(BlueprintReadWrite)
	bool CanUnlock;
};
