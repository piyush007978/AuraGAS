// Downbeatwolf

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
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
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
    UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	AAuraPlayerState();
    UPROPERTY()
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
    UPROPERTY()
    TObjectPtr <UAttributeSet> AttributeSet;
};
