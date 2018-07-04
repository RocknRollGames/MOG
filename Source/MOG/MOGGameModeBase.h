// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MOGCard.h"
#include "MOGGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MOG_API AMOGGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

private:

	void CreateCards();
	
	void ShuffleCards();

	UPROPERTY()
	TArray<AMOGCard*> CardsOnATable;

	UPROPERTY(EditDefaultsOnly, Category = Cards)
	TSubclassOf<AMOGCard> CardClass;
};
