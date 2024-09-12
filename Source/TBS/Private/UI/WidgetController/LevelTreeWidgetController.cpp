// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/LevelTreeWidgetController.h"

#include "UI/TBSUserWidget.h"

void ULevelTreeWidgetController::ShowAllAvailable()
{
	UTreeSlotController* TreeSlotController;
	for (auto Element : TreeSlotsMap)
	{
		TreeSlotController = Cast<UTreeSlotController>(Element.Value.Get()->WidgetController);
		Cast<UTreeSlotController>(Element.Value.Get()->WidgetController)->StartingPoint;
	}
}
