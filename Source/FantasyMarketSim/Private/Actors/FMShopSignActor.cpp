// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FMShopSignActor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Managers/FMShopManager.h"
#include "EngineUtils.h"

// Sets default values
AFMShopSignActor::AFMShopSignActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void AFMShopSignActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFMShopSignActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFMShopSignActor::Interact_Implementation(AActor* Interactor)
{
	for (TActorIterator<AFMShopManager> It(GetWorld()); It; ++It)
	{
		AFMShopManager* ShopManager = *It;
		if (ShopManager)
		{
			ShopManager->ToggleShopOpen();
			return; // Done after first manager
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("FMShopSignActor: No shop manager found to toggle shop state."));
}
