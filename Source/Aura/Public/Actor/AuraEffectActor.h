// Downbeatwolf

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

UENUM(BlueprintType)
enum class EEffectType : uint8
{
	HealthBoost		UMETA(DisplayName = "HealthBoost"),
	HealthBuff		UMETA(DisplayName = "HealthBuff"),
	ManaBoost		UMETA(DisplayName = "ManaBoost"),
	ManaBuff		UMETA(DisplayName = "ManaBuff")
};

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
public:
	AAuraEffectActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
								UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
								bool bFromSweep, const FHitResult& Hit);
	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
							UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	UPROPERTY(EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USphereComponent> SphereComponent;
	UPROPERTY(EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UStaticMeshComponent> StaticMeshComponent;
	UPROPERTY(EditAnywhere, Category = "Effect", meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<EEffectType> EffectType = EEffectType::HealthBoost;
};
