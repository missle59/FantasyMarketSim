// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ItemActor.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Data/EEquippedTool.h"
#include "Tools/ToolBase.h"
#include "FMPlayerCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class FANTASYMARKETSIM_API AFMPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFMPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(const struct FInputActionValue& Value);
	void Look(const struct FInputActionValue& Value);
	void Interact();
	void UpdateTargetActor();

	UFUNCTION(BlueprintCallable, Category = "Tools")
	void EquipTool(EEquippedTool Tool);

	UFUNCTION(BlueprintCallable, Category = "Tools")
	void UnEquipTool();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Inventory")
	AItemActor* HeldItem;

	UPROPERTY(VisibleAnywhere, Category="Interaction")
	AActor* InteractTarget;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* CameraComponent;

	// Input actions (set via ConstructorHelpers or later data system)
	UPROPERTY()
	UInputAction* MoveAction;

	UPROPERTY()
	UInputAction* LookAction;

	UPROPERTY()
	UInputAction* InteractAction;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY()
	class UUserWidget* HUDWidget;

	class UTextBlock* GoldText;
	class UTextBlock* TimeText;
	class UTextBlock* ShopLevelText;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Tools")
	EEquippedTool EquippedTool = EEquippedTool::None;

	UPROPERTY()
	AToolBase* CurrentToolActor = nullptr;
	
	TMap<EEquippedTool, TSubclassOf<AToolBase>> ToolBaseClassMap;

	UPROPERTY(EditDefaultsOnly, Category = "Tools")
	TSubclassOf<AToolBase> CrateClass;

	UPROPERTY(EditDefaultsOnly, Category = "Tools")
	TSubclassOf<AToolBase> SackClass;

	UPROPERTY(EditDefaultsOnly, Category = "Tools")
	TSubclassOf<AToolBase> HatchetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Tools")
	TSubclassOf<AToolBase> PestleClass;

private:
	UInputMappingContext* DefaultMappingContext;
};
