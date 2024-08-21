// Fill out your copyright notice in the Description page of Project Settings.


#include "TBSGameplayTags.h"

#include "GameplayTagsManager.h"

FTBSGameplayTags FTBSGameplayTags:: GameplayTags;

void FTBSGameplayTags::InitialiseNativeGameplayTags()
{
#pragma region Primary Attributes
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength"), FString("Strength"));
	GameplayTags.Attributes_Primary_Dexterity = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Dexterity"), FString("Dexterity"));
	GameplayTags.Attributes_Primary_Constitution = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Constitution"), FString("Constitution"));
	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"), FString("Intelligence"));
	GameplayTags.Attributes_Primary_Wisdom = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Wisdom"), FString("Wisdom"));
	GameplayTags.Attributes_Primary_Charisma = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Charisma"), FString("Charisma"));
#pragma endregion

#pragma region Vital Attributes
	GameplayTags.Attributes_Vital_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Health"), FString("Health"));
	GameplayTags.Attributes_Vital_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.MaxHealth"), FString("Max Health"));
#pragma endregion

#pragma region Abilities
	GameplayTags.Abilities_Basic_Move = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Abilities.Basic.Move"), FString("Move"));
#pragma endregion 
}
