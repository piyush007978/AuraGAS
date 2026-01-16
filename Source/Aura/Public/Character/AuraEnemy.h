// Downbeatwolf

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interface/ActorHoverInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IActorHoverInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();
	void HighlightActor() override;
	void UnHighlightActor() override;
	void PossessedBy(AController* NewController) override;
	int32 GetCharacterLevel() const override;
protected:
	virtual void BeginPlay() override;
	void InitAbilityActorInfo() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	TObjectPtr<class AAuraAIController> AuraAIController;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	TObjectPtr<class UBehaviorTree> BehaviorTree;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy Class Defaults")
	int32 Level = 1;
};
