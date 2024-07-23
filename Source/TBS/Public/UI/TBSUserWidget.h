// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TBSUserWidget.generated.h"

class UTBSWidgetController;
/**
 * 
 */
UCLASS()
class TBS_API UTBSUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UTBSWidgetController> Controller;
protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UTBSWidgetController> ControllerClass;
	
};
