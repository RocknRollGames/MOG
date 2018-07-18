// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MOGCard.h"
#include "MOGTable.h"
#include "MOGGameModeBase.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogMOGGameMode, Log, All)

UCLASS()
class MOG_API AMOGGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
    
public:

    virtual void PostLogin(APlayerController* NewPlayer) override;


    void SetTable(AMOGTable* InTable);

    UFUNCTION(BlueprintCallable, Category = Cards)
    uint8 GetNumberOfStockCards();

    UFUNCTION(BlueprintCallable, Category = Cards)
    uint8 GetNumberOfPlayerCardsOnTable(uint8 PlayerNum, ECardSuit Suit);

    UFUNCTION(BlueprintCallable, Category = Cards)
    uint8 GetNumberOfNeutralCardsOnTable(ECardSuit Suit);

    void MoveCardToTheTable(AMOGCard* Card);

    AMOGPlayerController* GetCurrentTurnController();

    //virtual AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName) override;


    void EndTurn();

private:

    AMOGPlayerController* FirstPlayerController;
    AMOGPlayerController* SecondPlayerController;

	void CreateCards();	
	void ShuffleCards();

	UPROPERTY()
	TArray<AMOGCard*> AllCards;

    UPROPERTY()
    TArray<AMOGCard*> StockCards;

	UPROPERTY(EditDefaultsOnly, Category = Cards)
	TSubclassOf<AMOGCard> CardClass;

    UPROPERTY()
    TArray<AMOGCard*> Player1Cards;

    UPROPERTY()
    TArray<AMOGCard*> Player2Cards;

    UPROPERTY()
    TArray<AMOGCard*> Player1CardsOnTable;

    UPROPERTY()
    TArray<AMOGCard*> Player2CardsOnTable;
    
    UPROPERTY()
    TArray<AMOGCard*> NeutralCards;

    UPROPERTY()
    AMOGTable* Table;

    UPROPERTY()
    uint8 Turn = 1;

    void MoveCardsToTheStock();

};
