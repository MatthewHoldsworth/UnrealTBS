// Fill out your copyright notice in the Description page of Project Settings.


#include "TBSBlueprintFunctionLibrary.h"

#include "UI/TBSUserWidget.h"

UTBSWidgetController* UTBSBlueprintFunctionLibrary::GetWidgetController(UUserWidget* ControlledWidget)
{
	return CastChecked<UTBSUserWidget>(ControlledWidget)->Controller;
}
