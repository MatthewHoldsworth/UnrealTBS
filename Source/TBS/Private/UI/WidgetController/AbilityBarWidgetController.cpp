// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AbilityBarWidgetController.h"

#include "Attribute/TBSAbilitySystemComponent.h"
#include "Character/TBSCharacter.h"

void UAbilityBarWidgetController::SetSelectedAbility(FGameplayAbilitySpecHandle AbilitySpecHandle)
{
	SelectedAbility = AbilitySpecHandle;
}

void UAbilityBarWidgetController::SetSelectedCharacter(ATBSCharacter* Character)
{
	SelectedCharacter = Character;
}

void UAbilityBarWidgetController::ActivateSelectedAbility()
{
	SelectedCharacter->GetAbilitySystemComponent()->TryActivateAbility(SelectedAbility);
}
