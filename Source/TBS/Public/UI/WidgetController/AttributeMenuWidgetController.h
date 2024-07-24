// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/TBSWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

class UTBSAbilitySystemComponent;
struct FTBSAttributeInfo;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeChangedSignature, const FTBSAttributeInfo&, AttributeInfo);

/**
 * 
 */
UCLASS()
class TBS_API UAttributeMenuWidgetController : public UTBSWidgetController
{
	GENERATED_BODY()
public:

	UAttributeMenuWidgetController();
	
	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FAttributeChangedSignature AttributeInfoDelegate;
	
	UFUNCTION(BlueprintCallable)
	void InitialiseCallbacks(UTBSAbilitySystemComponent* AbilitySystemComponent);
};
