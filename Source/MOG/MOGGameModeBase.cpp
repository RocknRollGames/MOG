// Fill out your copyright notice in the Description page of Project Settings.

#include "MOGGameModeBase.h"
#include "CardComponents/MOGCardComponent.h"
#include "GameFramework/Actor.h"
#include <Engine/World.h>
#include "MOGPlayerController.h"
#include "MOGWorldSettings.h"

DEFINE_LOG_CATEGORY(LogMOGGameMode);

void AMOGGameModeBase::BeginPlay()
{
	Super::BeginPlay();
    CreateCards();
    ShuffleCards();
    if (Table)
    {
        MoveCardsToTheStock();
    }
}

APlayerController* AMOGGameModeBase::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
    APlayerController* PC = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
    if (!FirstPlayerController)
    {
        FirstPlayerController = CastChecked<AMOGPlayerController>(PC);
        return PC;
    }
    if (!SecondPlayerController)
    {
        SecondPlayerController = CastChecked<AMOGPlayerController>(PC);
        return PC;
    }
    UE_LOG(LogMOGGameMode, Error, TEXT("Cant register %s, both places are occupied!"), *UniqueId->ToString());
    return nullptr;
}

void AMOGGameModeBase::SetTable(AMOGTable* InTable)
{
    Table = InTable;
    if (HasActorBegunPlay())
    {
        MoveCardsToTheStock();
    }
}

void AMOGGameModeBase::CreateCards()
{
	for ( uint8 suit = (uint8)ECardSuit::CS_Weapon; suit <= (uint8)ECardSuit::CS_Building_Materials; suit++ )
	{
		for (uint8 value = 0; value < 10; value++)
		{
            FActorSpawnParameters SpawnInfo;
            SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
            FTransform SpawnTransform;
            AMOGCard* NewCard = CastChecked<AMOGCard>(GetWorld()->SpawnActor(CardClass, &SpawnTransform, SpawnInfo));

            FCardInfo CardInfo((ECardSuit)suit, value);

            NewCard->InitCard(CardInfo);

			AllCards.Push(NewCard);
		}
	}
}

void AMOGGameModeBase::ShuffleCards()
{

}

uint8 AMOGGameModeBase::GetNumberOfStockCards()
{
    return StockCards.Num();
}

uint8 AMOGGameModeBase::GetNumberOfPlayerCardsOnTable(uint8 PlayerNum, ECardSuit Suit)
{
    TArray<AMOGCard*> PlayerCardsOnTable = PlayerNum == 1 ? Player1Cards : Player2Cards;

    uint8 Counter = 0;
    for (AMOGCard* Card : PlayerCardsOnTable)
    {
        if (Card->GetCardInfo().CardSuit == Suit)
        {
            Counter++;
        }
    }
    return Counter;
}

uint8 AMOGGameModeBase::GetNumberOfNeutralCardsOnTable(ECardSuit Suit)
{
    uint8 Counter = 0;
    for (AMOGCard* Card : NeutralCards)
    {
        if (Card->GetCardInfo().CardSuit == Suit)
        {
            Counter++;
        }
    }
    return Counter;
}

void AMOGGameModeBase::MoveCardsToTheStock()
{
    for (AMOGCard* Card : AllCards)
    {
        FTransform NewTransform = Table->GetStockPlace();
        Card->SetActorTransform(NewTransform);
        StockCards.Add(Card);
    }
}

void AMOGGameModeBase::MoveCardToTheTable(AMOGCard* Card)
{

}

AMOGPlayerController* AMOGGameModeBase::GetCurrentTurnController()
{
    return Turn == 1 ? FirstPlayerController : SecondPlayerController;
}

AActor* AMOGGameModeBase::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
{
    AMOGWorldSettings* WorldSettings = CastChecked<AMOGWorldSettings>(GetWorld()->GetWorldSettings());
    if (FirstPlayerController != nullptr && !FirstPlayerController->GetPawn())
    {
        return WorldSettings->FirstPlayerSpawn;
    }
    else
    {
        return WorldSettings->SecondPlayerSpawn;
    }
    //return Super::FindPlayerStart_Implementation(Player, IncomingName);
}

void AMOGGameModeBase::EndTurn()
{
    Turn = Turn == 1 ? 2 : 1;
}
