// Copyright Dean Jones


#include "AuraAssetManager.h"
#include "AuraGameplayTags.h"
#include <AbilitySystemGlobals.h>

UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);

	UAuraAssetManager* AuraAssetManager = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AuraAssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FAuraGameplayTags::InitialiseNativeGameplayTags();

	//REQUIRED to use Target Data!
	UAbilitySystemGlobals::Get().InitGlobalData();
}
