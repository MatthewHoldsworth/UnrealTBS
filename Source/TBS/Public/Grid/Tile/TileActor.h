// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/TBSActor.h"
#include "TileActor.generated.h"

/**
 * 
 */
UCLASS()
class TBS_API ATileActor : public ATBSActor
{
	GENERATED_BODY()
public:
	ATileActor();
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> CubeComponent;
};
