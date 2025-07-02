// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/FMGameMode.h"

#include "Managers/FMTimeManager.h"
#include "Managers/FMShopManager.h"

AFMGameMode::AFMGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Player/BP_FMPlayerCharacter.BP_FMPlayerCharacter_C"));
	if (PlayerPawnBPClass.Succeeded())
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find BP_FMPlayerCharacter. Check your path."));
	}
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
