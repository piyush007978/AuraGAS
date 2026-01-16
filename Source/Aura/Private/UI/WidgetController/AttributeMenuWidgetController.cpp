// Downbeatwolf


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "AuraGameplayTags.h"

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	check(AttributeInfo);

	for(const auto& Pair : AuraAttributeSet->TagsToAttributesMap)
	{
		const FGameplayTag& AttributeTag = Pair.Key;
		FAuraAttributeInfo FoundInfo = AttributeInfo->FindAttributeInfoForTag(AttributeTag, true);
		FoundInfo.AttributeValue = Pair.Value().GetNumericValue(AuraAttributeSet);
		OnAttributeInfo.Broadcast(FoundInfo);
	}
}

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	for(const auto& Pair : AuraAttributeSet->TagsToAttributesMap)
	{
		const FGameplayTag& AttributeTag = Pair.Key;
		FGameplayAttribute Attribute = Pair.Value();
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
			Attribute).AddLambda(
			[this, AttributeTag, Attribute](const FOnAttributeChangeData& Data)
			{
				FAuraAttributeInfo FoundInfo = AttributeInfo->FindAttributeInfoForTag(AttributeTag, true);
				FoundInfo.AttributeValue = Data.NewValue;
				OnAttributeInfo.Broadcast(FoundInfo);
			});
	}
}
