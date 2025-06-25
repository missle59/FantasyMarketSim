// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FMGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FANTASYMARKETSIM_API AFMGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFMGameMode();

protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY()
	class AFMTimeManager* TimeManager;

	UPROPERTY()
	class AFMShopManager* ShopManager;
};
