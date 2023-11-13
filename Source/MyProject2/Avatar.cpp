// Fill out your copyright notice in the Description page of Project Settings.


#include "Avatar.h"

// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	health = 0.0f;
	maxHealth = 0.0f;
}

// Called when the game starts or when spawned
void AAvatar::BeginPlay()
{
	Super::BeginPlay();
	

	// put in player
	health = maxHealth ;
	OnHealthChange();

	UE_LOG(LogTemp, Warning, TEXT("IsDead = %s"), (IsDead() ? TEXT("True": TEXT("False"))));

}

float AAvatar::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (!IsDead()) {
		health = FMath::RoundToInt32(health - Damage);
		if (health <= 0.0f) {
			UAnimInstance* anim = GetMesh()->GetAnimInstance();
			if (anim) {
				if (DeathMontage) {
					anim->Montage_Play(DeathMontage);
				}
			}
			health = 0.0f;
		}
		OnHealthChange();
	}
	return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}

void AAvatar::Heal(float healAmount)
{
	health += healAmount * 100.0f;
	if (health > maxHealth) {
		health = maxHealth;
		OnHealthChange();
	}
	OnHealthChange();
}

float AAvatar::GetPourcentHealth() const
{
	if (maxHealth <= 0.0f)
	{
		return 0.0f;
	}
	return health / maxHealth;
}

// Called every frame
void AAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AAvatar::IsDead() const
{
	if (health <= 0) {
		return true;
	}

	return false;
}
