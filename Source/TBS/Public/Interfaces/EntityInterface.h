// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EntityInterface.generated.h"

class ATileActor;
// This class does not need to be modified.
UINTERFACE(meta = (CannotImplementInterfaceInBlueprint))
class UEntityInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TBS_API IEntityInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, Category = "Entity Functions")
	virtual ATileActor* GetEntityLocation() const = 0;

	UFUNCTION(BlueprintCallable, Category = "Entity Functions")
	virtual void SetEntityLocation(ATileActor* NewLocation) = 0;
	
	//UPROPERTY(BlueprintReadOnly, Category="Entity")
	FName EntityName;
	
	//UPROPERTY(BlueprintReadOnly, Category="Entity")
	FString EntityDescription;
	
	//UPROPERTY(BlueprintReadOnly, Category="Entity")
	TObjectPtr<ATileActor> EntityLocation;
};
