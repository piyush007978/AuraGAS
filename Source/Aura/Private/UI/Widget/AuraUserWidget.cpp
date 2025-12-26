// Downbeatwolf


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* aWidgetController)
{
    myWidgetController = aWidgetController;
    OnWidgetControllerSet();
}
