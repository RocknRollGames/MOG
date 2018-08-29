
#pragma once

#include "CoreMinimal.h"
#include "MOGGameStructs.generated.h"

UENUM(BlueprintType)
enum class EPlayerNum : uint8
{
    PN_First UMETA(DisplayName = "First"),
    PN_Second UMETA(DisplayName = "Second"),
    PN_Neutral UMETA(DisplayName = "Neutral")
};