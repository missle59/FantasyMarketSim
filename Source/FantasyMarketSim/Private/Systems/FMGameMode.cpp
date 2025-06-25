// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/FMGameMode.h"
#include "Player/FMPlayerCharacter.h"
#include "Managers/FMTimeManager.h"
#include "Managers/FMShopManager.h"

AFMGameMode::AFMGameMode()
{
	DefaultPawnClass = AFMPlayerCharacter::StaticClass();
}

void AFMGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Spawn TimeManager
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	TimeManager = GetWorld()->SpawnActor<AFMTimeManager>(AFMTimeManager::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);

	FActorSpawnParameters ShopSpawnParams;
	ShopSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ShopManager = GetWorld()->SpawnActor<AFMShopManager>(AFMShopManager::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, ShopSpawnParams);
}
