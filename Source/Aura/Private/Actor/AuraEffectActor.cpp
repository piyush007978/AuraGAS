// Downbeatwolf


#include "Actor/AuraEffectActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraEffectActor::AAuraEffectActor()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SetRootComponent(StaticMeshComponent);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(RootComponent);
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnSphereBeginOverlap);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectActor::OnSphereEndOverlap);
}

void AAuraEffectActor::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent,
						AActor* OtherActor, UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	if(IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		if(const UAuraAttributeSet* attributeSet = Cast<UAuraAttributeSet>(AbilitySystemInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass())))
		{
			// TODO: using a const cast is already an indication that this is a HACK and should be fixed properly later. Use gameplay effects to modify attributes.
			UAuraAttributeSet* mutableAttributeSet = const_cast<UAuraAttributeSet*>(attributeSet);
			float currentHealth = attributeSet->GetmyHealth();
			mutableAttributeSet->SetmyHealth(currentHealth + 15.f);
			Destroy();
		}
	}
}

void AAuraEffectActor::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent,
						AActor* OtherActor, UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex)
{
	// Handle the end overlap event
}
