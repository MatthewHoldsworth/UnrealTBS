// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "Attribute/TBSAbilitySystemComponent.h"
#include "Attribute/TBSAttributeSet.h"

UAttributeMenuWidgetController::UAttributeMenuWidgetController()
{
}

void UAttributeMenuWidgetController::InitialiseCallbacks(UTBSAbilitySystemComponent* AbilitySystemComponent)
{
	const UTBSAttributeSet* AttributeSet = Cast<UTBSAttributeSet>(AbilitySystemComponent->GetAttributeSet(UTBSAttributeSet::StaticClass()));
	for(auto& It : AttributeSet->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(It.Value()).AddLambda([this, It, AttributeSet](const FOnAttributeChangeData& Data)
		{
			Broadcast(It.Key, It.Value(), AttributeSet);
			//FTBSAttributeInfo info;
			//info.AttributeTag = it.Key;
			//info.AttributeName = FName(Data.Attribute.GetName());
			//info.AttributeValue = Data.NewValue;
			//AttributeInfoDelegate.Broadcast(info);
		});
		
		//AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(It.Value()).Clear();
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, it.Key.GetTagName().ToString());	
	}
}

void UAttributeMenuWidgetController::ClearCallbacks(UTBSAbilitySystemComponent* AbilitySystemComponent)
{
	const UTBSAttributeSet* AttributeSet = Cast<UTBSAttributeSet>(AbilitySystemComponent->GetAttributeSet(UTBSAttributeSet::StaticClass()));
	for(auto& It : AttributeSet->TagsToAttributes)
	{
		//AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(It.Value()).Remove();
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(It.Value()).RemoveAll(this);
		//AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(It.Value()).Clear();
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, it.Key.GetTagName().ToString());	
	}
}

void UAttributeMenuWidgetController::InitialBroadcast(UTBSAbilitySystemComponent* AbilitySystemComponent)
{
	const UTBSAttributeSet* AttributeSet = Cast<UTBSAttributeSet>(AbilitySystemComponent->GetAttributeSet(UTBSAttributeSet::StaticClass()));
	for(auto& It : AttributeSet->TagsToAttributes)
	{
		Broadcast(It.Key, It.Value(), AttributeSet);
		// FTBSAttributeInfo info;
		// info.AttributeTag = it.Key;
		// info.AttributeValue = it.Value().GetNumericValue(AS);
		// AttributeInfoDelegate.Broadcast(info);
	}
}

void UAttributeMenuWidgetController::Broadcast(const FGameplayTag& Tag, const FGameplayAttribute& Attribute, const UTBSAttributeSet* AttributeSet) const
{
	FTBSAttributeInfo Info;
	Info.AttributeTag = Tag;
	Info.AttributeName = FName(Attribute.AttributeName);//Tag.GetTagName();
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, Info.AttributeName);	
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "HEKLLAODOASD");	
	AttributeInfoDelegate.Broadcast(Info);
}
