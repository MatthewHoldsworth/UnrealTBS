// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/TBSGameStateBase.h"

void ATBSGameStateBase::EnterCombat()
{
	bInCombat = true;
	CombatStateChanged.Broadcast(bInCombat);
}

void ATBSGameStateBase::ExitCombat()
{
	bInCombat = false;
	CombatStateChanged.Broadcast(bInCombat);
}
