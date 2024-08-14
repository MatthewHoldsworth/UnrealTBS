// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TBSWidgetController.generated.h"

class UTBSUserWidget;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class TBS_API UTBSWidgetController : public UObject
{
	GENERATED_BODY()
public:

protected:

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UTBSUserWidget> ControlledWidget;
};
