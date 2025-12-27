// Downbeatwolf

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AuraWidgetController.generated.h"

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	
	GENERATED_BODY()

public:
	FWidgetControllerParams() = default;
	FWidgetControllerParams(APlayerState* InPlayerState,
							APlayerController* InPlayerController,
							class UAbilitySystemComponent* InAbilitySystemComponent,
							class UAttributeSet* InAttributeSet)
		: PlayerState(InPlayerState)
		, PlayerController(InPlayerController)
		, AbilitySystemComponent(InAbilitySystemComponent)
		, AttributeSet(InAttributeSet)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetControllerParams")
	TObjectPtr<APlayerState> PlayerState = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetControllerParams")
	TObjectPtr<APlayerController> PlayerController = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetControllerParams")
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetControllerParams")
	TObjectPtr<class UAttributeSet> AttributeSet = nullptr;
};

/**
 * 
 */
UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "WidgetController")
	void SetWidgetControllerParams(const FWidgetControllerParams& Params);
	virtual void BroadcastInitialValues();
	virtual void BindCallbacksToDependencies();
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
