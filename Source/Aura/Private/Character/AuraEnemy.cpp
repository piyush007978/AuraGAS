// Downbeatwolf


#include "Character/AuraEnemy.h"
#include "Aura/Aura.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

void AAuraEnemy::BeginPlay()
{
    Super::BeginPlay();
    AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

AAuraEnemy::AAuraEnemy()
{
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    GetCharacterMovement()->bConstrainToPlane = true;
    GetCharacterMovement()->bSnapToPlaneAtStart = true;
    AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
    AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemy::HighlightActor()
{
    GetMesh()->SetRenderCustomDepth(true);
    GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
    Weapon->SetRenderCustomDepth(true);
    Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnHighlightActor()
{
    GetMesh()->SetRenderCustomDepth(false);
    Weapon->SetRenderCustomDepth(false);
}
