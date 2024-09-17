// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "TBSGameplayAbility.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class TBS_API UTBSGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName AbilityName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 Range;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 Radius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bHasPath;

	
};
