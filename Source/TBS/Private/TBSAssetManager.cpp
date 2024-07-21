// Fill out your copyright notice in the Description page of Project Settings.


#include "TBSAssetManager.h"

#include "TBSGameplayTags.h"

UTBSAssetManager& UTBSAssetManager::Get()
{
	check(GEngine)
	UTBSAssetManager* AssetManager = Cast<UTBSAssetManager>(GEngine->AssetManager);

	return *AssetManager;
}

void UTBSAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FTBSGameplayTags::InitialiseNativeGameplayTags();
}
