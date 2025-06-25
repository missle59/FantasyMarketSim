// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FMShopManager.generated.h"

UENUM(BlueprintType)
enum class EShopState : uint8
{
	Prep,
	Open,
	Closed,
	Summary
};

UCLASS()
class FANTASYMARKETSIM_API AFMShopManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFMShopManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool bIsShopOpen;
};
