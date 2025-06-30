// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/FMShopManager.h"

// Sets default values
AFMShopManager::AFMShopManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bIsShopOpen = false;
}

// Called when the game starts or when spawned
void AFMShopManager::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("ShopManager: Shop is %s"),
	bIsShopOpen ? TEXT("Open") : TEXT("Closed"));
}

// Called every frame
void AFMShopManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFMShopManager::ToggleShopOpen()
{
	bIsShopOpen = !bIsShopOpen;

	if (bIsShopOpen)
	{
		UE_LOG(LogTemp, Warning, TEXT("FMShopManager: The shop is now OPEN."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FMShopManager: The shop is now CLOSED."));
	}
}
