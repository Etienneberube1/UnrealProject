// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionBase.h"
#include "PlayerAvatar.h"

// Sets default values
AInteractionBase::AInteractionBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AInteractionBase::OnEnterInteractionZone(APlayerAvatar* other)
{
	if (!other) return;

	other->OnInteractionEvent.AddDynamic(this, &AInteractionBase::OnInteractActivated);
}

void AInteractionBase::OnExitInteractionZone(APlayerAvatar* other)
{
	if (!other) return;

	other->OnInteractionEvent.RemoveAll(this);

}

void AInteractionBase::OnInteractActivated()
{
	Activate();
}




