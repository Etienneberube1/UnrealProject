// Fill out your copyright notice in the Description page of Project Settings.

#include "Potion.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerAvatar.h"

UPotion::UPotion()
{
	HealingPercent = 0.20f;
}

bool UPotion::Drink(APlayerAvatar* avatar)
{
	if (!avatar) return false;

	if (!avatar->IsDead()) {
		avatar->Heal(HealingPercent);
		return true;
	}
	else { return false; }

}

void UPotion::PlayPickUpSound(const FVector& Location)
{
	if (!PickupSound) return;

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), PickupSound, Location);
}

void UPotion::PlayHealSound(const FVector& Location)
{
	if (!HealSound) return;

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), HealSound, Location);
}
