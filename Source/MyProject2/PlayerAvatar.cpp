// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerAvatar.h"
#include "Potion.h"



void APlayerAvatar::Take(UPotion* PotionItem)
{
	if (!PotionItem) return;

	Inventory.Add(PotionItem);
	PotionItem->PlayPickUpSound(GetActorLocation());
}
