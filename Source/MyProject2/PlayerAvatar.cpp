// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerAvatar.h"
#include "Potion.h"



void APlayerAvatar::Take(UPotion* PotionItem)
{
	if (!PotionItem) return;

	Inventory.Add(PotionItem);
	PotionItem->PlayPickUpSound(GetActorLocation());
}

void APlayerAvatar::UsePotion()
{
	if (Inventory.Num() > 0 && health < maxHealth) {
		UPotion* potion = Inventory[0];
		if (potion->Drink(this)) {
			Inventory.Remove(potion);
		}
	}
}

void APlayerAvatar::Interact()
{
	OnInteractionEvent.Broadcast();
}
