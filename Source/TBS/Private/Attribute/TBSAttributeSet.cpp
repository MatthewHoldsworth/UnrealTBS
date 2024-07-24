// Fill out your copyright notice in the Description page of Project Settings.


#include "Attribute/TBSAttributeSet.h"

#include "TBSGameplayTags.h"

UTBSAttributeSet::UTBSAttributeSet()
{
	// Strength = 10.f;
	// Dexterity = 10.f;
	// Constitution = 10.f;
	// Intelligence = 10.f;
	// Wisdom = 10.f;
	// Charisma = 10.f;

	const FTBSGameplayTags GameplayTags = FTBSGameplayTags::Get();

	TagsToAttributes.Add(GameplayTags.Attributes_Primary_Strength, GetStrengthAttribute);

	TagsToAttributes.Add(GameplayTags.Attributes_Primary_Dexterity, GetDexterityAttribute);

	TagsToAttributes.Add(GameplayTags.Attributes_Primary_Constitution, GetConstitutionAttribute);

	TagsToAttributes.Add(GameplayTags.Attributes_Primary_Intelligence, GetIntelligenceAttribute);

	TagsToAttributes.Add(GameplayTags.Attributes_Primary_Wisdom, GetWisdomAttribute);

	TagsToAttributes.Add(GameplayTags.Attributes_Primary_Charisma, GetCharismaAttribute);
}
