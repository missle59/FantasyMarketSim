// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/FMPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "DrawDebugHelpers.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Interfaces/Interactable.h"

// Sets default values
AFMPlayerCharacter::AFMPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 64.0f));
	CameraComponent->bUsePawnControlRotation = true;

	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	HeldItem = nullptr;

	static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputMappingAsset(TEXT("/Game/Input/IMC_Default.IMC_Default"));
	if (InputMappingAsset.Succeeded())
	{
		DefaultMappingContext = InputMappingAsset.Object;
	}
	
	static ConstructorHelpers::FObjectFinder<UInputAction> MoveActionAsset(TEXT("/Game/Input/IA_Move.IA_Move"));
	if (MoveActionAsset.Succeeded())
	{
		MoveAction = MoveActionAsset.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> LookActionAsset(TEXT("/Game/Input/IA_Look.IA_Look"));
	if (LookActionAsset.Succeeded())
	{
		LookAction = LookActionAsset.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> InteractActionAsset(TEXT("/Game/Input/IA_Interact.IA_Interact"));
	if (InteractActionAsset.Succeeded())
	{
		InteractAction = InteractActionAsset.Object;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> HUDWidgetBPClass(TEXT("/Game/Blueprints/UI/WBP_HUD.WBP_HUD_C"));
	if (HUDWidgetBPClass.Succeeded())
	{
		HUDWidgetClass = HUDWidgetBPClass.Class;
	}
}

// Called when the game starts or when spawned
void AFMPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Ensure a controller exists and is a player controller
	if (APlayerController* PC = Cast<APlayerController>(Controller))
	{
		// Get the LocalPlayer (required for an Enhanced Input subsystem)
		if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
		{
			// Access the Enhanced Input Subsystem and apply the mapping
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}

	if (HUDWidgetClass)
	{
		HUDWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (HUDWidget)
		{
			HUDWidget->AddToViewport();
		}
	}

	if (HUDWidget)
	{
		GoldText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("GoldText")));
		TimeText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("TimeText")));
		ShopLevelText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("ShopLevelText")));

		if (GoldText)
		{
			GoldText->SetText(FText::FromString(TEXT("Gold: 100")));
		}
		if (TimeText)
		{
			TimeText->SetText(FText::FromString(TEXT("Time: 08:00 AM")));
		}
		if (ShopLevelText)
		{
			ShopLevelText->SetText(FText::FromString(TEXT("Shop Level: 1")));
		}
	}

}

// Called every frame
void AFMPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateTargetActor();
}

// Called to bind functionality to input
void AFMPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)
		{
			EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFMPlayerCharacter::Move);
		}

		if (LookAction)
		{
			EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFMPlayerCharacter::Look);
		}

		if (InteractAction)
		{
			EnhancedInput->BindAction(InteractAction, ETriggerEvent::Started, this, &AFMPlayerCharacter::Interact);
		}
	}
}

void AFMPlayerCharacter::Move(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector(), Input.Y);
	AddMovementInput(GetActorRightVector(), Input.X);
}

void AFMPlayerCharacter::Look(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();
	AddControllerYawInput(Input.X);
	AddControllerPitchInput(Input.Y);
}

void AFMPlayerCharacter::Interact()
{
	if (InteractTarget)
	{
		IInteractable::Execute_Interact(InteractTarget, this);
	}
}

void AFMPlayerCharacter::UpdateTargetActor()
{
	const FVector Start = CameraComponent->GetComponentLocation();
	const FVector End = Start + (CameraComponent->GetForwardVector() * 300.0f);

	FHitResult HitResult;
	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(this); // Ignore self

	// Perform the line trace
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, TraceParams))
	{
		AActor* HitActor = HitResult.GetActor();
		if (HitActor != InteractTarget)
		{
			if (InteractTarget && InteractTarget->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
			{
				IInteractable::Execute_OnFocusLost(InteractTarget);
			}

			if (HitActor && HitActor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
			{
				IInteractable::Execute_OnFocusGained(HitActor);
				InteractTarget = HitActor;

				UE_LOG(LogTemp, Log, TEXT("Now looking at: %s"), *HitActor->GetName());
			}
			else
			{
				InteractTarget = nullptr;
			}
		}
	}
	else
	{
		// Only clear if something was previously set
		if (InteractTarget)
		{
			if (InteractTarget->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
			{
				IInteractable::Execute_OnFocusLost(InteractTarget);
			}
			InteractTarget = nullptr;
			UE_LOG(LogTemp, Log, TEXT("No interactable in view"));
		}
	}
}
