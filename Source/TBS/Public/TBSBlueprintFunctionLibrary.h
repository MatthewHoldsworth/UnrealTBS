// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TBSBlueprintFunctionLibrary.generated.h"

class AGridManager;
class ATileActor;
class UTBSWidgetController;
/**
 * 
 */
UCLASS()
class TBS_API UTBSBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
		GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category="UI")
	static UTBSWidgetController* GetWidgetController(UUserWidget* ControlledWidget);
	
	UFUNCTION(BlueprintCallable, Category="Grid")
	static ATileActor* GetTileAt(FIntVector Vector);

	UFUNCTION(BlueprintCallable, Category="Grid")
	static AGridManager* GetGridManager();
};
