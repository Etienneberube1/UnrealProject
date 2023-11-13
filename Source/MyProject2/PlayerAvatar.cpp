// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerAvatar.h"
#include "Potion.h"



void APlayerAvatar::Take(UPotion* PotionItem)
{
	if (!PotionItem) return;

	Inventory.Add(PotionItem);
	PotionItem->PlayPickUpSound(GetActorLocation());
}

void APlayerAvatar::UsePotion(UPotion* PotionItem)
{
	if (!PotionItem) return;

	if (PotionItem->Drink(this)) {
		Inventory.Remove(PotionItem);
		PotionItem->PlayHealSound(GetActorLocation());
	}

}
