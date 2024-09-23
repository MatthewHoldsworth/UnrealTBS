// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "TBSGameplayAbility.generated.h"

class UTBSAbilitySystemComponent;

UENUM(BlueprintType)
enum ETargetTypes
{
	Any,
	Entity,
	Tile,
	Self,
	Last
};
/**
 * 
 */
UCLASS(BlueprintType)
class TBS_API UTBSGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName AbilityName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 Range;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 Radius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bHasPath;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TEnumAsByte<ETargetTypes> ValidTargets;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void InitAbilityInfo(UTBSAbilitySystemComponent* AbilitySystemComponent) const;
	
// protected:
// 	void InitAbilityInfo_Implementation();
};
