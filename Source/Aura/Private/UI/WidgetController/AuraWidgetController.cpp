// Downbeatwolf


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& Params)
{
	myPlayerState = Params.PlayerState;
	myPlayerController = Params.PlayerController;
	myAbilitySystemComponent = Params.AbilitySystemComponent;
	myAttributeSet = Params.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValues()
{
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
}
