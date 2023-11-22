// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Avatar.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// adding component
	SceneRoot = CreateDefaultSubobject<USceneComponent>(FName("SceneRoot"));
	SetRootComponent(SceneRoot);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("WeaponMesh"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponMesh->SetupAttachment(SceneRoot);
}


// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	IsAttacking = false;
}

void AWeapon::BeginDamage(AAvatar* WeaponOwner)
{
	IsAttacking = true;
	IgnoredActors.Empty();
	IgnoredActors.Add(WeaponOwner);
}

void AWeapon::EndDamage()
{
	IsAttacking = false;

	// clearing list
	IgnoredActors.Empty();
}

void AWeapon::OnActorDamage(AActor* other)
{
	if (!IsAttacking) return;

	if (other) {
		if (!IgnoredActors.Contains(other)) {

			// apply damage
			UGameplayStatics::ApplyDamage(other, Damage, nullptr, this, UDamageType::StaticClass());
			IgnoredActors.Add(other);
		}
	}
}



