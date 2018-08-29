// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MOGGameModeBase.h"
#include "MOGGameStructs.h"
#include "MOGTable.generated.h"

UCLASS()
class MOG_API AMOGTable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMOGTable();

    UFUNCTION(BlueprintImplementableEvent, Category = Placing)
    FTransform GetStockPlace();

    UFUNCTION(BlueprintImplementableEvent, Category = Placing)
    FTransform GetPlayerCardPlace(uint8 PlayerNum, ECardSuit CardSuit);

    UFUNCTION(BlueprintImplementableEvent, Category = Placing)
    FTransform GetNeutralCardPlace(ECardSuit CardSuit);

    UFUNCTION(BlueprintImplementableEvent, Category = Placing)
    FTransform GetCardPlace(ECardSuit CardSuit, EPlayerNum FieldType);

    UFUNCTION(BlueprintCallable, Category = Placing)
    void OnStockClicked();

    UFUNCTION(BlueprintCallable, Category = Placing)
    void OnCardFieldClicked(bool bIsNeutral, ECardSuit Suit, uint8 PlayerNum);

    UFUNCTION(BlueprintCallable, Category = Placing)
    void OnPlayFieldClicked(ECardSuit Suit, EPlayerNum Field);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
