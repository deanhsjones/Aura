// Copyright Dean Jones


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AuraGameplayTags.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies() 
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);
	check(AttributeInfo);
	for (auto& Pair : AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
			[this, Pair](const FOnAttributeChangeData& Data)
			{
				//get the AttributeInfo
				//get an FAuraAttributeInfo struct
				//FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
				//make sure it’s attribute value is correct
				//Info.AttributeValue = Pair.Value().GetNumericValue(AS);
				//and broadcast that struct to widgets
				//AttributeInfoDelegate.Broadcast(Info);

				BroadcastAttributeInfo(Pair.Key, Pair.Value());
			}
		);
	}
	

}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag AttributeTag, const FGameplayAttribute& Attribute) const
{
	FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}

void UAttributeMenuWidgetController::BroadcastInitialValues() 
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);

	check(AttributeInfo);


	for (auto& Pair : AS->TagsToAttributes)
	{
		//FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
		//Info.AttributeValue = Pair.Value().GetNumericValue(AS);
		//AttributeInfoDelegate.Broadcast(Info);

		BroadcastAttributeInfo(Pair.Key, Pair.Value());
	}
}