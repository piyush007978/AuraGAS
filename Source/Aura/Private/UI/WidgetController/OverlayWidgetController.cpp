// Downbeatwolf


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	Super::BroadcastInitialValues();
	const UAuraAttributeSet* auraAttributeSet = CastChecked<const UAuraAttributeSet>(myAttributeSet);
	OnHealthChanged.Broadcast(auraAttributeSet->GetmyHealth());
	OnMaxHealthChanged.Broadcast(auraAttributeSet->GetmyMaxHealth());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* auraAttributeSet = CastChecked<const UAuraAttributeSet>(myAttributeSet);
	myAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	auraAttributeSet->GetmyHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	myAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	auraAttributeSet->GetmyMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}
