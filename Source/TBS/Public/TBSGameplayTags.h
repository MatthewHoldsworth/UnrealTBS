// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FTBSGameplayTags
{
public:
	static const FTBSGameplayTags& Get(){return GameplayTags;}

	static void InitialiseNativeGameplayTags();

	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Dexterity;
	FGameplayTag Attributes_Primary_Constitution;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Wisdom;
	FGameplayTag Attributes_Primary_Charisma;
protected:

private:
	static FTBSGameplayTags GameplayTags;
};