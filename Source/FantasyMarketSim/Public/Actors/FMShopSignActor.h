// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "FMShopSignActor.generated.h"

UCLASS()
class FANTASYMARKETSIM_API AFMShopSignActor : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFMShopSignActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation(AActor* Interactor) override;

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
};
