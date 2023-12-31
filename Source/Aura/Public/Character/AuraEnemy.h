// Copyright Dean Jones

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/MouseoverInterface.h"
#include "AuraEnemy.generated.h"


/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IMouseoverInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();


	/*Enemy interface*/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/*End enemy interface*/

protected:
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;
};
