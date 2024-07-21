// Fill out your copyright notice in the Description page of Project Settings.


#include "TBSGameplayTags.h"

#include "GameplayTagsManager.h"

FTBSGameplayTags FTBSGameplayTags:: GameplayTags;

void FTBSGameplayTags::InitialiseNativeGameplayTags()
{
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Abilities.Primary.Strength"), FString("Strength"));
	GameplayTags.Attributes_Primary_Dexterity = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Abilities.Primary.Dexterity"), FString("Dexterity"));
	GameplayTags.Attributes_Primary_Constitution = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Abilities.Primary.Constitution"), FString("Constitution"));
	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Abilities.Primary.Intelligence"), FString("Intelligence"));
	GameplayTags.Attributes_Primary_Wisdom = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Abilities.Primary.Wisdom"), FString("Wisdom"));
	GameplayTags.Attributes_Primary_Charisma = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Abilities.Primary.Charisma"), FString("Charisma"));
}
