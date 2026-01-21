// Fill out your copyright notice in the Description page of Project Settings.


#include "Tools/ToolBase.h"


// Sets default values
AToolBase::AToolBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ToolMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ToolMesh"));
	RootComponent = ToolMesh;
}

// Called when the game starts or when spawned
void AToolBase::BeginPlay()
{
	Super::BeginPlay();
	
}
