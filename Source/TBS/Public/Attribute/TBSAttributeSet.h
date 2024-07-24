// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "TBSAttributeSet.generated.h"

#define TBS_ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

DECLARE_DELEGATE_RetVal(FGameplayAttribute, FAttributeSignature);


USTRUCT(BlueprintType)
struct FTBSAttributeInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag AttributeTag = FGameplayTag();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeName = FText();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeDescription = FText();

	UPROPERTY(BlueprintReadOnly)
	float AttributeValue = 0.f;
};

template<class T>
using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;

/**
 * 
 */
UCLASS()
class TBS_API UTBSAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UTBSAttributeSet();

	TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Strength;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, Strength);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Dexterity;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, Dexterity);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Constitution;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, Constitution);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Intelligence;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, Intelligence);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Wisdom;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, Wisdom);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Charisma;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, Charisma);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxHealth;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, MaxHealth);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxStamina;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, MaxStamina);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxMana;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, MaxMana);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxMovementPoints;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, MaxMovementPoints);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Health;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Stamina;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, Stamina);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Mana;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, Mana);
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MovementPoints;
	TBS_ATTRIBUTE_ACCESSORS(UTBSAttributeSet, MovementPoints);
};
