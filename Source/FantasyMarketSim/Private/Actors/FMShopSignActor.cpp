// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FMShopSignActor.h"
#include "Components/StaticMeshComponent.h"
#include "Managers/FMShopManager.h"


// Sets default values
AFMShopSignActor::AFMShopSignActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	PostMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PostMesh"));
	PostMesh->SetupAttachment(Root);

	SignMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SignMesh"));
	SignMesh->SetupAttachment(PostMesh);
}

// Called when the game starts or when spawned
void AFMShopSignActor::BeginPlay()
{
	Super::BeginPlay();
	
}

