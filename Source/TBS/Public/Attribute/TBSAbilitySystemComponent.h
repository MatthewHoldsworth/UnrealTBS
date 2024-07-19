// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "TBSAbilitySystemComponent.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAttributeChanged,FString, Attribute, float, NewValue, float, OldValue);

UCLASS()
class TBS_API UTBSAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UTBSAbilitySystemComponent();
	
	UPROPERTY(BlueprintAssignable, Category="Attributes")
	FAttributeChanged AttributeChanged;

	UFUNCTION(BlueprintCallable, Category="Attributes")
	void InitialiseCallbacks();
};
