// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
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

private:
	UInputMappingContext* DefaultMappingContext;
};
