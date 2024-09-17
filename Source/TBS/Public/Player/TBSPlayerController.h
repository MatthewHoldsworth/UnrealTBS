// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameFramework/PlayerController.h"
#include "TBSPlayerController.generated.h"

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

	UPROPERTY(BlueprintReadOnly)
	FGameplayAbilitySpecHandle PlayerSelectedAbility;
	
	UPROPERTY(BlueprintReadWrite)
	TScriptInterface<IEntityInterface> SelectedEntity;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<ATileActor> SelectedTile;
protected:
	UFUNCTION(BlueprintCallable)
	TScriptInterface<IEntityInterface> GetEntityUnderCursor(bool SelectEntity) const;
	
	UFUNCTION(BlueprintCallable)
	bool ExecuteSelectedAbility(UTBSAbilitySystemComponent* Source);
	
	UFUNCTION(BlueprintCallable)
	ATileActor* GetTileUnderCursor();
};
