// Downbeatwolf


#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& Params)
{
	if(OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(Params);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* InPlayerController, APlayerState* InPlayerState, UAbilitySystemComponent* InAbilitySystemComponent, UAttributeSet* InAttributeSet)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is not set in AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass is not set in AuraHUD"));

	UUserWidget* widget = CreateWidget<UUserWidget>(InPlayerController, OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(widget);
	FWidgetControllerParams params(InPlayerState, InPlayerController, InAbilitySystemComponent, InAttributeSet);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(params);
	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	widget->AddToViewport();
}
