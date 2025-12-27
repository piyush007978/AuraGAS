// Downbeatwolf


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	Super::BroadcastInitialValues();
	const UAuraAttributeSet* auraAttributeSet = CastChecked<const UAuraAttributeSet>(myAttributeSet);
	OnHealthChanged.Broadcast(auraAttributeSet->GetmyHealth());
	OnMaxHealthChanged.Broadcast(auraAttributeSet->GetmyMaxHealth());
	OnManaChanged.Broadcast(auraAttributeSet->GetmyMana());
	OnMaxManaChanged.Broadcast(auraAttributeSet->GetmyMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* auraAttributeSet = CastChecked<const UAuraAttributeSet>(myAttributeSet);
	myAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	auraAttributeSet->GetmyHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	myAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	auraAttributeSet->GetmyMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	myAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	auraAttributeSet->GetmyManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
	myAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	auraAttributeSet->GetmyMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
