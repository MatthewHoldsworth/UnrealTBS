// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TBSCharacter.h"

#include "Attribute/TBSAbilitySystemComponent.h"

// Sets default values
ATBSCharacter::ATBSCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UTBSAbilitySystemComponent>("AbilitySystem");
 	AttributeSet = CreateDefaultSubobject<UTBSAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ATBSCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ATBSCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	InitialiseDefaultAttributes();
}

void ATBSCharacter::InitialiseDefaultAttributes() const
{
	if(DefaultPrimaryAttributes)
		ApplyEffectToSelf(DefaultPrimaryAttributes, 1.0f);
	if(SecondaryAttributes)
		ApplyEffectToSelf(SecondaryAttributes, 1.0f);
	if(VitalAttributes)
		ApplyEffectToSelf(VitalAttributes, 1.0f);
}

void ATBSCharacter::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& GameplayEffectClass, const float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

