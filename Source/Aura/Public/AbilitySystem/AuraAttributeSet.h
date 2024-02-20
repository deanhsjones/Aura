// Copyright Dean Jones

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"

#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()
		
		FEffectProperties() {}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
		UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
		AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
		AController* SourceController = nullptr;

	UPROPERTY()
		ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
		UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
		AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
		AController* TargetController = nullptr;

	UPROPERTY()
		ACharacter* TargetCharacter = nullptr;
};

//typedef is specific to the FGameplayAttribute() signature, TSTaticFuncPtr is generic t any signatire chosen
//typedef TBaseStaticDelegateInstance<FGameplayAttribute(), FDefaultDelegateUserPolicy>::FFuncPtr FAttributeFuncPtr;
template<class T>
using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;


	/*
	*	Primary Attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Attributes")
		FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resilience, Category = "Primary Attributes")
		FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Resilience);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor, Category = "Primary Attributes")
		FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Vigor);

	/* attributes
	*	Vital Attributes
	*/


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	//Getter accessor function example
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
		FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);


	/*
	*	Secondary Attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Secondary Attributes")
		FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Armor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmorPen, Category = "Secondary Attributes")
		FGameplayAttributeData ArmorPen;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ArmorPen);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "Secondary Attributes")
		FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, BlockChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CritChance, Category = "Secondary Attributes")
		FGameplayAttributeData CritChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CritChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CritDmg, Category = "Secondary Attributes")
		FGameplayAttributeData CritDmg;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CritDmg);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CritResist, Category = "Secondary Attributes")
		FGameplayAttributeData CritResist;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CritResist);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegen, Category = "Secondary Attributes")
		FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, HealthRegen);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegen, Category = "Secondary Attributes")
		FGameplayAttributeData ManaRegen;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ManaRegen);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Secondary Attributes")
		FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Secondary Attributes")
		FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);

	//end attributes


	//rep notifs

	//vital

	UFUNCTION()
	void  OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	UFUNCTION()
		void  OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	//primary
	UFUNCTION()
		void  OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
		void  OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
		void  OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;

	UFUNCTION()
		void  OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;

	//secondary
	UFUNCTION()
		void  OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	UFUNCTION()
		void  OnRep_ArmorPen(const FGameplayAttributeData& OldArmorPen) const;

	UFUNCTION()
		void  OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

	UFUNCTION()
		void  OnRep_CritChance(const FGameplayAttributeData& OldCritChance) const;

	UFUNCTION()
		void  OnRep_CritDmg(const FGameplayAttributeData& OldCritDmg) const;

	UFUNCTION()
		void  OnRep_CritResist(const FGameplayAttributeData& OldCritResist) const;

	UFUNCTION()
		void  OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen) const;

	UFUNCTION()
		void  OnRep_ManaRegen(const FGameplayAttributeData& OldManaRegen) const;

	UFUNCTION()
		void  OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;


	UFUNCTION()
		void  OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;



	//end rep notifs

private:

		void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;


};
