// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Abilities/TBSGameplayAbility.h"
#include "Engine/DataAsset.h"
#include "AbilityDataAsset.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FAbilityAsset : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName AbilityAssetName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Thumbnail;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag Tags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UTBSGameplayAbility> AbilityClass;
};

/**
 * 
 */
UCLASS()
class TBS_API UAbilityDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FAbilityAsset> Assets;
};
