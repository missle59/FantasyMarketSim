// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Managers/FMShopManager.h"
#include "FMShopSignActor.generated.h"

UCLASS()
class FANTASYMARKETSIM_API AFMShopSignActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFMShopSignActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shop")
	AFMShopManager* ShopManager;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PostMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SignMesh;

	UPROPERTY(EditAnywhere, Category = "Shop")
	FRotator ClosedRotation;

	UPROPERTY(EditAnywhere, Category = "Shop")
	FRotator OpenRotation;

	UPROPERTY(EditAnywhere, Category = "Shop")
	bool bIsOpen = false;

private:
	void RotateSign();
};
