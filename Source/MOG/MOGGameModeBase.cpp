// Fill out your copyright notice in the Description page of Project Settings.

#include "MOGGameModeBase.h"
#include "CardComponents/MOGCardComponent.h"
#include "GameFramework/Actor.h"
#include <Engine/World.h>

void AMOGGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	CreateCards();
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

			CardsOnATable.Push(NewCard);
		}
	}
}

void AMOGGameModeBase::ShuffleCards()
{

}
