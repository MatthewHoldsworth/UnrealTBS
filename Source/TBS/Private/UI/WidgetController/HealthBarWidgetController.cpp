// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/HealthBarWidgetController.h"

#include "TBSGameplayTags.h"
#include "Attribute/TBSAttributeSet.h"
#include "Attribute/TBSAbilitySystemComponent.h"

void UHealthBarWidgetController::InitialiseCallbacks(UTBSAbilitySystemComponent* AbilitySystemComponent)
{
	const UTBSAttributeSet* AttributeSet = Cast<UTBSAttributeSet>(AbilitySystemComponent->GetAttributeSet(UTBSAttributeSet::StaticClass()));
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddLambda([this, AttributeSet](const FOnAttributeChangeData& Data)
	{
		BroadcastHealth(FTBSGameplayTags::Get().Attributes_Vital_Health, AttributeSet->GetHealthAttribute(), AttributeSet);
	});
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHealthAttribute()).AddLambda([this, AttributeSet](const FOnAttributeChangeData& Data)
	{
		BroadcastHealth(FTBSGameplayTags::Get().Attributes_Vital_MaxHealth, AttributeSet->GetMaxHealthAttribute(), AttributeSet);
	});
}

void UHealthBarWidgetController::ClearCallbacks(UTBSAbilitySystemComponent* AbilitySystemComponent)
{
	const UTBSAttributeSet* AttributeSet = Cast<UTBSAttributeSet>(AbilitySystemComponent->GetAttributeSet(UTBSAttributeSet::StaticClass()));

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).Clear();
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHealthAttribute()).Clear();
}

void UHealthBarWidgetController::InitialBroadcast(UTBSAbilitySystemComponent* AbilitySystemComponent)
{
	const UTBSAttributeSet* AttributeSet = Cast<UTBSAttributeSet>(AbilitySystemComponent->GetAttributeSet(UTBSAttributeSet::StaticClass()));
	
	BroadcastHealth(FTBSGameplayTags::Get().Attributes_Vital_Health, AttributeSet->GetHealthAttribute(), AttributeSet);
	BroadcastHealth(FTBSGameplayTags::Get().Attributes_Vital_MaxHealth, AttributeSet->GetMaxHealthAttribute(), AttributeSet);
}

void UHealthBarWidgetController::BroadcastHealth(const FGameplayTag& Tag, const FGameplayAttribute& Attribute,
	const UTBSAttributeSet* AttributeSet) const
{
	FTBSAttributeInfo Info;
	Info.AttributeTag = Tag;
	Info.AttributeName = FName(Attribute.AttributeName);//Tag.GetTagName();
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, Info.AttributeName);	
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "HEKLLAODOASD");	
	HealthInfoDelegate.Broadcast(Info);
}

