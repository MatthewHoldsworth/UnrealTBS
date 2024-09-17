// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridManager.generated.h"

class ATileActor;
class USphereComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTileHovered, ATileActor*, Tile);

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
	UPROPERTY(BlueprintAssignable)
	FOnTileHovered OnTileHovered;
	
	// Sets default values for this actor's properties
	AGridManager();

	UFUNCTION(BlueprintCallable)
	void InitGrid();

	UFUNCTION(BlueprintCallable)
	ATileActor* TileAt(int X, int Y);

	UFUNCTION(BlueprintCallable)
	TArray<ATileActor*> GetTilesInRange(ATileActor* Origin, int Range);

	UPROPERTY(BlueprintReadWrite)
	TArray<ATileActor*> TilesOfInterest;

	UFUNCTION(BlueprintCallable)
	void SetHighlightTiles(const TArray<ATileActor*> Tiles);
	
	UFUNCTION(BlueprintCallable)
	void AddTileToPath(ATileActor* Tile);
	
	UFUNCTION(BlueprintCallable)
	void TileHovered(ATileActor* Tile);
	
	UFUNCTION(BlueprintCallable)
	void CalculateDistances(ATileActor* Origin, TArray<ATileActor*> Tiles);
	
	UPROPERTY(EditDefaultsOnly, Category="Grid Properties")
	int GridX;

	UPROPERTY(EditDefaultsOnly, Category="Grid Properties")
	int GridY;
protected:
	UPROPERTY(BlueprintReadWrite)
	TArray<ATileActor*> HighlightedTiles;
	
	UPROPERTY(BlueprintReadWrite)
	TArray<ATileActor*> TilePath;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USphereComponent> DebugSphere;
	
	UFUNCTION(BlueprintCallable)
	void GenerateTileMapNeighbours();
private:
	int GridOffsetValueX = 0;
	int GridOffsetValueY = 0;
	
	UPROPERTY(VisibleAnywhere)
	TMap<FIntVector, TObjectPtr<ATileActor>> TileMap;
	
	UPROPERTY(EditDefaultsOnly, Category="Grid Properties")
	TSubclassOf<ATileActor> TileClass;
	
};
