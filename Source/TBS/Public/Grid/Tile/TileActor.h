// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/TBSActor.h"
#include "TileActor.generated.h"

class ATBSCharacter;
/**
 * 
 */
UCLASS()
class TBS_API ATileActor : public ATBSActor
{
	GENERATED_BODY()
public:
	ATileActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<ATBSCharacter> Occupant;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<TObjectPtr<ATileActor>, int32> Neighbours;

	UFUNCTION(BlueprintCallable)
	bool SetOccupant(ATBSCharacter* NewOccupant);
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> CubeComponent;
};
