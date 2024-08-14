// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpecHandle.h"
#include "UI/WidgetController/TBSWidgetController.h"
#include "AbilityBarWidgetController.generated.h"

class ATBSCharacter;
/**
 * 
 */
UCLASS()
class TBS_API UAbilityBarWidgetController : public UTBSWidgetController
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	FGameplayAbilitySpecHandle SelectedAbility;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ATBSCharacter> SelectedCharacter;
	
	UFUNCTION(BlueprintCallable)
	void SetSelectedAbility(FGameplayAbilitySpecHandle AbilitySpecHandle);
	UFUNCTION(BlueprintCallable)
	void SetSelectedCharacter(ATBSCharacter* Character);
	
	UFUNCTION(BlueprintCallable)
	void ActivateSelectedAbility();
};
