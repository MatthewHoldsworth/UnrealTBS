// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "TBSGameplayAbility.generated.h"

class UTBSAbilitySystemComponent;

UENUM(BlueprintType)
enum ETargetTypes
{
	Self,
	Entities,
	Allies,
	Enemies,
	Tiles,
	Any
};

UENUM(BlueprintType)
enum ERadiusTypes
{
	None,
	Tile,
	Sphere
};

USTRUCT(BlueprintType)
struct FTargetParams
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TEnumAsByte<ETargetTypes> ValidTargets;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TEnumAsByte<ERadiusTypes> RadiusType;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bAffectsAllies = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bAffectsEnemies = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bAffectsTiles = false;
	//Is Last
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bCanTargetSelf = false;
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
	
	// UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	// TEnumAsByte<ETargetTypes> ValidTargets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FTargetParams TargetParameters;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void InitAbilityInfo(UTBSAbilitySystemComponent* AbilitySystemComponent) const;
	
// protected:
// 	void InitAbilityInfo_Implementation();
};
