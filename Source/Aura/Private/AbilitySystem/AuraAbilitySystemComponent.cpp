// Downbeatwolf


#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::OnAbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<class UGameplayAbility>>& AbilitiesToAdd)
{
	for (TSubclassOf<UGameplayAbility> AbilityClass : AbilitiesToAdd)
	{
		if (IsValid(AbilityClass))
		{
			FGameplayAbilitySpec GameplayAbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
			//GiveAbility(FGameplayAbilitySpec(AbilityClass, 1));
			GiveAbilityAndActivateOnce(GameplayAbilitySpec);
		}
	}
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* Source, const FGameplayEffectSpec& SpecApplied, FActiveGameplayEffectHandle ActiveHandle)
{
	FGameplayTagContainer Container;
	SpecApplied.GetAllAssetTags(Container);
	OnEffectAssetTags.Broadcast(Container);
}
