// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "TBSAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class TBS_API UTBSAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static UTBSAssetManager& Get();

protected:

	virtual void StartInitialLoading() override;
};
