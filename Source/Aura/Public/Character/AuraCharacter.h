// Copyright Dean Jones

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"

#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();

	/*begin interface*/
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	/*end interface*/

	/* 
	*	Combat Interface
	*/
	virtual int32 GetPlayerLevel() override;

	/*
	*	end combat interface 
	*/

	
private:
	virtual void InitAbilityActorInfo() override;

};
