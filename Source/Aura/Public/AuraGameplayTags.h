// Copyright Dean Jones

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 *	AuraGameplayTags
 * 
 *	This is a singleton containing native gameplay tags
 */

struct FAuraGameplayTags
{
public:
	static const FAuraGameplayTags& Get() { return GameplayTags; }
	static void InitialiseNativeGameplayTags();

	FGameplayTag Attributes_Secondary_Armor;

protected:

private:
	static FAuraGameplayTags GameplayTags;
};
