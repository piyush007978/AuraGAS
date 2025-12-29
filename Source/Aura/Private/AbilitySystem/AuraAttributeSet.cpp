// Downbeatwolf


#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UAuraAttributeSet::UAuraAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(50.f);
}

void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UAuraAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if(Attribute == GetHealthAttribute())
	{
		// Clamp health values
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}

	if(Attribute == GetManaAttribute())
	{
		// Clamp mana values
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
}

void UAuraAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	//if(Data.EvaluatedData.Attribute == GetHealthAttribute())
	//{
	//	// Clamp health values
	//	SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	//}
	//if(Data.EvaluatedData.Attribute == GetManaAttribute())
	//{
	//	// Clamp mana values
	//	SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	//}
}

void UAuraAttributeSet::OnRep_Health(const FGameplayAttributeData& anOldValue) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Health, anOldValue);
}

void UAuraAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& anOldValue) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxHealth, anOldValue);
}

void UAuraAttributeSet::OnRep_Mana(const FGameplayAttributeData& anOldValue) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Mana, anOldValue);
}

void UAuraAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& anOldValue) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxMana, anOldValue);
}
