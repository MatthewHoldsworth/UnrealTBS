// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/TBSWidgetController.h"
#include "HealthBarWidgetController.generated.h"

class UTBSAttributeSet;
struct FGameplayAttribute;
struct FGameplayTag;
class ATBSCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthChangedSignature, const FTBSAttributeInfo&, AttributeInfo);

/**
 * 
 */
UCLASS()
class TBS_API UHealthBarWidgetController : public UTBSWidgetController
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite)
	ATBSCharacter* OwningCharacter;
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FHealthChangedSignature HealthInfoDelegate;
	
	UFUNCTION(BlueprintCallable)
	void InitialiseCallbacks(UTBSAbilitySystemComponent* AbilitySystemComponent);
	
	UFUNCTION(BlueprintCallable)
	void ClearCallbacks(UTBSAbilitySystemComponent* AbilitySystemComponent);
	
	UFUNCTION(BlueprintCallable)
	void InitialBroadcast(UTBSAbilitySystemComponent* AbilitySystemComponent);
	
	void BroadcastHealth(const FGameplayTag& Tag, const FGameplayAttribute& Attribute, const UTBSAttributeSet* AttributeSet) const;
};
