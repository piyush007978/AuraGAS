// Downbeatwolf


#include "Character/AuraEnemy.h"
#include "Aura/Aura.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

void AAuraEnemy::BeginPlay()
{
    Super::BeginPlay();
    myAbilitySystemComponent->InitAbilityActorInfo(this, this);
}

AAuraEnemy::AAuraEnemy()
{
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    GetCharacterMovement()->bConstrainToPlane = true;
    GetCharacterMovement()->bSnapToPlaneAtStart = true;
    myAbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
    myAbilitySystemComponent->SetIsReplicated(true);
    myAbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
    myAttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemy::HighlightActor()
{
    GetMesh()->SetRenderCustomDepth(true);
    GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
    myWeapon->SetRenderCustomDepth(true);
    myWeapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnHighlightActor()
{
    GetMesh()->SetRenderCustomDepth(false);
    myWeapon->SetRenderCustomDepth(false);
}
