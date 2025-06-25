// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FMTimeManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDayEnded);

UCLASS()
class FANTASYMARKETSIM_API AFMTimeManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFMTimeManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Time")
	float GetCurrentTime() const { return CurrentTime; }

	UFUNCTION(BlueprintCallable, Category = "Time")
	FString GetFormattedTime() const;

private:
	float CurrentTime;
};
