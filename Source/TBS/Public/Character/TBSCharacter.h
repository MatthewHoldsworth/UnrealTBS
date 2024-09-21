// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Attribute/TBSAttributeSet.h"
#include "Interfaces/EntityInterface.h"
#include "TBSCharacter.generated.h"

class UWidgetComponent;

UCLASS()
class TBS_API ATBSCharacter : public ACharacter, public IAbilitySystemInterface, public IEntityInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATBSCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable)
	virtual ATileActor* GetEntityLocation() const override;
	UFUNCTION(BlueprintCallable)
	virtual void SetEntityLocation(ATileActor* NewLocation) override;

	virtual void Destroyed() override;

#pragma region Character Tile Movement
	UPROPERTY(BlueprintReadWrite, Category="Character Tile Movement")
	bool bIsMoving;

	UPROPERTY(BlueprintReadWrite, Category="Character Tile Movement")
	TArray<ATileActor*> MovementPath;

	UFUNCTION(BlueprintCallable, Category="Character Tile Movement")
	void BeginMovement(TArray<ATileActor*> Path);

	UFUNCTION(BlueprintImplementableEvent, Category="Character Tile Movement")
	void MoveToNextTile();
	
	UFUNCTION(BlueprintCallable, Category="Character Tile Movement")
	bool CanMoveToNextTile();
	
	UFUNCTION(BlueprintCallable, Category="Character Tile Movement")
	void StopMoveToNextTile();
#pragma endregion 
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> WidgetComponent;

	//TSubclassOf<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	TObjectPtr<UTBSAttributeSet> AttributeSet;

	UPROPERTY(BlueprintReadOnly, EditAnywhere,Category="Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere,Category="Attributes")
	TSubclassOf<UGameplayEffect> SecondaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere,Category="Attributes")
	TSubclassOf<UGameplayEffect> VitalAttributes;

	virtual void BeginPlay() override;

	void InitialiseDefaultAttributes() const;
	void ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& GameplayEffectClass, const float Level) const;
};
