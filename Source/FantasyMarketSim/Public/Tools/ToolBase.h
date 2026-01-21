// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ToolBase.generated.h"

UCLASS()
class FANTASYMARKETSIM_API AToolBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AToolBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UStaticMeshComponent* ToolMesh;
};
