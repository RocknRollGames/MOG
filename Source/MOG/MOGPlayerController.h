// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MOGCard.h"
#include "MOGGameModeBase.h"
#include "MOGPlayerController.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogMogPlayerController, All, All)

UCLASS()
class MOG_API AMOGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    
    UFUNCTION(Server, Reliable, WithValidation)
    void Server_MoveCard(AMOGCard* Card);
    void Server_MoveCard_Implementation(AMOGCard* Card);
    bool Server_MoveCard_Validate(AMOGCard* Card);

    UFUNCTION(BlueprintCallable, Category = Game)
    bool IsValidTurn();

    UFUNCTION(Server, Reliable, WithValidation)
    void Server_StockTouched();
    void Server_StockTouched_Implementation();
    bool Server_StockTouched_Validate();

    UFUNCTION(Server, Reliable, WithValidation)
    void Server_CardTouched();
    void Server_CardTouched_Implementation();
    bool Server_CardTouched_Validate();
};
