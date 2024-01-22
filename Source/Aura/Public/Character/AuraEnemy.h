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

	/*
	*	Combat Interface
	*/
	int32 GetPlayerLevel() override;
	/*
	*	Combat Interface end
	*/

protected:
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;
private:

};
