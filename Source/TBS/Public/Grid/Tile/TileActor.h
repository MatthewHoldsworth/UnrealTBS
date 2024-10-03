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
	TArray<TObjectPtr<ATileActor>> Neighbours;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float Distance = -1.0f;

	UFUNCTION(BlueprintCallable)
	bool SetOccupant(ATBSCharacter* NewOccupant);

	UFUNCTION(BlueprintCallable)
	void GenerateNeighbours();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Highlight();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UnHighlight();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsHighlighted() const;
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<ATBSCharacter> Occupant;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> CubeComponent;

	UPROPERTY(BlueprintReadWrite)
	int32 HighlightLevel;
};
