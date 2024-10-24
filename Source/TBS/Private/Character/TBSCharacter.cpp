// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TBSCharacter.h"

#include "TBSGameplayTags.h"
#include "Attribute/TBSAbilitySystemComponent.h"
#include "Components/WidgetComponent.h"

// Sets default values
ATBSCharacter::ATBSCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UTBSAbilitySystemComponent>("AbilitySystem");
 	AttributeSet = CreateDefaultSubobject<UTBSAttributeSet>("AttributeSet");
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>("WidgetComponent");
	WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	WidgetComponent->SetDrawAtDesiredSize(true);
	WidgetComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

UAbilitySystemComponent* ATBSCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

ATileActor* ATBSCharacter::GetEntityLocation() const
{
	return EntityLocation;
}

void ATBSCharacter::SetEntityLocation(ATileActor* NewLocation)
{
	EntityLocation = NewLocation;
}

void ATBSCharacter::Destroyed()
{
	Super::Destroyed();

	//const UTBSAttributeSet* AttributeSet = Cast<UTBSAttributeSet>(AbilitySystemComponent->GetAttributeSet(UTBSAttributeSet::StaticClass()));

	for(const auto& It : AttributeSet->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(It.Value()).Clear();
	}
}

void ATBSCharacter::BeginMovement(TArray<ATileActor*> Path)
{
	bIsMoving = true;
	MovementPath = Path;
}

bool ATBSCharacter::CanMoveToNextTile()
{
	return true;
}

void ATBSCharacter::StopMoveToNextTile()
{
	bIsMoving = false;
	MovementPath.Empty();
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

