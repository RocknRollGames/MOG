// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "MOGWorldSettings.generated.h"

class APlayerStart;

/**
 * 
 */
UCLASS()
class MOG_API AMOGWorldSettings : public AWorldSettings
{
    GENERATED_BODY()

public:

    UPROPERTY(EditDefaultsOnly, Category = Spawn)
    AActor* FirstPlayerSpawn;
    
    UPROPERTY(EditDefaultsOnly, Category = Spawn)
    AActor* SecondPlayerSpawn;
	
};
