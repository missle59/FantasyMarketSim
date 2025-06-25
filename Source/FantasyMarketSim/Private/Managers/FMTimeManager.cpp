// Fill out your copyright notice in the Description page of Project Settings.


#include "FantasyMarketSim/Public/Managers/FMTimeManager.h"


// Sets default values
AFMTimeManager::AFMTimeManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentTime = 0.0f;
}

// Called when the game starts or when spawned
void AFMTimeManager::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("TimeManager has begun!"));
}

void AFMTimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentTime += DeltaTime * 60.0f;
}

FString AFMTimeManager::GetFormattedTime() const
{
	int32 TotalMinutes = FMath::FloorToInt(CurrentTime / 60.0f);
	int32 Hours = (TotalMinutes / 60) % 24;
	int32 Minutes = TotalMinutes % 60;

	return FString::Printf(TEXT("%02d:%02d"), Hours, Minutes);
}
