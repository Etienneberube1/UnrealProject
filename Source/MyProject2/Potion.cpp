// Fill out your copyright notice in the Description page of Project Settings.

#include "Potion.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerAvatar.h"

UPotion::UPotion()
{
	HealingPercent = 0.20f;
	HealAmount = 10.0f;
}

bool UPotion::Drink(APlayerAvatar* avatar)
{
	if (!avatar) return false;

	//if (avatar < 1.0f && !avatar->IsDead()) {
	//	avatar->Heal(HealAmount);
	//	return true;
	//}
	//
	return false;
}

void UPotion::PlayPickUpSound(const FVector& Location)
{
	if (!PickupSound) return;

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), PickupSound, Location);
}
