// Downbeatwolf


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
    return myAbilitySystemComponent;
}

AAuraPlayerState::AAuraPlayerState()
{
    NetUpdateFrequency = 100.f;
    myAbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
    myAbilitySystemComponent->SetIsReplicated(true);
    myAbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
    myAttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}