// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IntVectorTypes.h"
#include "GameFramework/Actor.h"
#include "GridManager.generated.h"

class ATileActor;
class USphereComponent;

// USTRUCT()
// struct FGridLocation
// {
// 	GENERATED_BODY()
// 	
// };

UCLASS()
class TBS_API AGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridManager();

	UFUNCTION(BlueprintCallable)
	void InitGrid();
protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USphereComponent> DebugSphere;
private:
	UPROPERTY(VisibleAnywhere)
	TMap<FIntVector2, TObjectPtr<ATileActor>> TileMap;

	UPROPERTY(EditDefaultsOnly, Category="Grid Properties")
	int GridX;

	UPROPERTY(EditDefaultsOnly, Category="Grid Properties")
	int GridY;
	
	UPROPERTY(EditDefaultsOnly, Category="Grid Properties")
	TSubclassOf<ATileActor> TileClass;
	
};
