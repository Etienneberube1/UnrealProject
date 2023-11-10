// Fill out your copyright notice in the Description page of Project Settings.


#include "FristActor.h"

// Sets default values
AFristActor::AFristActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Speed = 100;
}

// Called when the game starts or when spawned
void AFristActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFristActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += GetActorForwardVector() * Speed * DeltaTime;
	SetActorLocation(CurrentLocation);
}

