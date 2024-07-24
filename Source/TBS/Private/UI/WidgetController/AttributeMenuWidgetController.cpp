// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "Attribute/TBSAbilitySystemComponent.h"
#include "Attribute/TBSAttributeSet.h"

UAttributeMenuWidgetController::UAttributeMenuWidgetController()
{
}

void UAttributeMenuWidgetController::InitialiseCallbacks(UTBSAbilitySystemComponent* AbilitySystemComponent)
{
	const UTBSAttributeSet* AS = Cast<UTBSAttributeSet>(AbilitySystemComponent->GetAttributeSet(UTBSAttributeSet::StaticClass()));
	for(auto& it : AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(it.Value()).AddLambda([this, it](const FOnAttributeChangeData& Data)
		{
			FTBSAttributeInfo info;
			info.AttributeTag = it.Key;
			info.AttributeValue = 5.0f;
			AttributeInfoDelegate.Broadcast(info);
		});
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, it.Key.GetTagName().ToString());	
	}
}
