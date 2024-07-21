// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Attribute/TBSAttributeSet.h"
#include "Interfaces/EntityInterface.h"
#include "TBSCharacter.generated.h"

UCLASS()
class TBS_API ATBSCharacter : public ACharacter, public IAbilitySystemInterface, public IEntityInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATBSCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	//TSubclassOf<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	TObjectPtr<UTBSAttributeSet> AttributeSet;

	UPROPERTY(BlueprintReadOnly, EditAnywhere,Category="Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere,Category="Attributes")
	TSubclassOf<UGameplayEffect> SecondaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere,Category="Attributes")
	TSubclassOf<UGameplayEffect> VitalAttributes;

	virtual void BeginPlay() override;

	void InitialiseDefaultAttributes() const;
	void ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& GameplayEffectClass, const float Level) const;
};
