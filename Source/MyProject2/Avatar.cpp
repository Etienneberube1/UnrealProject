// Fill out your copyright notice in the Description page of Project Settings.


#include "Avatar.h"
#include "Weapon.h"
#include "Engine/SkeletalMeshSocket.h"

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
	health = maxHealth;
	OnHealthChange();

	if (StartingWeaponClass) {
		UWorld* World = GetWorld();
		CurrentWeapon = World->SpawnActor<AWeapon>(StartingWeaponClass);

		USkeletalMeshComponent* sm = GetMesh();

		if (sm) {
			const USkeletalMeshSocket* Socket = sm->GetSocketByName(FName("RightHandSocket"));
			if (Socket) {
				Socket->AttachActor(CurrentWeapon, sm);
			}
		}
	}
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

void AAvatar::BeginAttack()
{
	if (CurrentWeapon) {
		CurrentWeapon->BeginDamage(this);
	}
}

void AAvatar::EndAttack()
{
	if (CurrentWeapon) {
		CurrentWeapon->EndDamage();
	}

}

void AAvatar::NormalAttack()
{
	if (AttackMontage) {
		UAnimInstance* anim = GetMesh()->GetAnimInstance();
		if (anim) {
			if (DeathMontage) {
				anim->Montage_Play(AttackMontage);
				anim->Montage_JumpToSection(FName("Normal"));
			}
		}
	}
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
