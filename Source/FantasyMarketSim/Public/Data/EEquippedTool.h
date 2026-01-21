#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EEquippedTool : uint8
{
	None UMETA(DisplayName = "None"),
	Crate UMETA(DisplayName = "Crate"),
	Sack UMETA(DisplayName = "Sack"),
	Hatchet UMETA(DisplayName = "Hatchet"),
	Pestle UMETA(DisplayName = "Pestle")
};
