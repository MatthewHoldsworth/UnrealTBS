// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UI/WidgetController/TBSWidgetController.h"
#include "TreeSlotController.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FTreeSlot : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName SlotDisplayName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Thumbnail;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag Tags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FIntVector SlotID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FIntVector> Adjacent;

	/*
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UTBSGameplayAbility> AbilityClass;*/
};


USTRUCT(BlueprintType, Blueprintable)
struct FTreeSlotParams
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	bool HasUnlocked;
	
	UPROPERTY(EditAnywhere)
	bool CanUnlock;
	
	UPROPERTY(EditAnywhere)
	bool StartingPoint;

	UPROPERTY(EditAnywhere)
	FIntVector TreePosition;
};


/**
 * 
 */
UCLASS()
class TBS_API UTreeSlotController : public UTBSWidgetController
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	bool HasUnlocked;
	
	UPROPERTY(BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	bool CanUnlock;
	
	UPROPERTY(BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	bool StartingPoint;

	UPROPERTY(BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	FIntVector TreePosition;
};
