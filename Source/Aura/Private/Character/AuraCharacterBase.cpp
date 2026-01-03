// Downbeatwolf


#include "Character/AuraCharacterBase.h"
#include "AbilitySystemComponent.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();	
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
}

void AAuraCharacterBase::InitializeAttributesFromEffect(TSubclassOf<UGameplayEffect> EffectClass, float Level) const
{
	checkf(IsValid(AbilitySystemComponent), TEXT("AbilitySystemComponent is not valid"));
	checkf(IsValid(EffectClass), TEXT("EffectClass is not valid"));
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(EffectClass, Level, GetAbilitySystemComponent()->MakeEffectContext());
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(
		*SpecHandle.Data,
		GetAbilitySystemComponent());
}

void AAuraCharacterBase::IntializeDefaultAttributes() const
{
	InitializeAttributesFromEffect(DefaultPrimaryAttributes);
	InitializeAttributesFromEffect(DefaultSecondaryAttributes);
}

