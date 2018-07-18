// Fill out your copyright notice in the Description page of Project Settings.

#include "MOGPlayerController.h"

DEFINE_LOG_CATEGORY(LogMogPlayerController)

bool AMOGPlayerController::IsValidTurn()
{
    AMOGGameModeBase* GameMode = GetWorld()->GetAuthGameMode<AMOGGameModeBase>();
    return GameMode->GetCurrentTurnController() == this;
}

void AMOGPlayerController::Server_MoveCard_Implementation(AMOGCard* Card)
{

}

void AMOGPlayerController::Server_CardTouched_Implementation()
{

}

void AMOGPlayerController::Server_StockTouched_Implementation()
{
    if (IsValidTurn())
    {
        UE_LOG(LogMogPlayerController, Display, TEXT("%s touched stock"), *this->GetName());
    }
}

bool AMOGPlayerController::Server_MoveCard_Validate(AMOGCard* Card)
{
    return true;
}

bool AMOGPlayerController::Server_StockTouched_Validate()
{
    return true;
}

bool AMOGPlayerController::Server_CardTouched_Validate()
{
    return true;
}
