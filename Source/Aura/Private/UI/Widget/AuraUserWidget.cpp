// Downbeatwolf


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* aWidgetController)
{
    WidgetController = aWidgetController;
    OnWidgetControllerSet();
}
