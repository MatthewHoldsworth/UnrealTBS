// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameFramework/PlayerController.h"
#include "Grid/Tile/TileActor.h"
#include "TBSPlayerController.generated.h"

class UTBSAbilitySystemComponent;
class ATileActor;
class ATBSCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEntitySelected, TScriptInterface<IEntityInterface>, Entity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTileSelected, ATileActor*, Entity);

class IEntityInterface;
/**
 * 
 */
UCLASS()
class TBS_API ATBSPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATBSPlayerController();
	
	UPROPERTY(BlueprintAssignable)
	FOnEntitySelected OnEntitySelected;
	UPROPERTY(BlueprintAssignable)
	FOnTileSelected OnTileSelected;

	UPROPERTY(BlueprintReadOnly, Category= "Selected Ability")
	FGameplayAbilitySpecHandle PlayerSelectedAbility;

	UPROPERTY(BlueprintReadWrite, Category= "Selected Ability")
	bool bIsAbilitySelected;
	
	UPROPERTY(BlueprintReadWrite)
	TScriptInterface<IEntityInterface> SelectedEntity;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<ATileActor> SelectedTile;
	
	UFUNCTION(BlueprintCallable)
	void SelectedAbility(FGameplayAbilitySpecHandle AbilitySelected);
protected:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	TScriptInterface<IEntityInterface> GetEntityUnderCursor(bool bSelectEntity) const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	ATileActor* GetTileUnderCursor() const;
	
	UFUNCTION(BlueprintCallable, Category= "Selected Ability")
	bool ExecuteSelectedAbility(UTBSAbilitySystemComponent* Source);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Selected Ability")
	TSubclassOf<AActor> PathingObject;

	UPROPERTY(BlueprintReadWrite, Category= "Selected Ability")
	TArray<AActor*> SpawnedPathObjects;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category= "Selected Ability")
	TArray<ATileActor*> AbilityPath;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category= "Selected Ability")
	TArray<ATileActor*> TilesInRange;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category= "Selected Ability")
	TArray<ATileActor*> TilesInAbilityRadius;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category= "Selected Ability")
	int32 AbilityRadius;
};
