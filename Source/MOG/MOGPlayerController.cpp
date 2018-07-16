// Fill out your copyright notice in the Description page of Project Settings.

#include "MOGPlayerController.h"

DEFINE_LOG_CATEGORY(LogMogPlayerController)

bool AMOGPlayerController::IsValidTurn()
{
    AMOGGameModeBase* GameMode = GetWorld()->GetAuthGameMode<AMOGGameModeBase>();
    return GameMode->GetCurrentTurnController() == this;
}

bool AMOGPlayerController::Server_MoveCard_Validate(AMOGCard* Card)
{
    return true;
}

void AMOGPlayerController::Server_MoveCard_Implementation(AMOGCard* Card)
{

}

bool AMOGPlayerController::Server_StockTouched_Validate()
{
    return true;
}

void AMOGPlayerController::Server_StockTouched_Implementation()
{
    if (IsValidTurn())
    {
        UE_LOG(LogMogPlayerController, Display, TEXT("%s touched stock"), *this->GetName());
    }
}
