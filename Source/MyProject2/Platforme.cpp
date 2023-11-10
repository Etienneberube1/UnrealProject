// Fill out your copyright notice in the Description page of Project Settings.


#include "Platforme.h"

// Sets default values
APlatforme::APlatforme()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	isPaused = false;
	maxDistance = 100.0f;
	speedVector = FVector(0.0f, 0.0f, 0.0f);
}

// Called when the game starts or when spawned
void APlatforme::BeginPlay()
{
	Super::BeginPlay();
	
	currentLocation = GetActorLocation();

}

// Called every frame
void APlatforme::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!isPaused) {
		SetActorLocation(GetActorLocation() + speedVector * DeltaTime);
	}
}

