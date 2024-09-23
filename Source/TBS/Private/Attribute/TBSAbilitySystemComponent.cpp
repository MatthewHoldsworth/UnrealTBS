// Fill out your copyright notice in the Description page of Project Settings.


#include "Attribute/TBSAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Abilities/TBSGameplayAbility.h"
#include "Attribute/TBSAttributeSet.h"

UTBSAbilitySystemComponent::UTBSAbilitySystemComponent()
{
	
}

void UTBSAbilitySystemComponent::InitialiseCallbacks()
{
	const TSubclassOf<UTBSAttributeSet> AttributeClass;
	GetGameplayAttributeValueChangeDelegate(Cast<UTBSAttributeSet>(GetAttributeSet(AttributeClass))->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data){AttributeChanged.Broadcast("Health", 1.0f,1.0f);});
}

void UTBSAbilitySystemComponent::BroadcastInitialValues()
{
	
}

void UTBSAbilitySystemComponent::InitGivenAbilities()
{
	TArray<FGameplayAbilitySpecHandle> TESTT;
	GetAllAbilities(TESTT);
	bool t = true;
	for (auto it : TESTT)
	{
		const UTBSGameplayAbility* TBSAbility = Cast<UTBSGameplayAbility>(UAbilitySystemBlueprintLibrary::GetGameplayAbilityFromSpecHandle(this, it, t));
		TBSAbility->InitAbilityInfo(this);
		//const UGameplayAbility* Ability = UAbilitySystemBlueprintLibrary::GetGameplayAbilityFromSpecHandle(this, it, t);
		
	}
}
