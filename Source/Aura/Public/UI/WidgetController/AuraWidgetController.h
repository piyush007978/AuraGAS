// Downbeatwolf

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AuraWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerState> myPlayerState;
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerController> myPlayerController;
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<class UAbilitySystemComponent> myAbilitySystemComponent;
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<class UAttributeSet> myAttributeSet;
	
};
