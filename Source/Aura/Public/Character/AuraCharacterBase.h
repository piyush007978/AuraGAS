// Downbeatwolf

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const {return myAttributeSet; }
protected:

	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnyWhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> myWeapon;
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> myAbilitySystemComponent;
	UPROPERTY()
	TObjectPtr <UAttributeSet> myAttributeSet;
};
