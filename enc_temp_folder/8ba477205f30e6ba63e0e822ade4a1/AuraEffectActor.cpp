// Downbeatwolf


#include "Actor/AuraEffectActor.h"

AAuraEffectActor::AAuraEffectActor()
{
 	
	PrimaryActorTick.bCanEverTick = false;

}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}
