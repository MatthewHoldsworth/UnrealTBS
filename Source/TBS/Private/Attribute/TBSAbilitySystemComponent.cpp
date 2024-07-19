// Fill out your copyright notice in the Description page of Project Settings.


#include "Attribute/TBSAbilitySystemComponent.h"

#include "Attribute/TBSAttributeSet.h"

UTBSAbilitySystemComponent::UTBSAbilitySystemComponent()
{
	
}

void UTBSAbilitySystemComponent::InitialiseCallbacks()
{
	const TSubclassOf<UTBSAttributeSet> AttributeClass;
	GetGameplayAttributeValueChangeDelegate(Cast<UTBSAttributeSet>(GetAttributeSet(AttributeClass))->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data){AttributeChanged.Broadcast("Health", 1.0f,1.0f);});
}
