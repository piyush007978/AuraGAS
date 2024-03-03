// Downbeatwolf


#include "Character/AuraCharacterBase.h"

// Sets default values
AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	myWeapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	myWeapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	myWeapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

