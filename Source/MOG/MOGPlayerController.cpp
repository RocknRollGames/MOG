// Fill out your copyright notice in the Description page of Project Settings.

#include "MOGPlayerController.h"



bool AMOGPlayerController::Server_MoveCard_Validate(AMOGCard* Card)
{
    AMOGGameModeBase* GameMode = GetWorld()->GetAuthGameMode<AMOGGameModeBase>();

    return GameMode->GetCurrentTurnController() == this;
}

void AMOGPlayerController::Server_MoveCard_Implementation(AMOGCard* Card)
{

}
