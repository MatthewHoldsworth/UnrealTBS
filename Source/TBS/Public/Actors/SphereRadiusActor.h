// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SphereRadiusActor.generated.h"

UCLASS()
class TBS_API ASphereRadiusActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASphereRadiusActor();

	UFUNCTION(BlueprintCallable)
	void ShowSphereAt(FVector NewLocation, int32 NewRadius, FColor Colour = FColor::Blue);
	
	UFUNCTION(BlueprintCallable)
	void HideSphere();

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> SphereComponent;

};
