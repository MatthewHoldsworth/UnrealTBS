// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AbilityBarWidgetController.h"

#include "Attribute/TBSAbilitySystemComponent.h"
#include "Character/TBSCharacter.h"
#include "Player/TBSPlayerController.h"

void UAbilityBarWidgetController::SetSelectedAbility(FGameplayAbilitySpecHandle AbilitySpecHandle)
{
	if (IsValid(SelectedCharacter))
	{
		Cast<ATBSPlayerController>(SelectedCharacter->GetController())->PlayerSelectedAbility = AbilitySpecHandle;
		Cast<ATBSPlayerController>(SelectedCharacter->GetController())->bIsAbilitySelected = true;
	}
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
