// Fill out your copyright notice in the Description page of Project Settings.

#include "MOGTable.h"
#include "MOGGameModeBase.h"
#include "MOGPlayerController.h"


// Sets default values
AMOGTable::AMOGTable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMOGTable::OnStockClicked()
{
    if (AMOGPlayerController* PC = CastChecked<AMOGPlayerController>(GetWorld()->GetFirstPlayerController()))
    {
        PC->Server_StockTouched();
    }
}

void AMOGTable::OnCardFieldClicked( bool bIsNeutral, ECardSuit Suit, uint8 PlayerNum)
{

}


void AMOGTable::OnPlayFieldClicked(ECardSuit Suit, EPlayerNum Field)
{
 
}


// Called when the game starts or when spawned
void AMOGTable::BeginPlay()
{
	Super::BeginPlay();
    if (AMOGGameModeBase* GameMode = GetWorld()->GetAuthGameMode<AMOGGameModeBase>())
    {
        GameMode->SetTable(this);
    }
}

// Called every frame
void AMOGTable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

