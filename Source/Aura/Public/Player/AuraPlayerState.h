// Copyright Dean Jones

#pragma once

#include "AbilitySystemInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "AuraPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;


/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AAuraPlayerState();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	FORCEINLINE int32 GetPlayerLevel() const { return Level; }

protected:

	UPROPERTY(VisibleAnywhere)
		TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
		TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_Level, Category = "Character Class Defaults")
		int32 Level = 1;

	UFUNCTION()
		void OnRep_Level(int32 OldLevel) const;
private:

};
