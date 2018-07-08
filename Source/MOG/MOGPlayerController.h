// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MOGCard.h"
#include "MOGGameModeBase.h"
#include "MOGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MOG_API AMOGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

    UFUNCTION(Server, Reliable, WithValidation)
    void Server_MoveCard(AMOGCard* Card);
	
	
};
