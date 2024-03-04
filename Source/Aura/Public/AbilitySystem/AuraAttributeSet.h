// Downbeatwolf

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
/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty> & OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData myHealth;

	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, myHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData myMaxHealth;
	
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, myMaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData myMana;

	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, myMana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData myMaxMana;

	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, myMaxMana);

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& anOldValue) const;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& anOldValue) const;
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& anOldValue) const;
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& anOldValue) const;
	
};
