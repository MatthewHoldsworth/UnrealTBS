// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TBSBlueprintFunctionLibrary.generated.h"

class UTBSAbilitySystemComponent;
class UTBSAttributeSet;
class UAbilitySystemComponent;
class ATBSGameStateBase;
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
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Ability System")
	static const UTBSAttributeSet* GetTBSAttributeSet(UAbilitySystemComponent* AbilitySystemComponent);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Ability System")
	static UTBSAbilitySystemComponent* GetTBSAbilitySystemComponent(ACharacter* Character);
	
	UFUNCTION(BlueprintCallable, Category="Grid")
	static ATileActor* GetTileAt(FIntVector Vector);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Grid")
	static AGridManager* GetGridManager(UObject* WorldObject);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Grid")
	static FIntVector WorldToGridCoordinates(FVector Location);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Grid")
	static FVector GridToWorldCoordinates(FIntVector Position);
};
