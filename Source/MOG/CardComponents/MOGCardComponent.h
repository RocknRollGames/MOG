// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MOGCardComponent.generated.h"

UENUM(BlueprintType)
enum class ECardSuit : uint8
{
	CS_Weapon             UMETA(DisplayName = "Weapon"),
	CS_Gemstones          UMETA(DisplayName = "Gemstones"),
	CS_Furr               UMETA(DisplayName = "Furr"),
	CS_Food               UMETA(DisplayName = "Food"),
	CS_Building_Materials UMETA(DisplayName = "Building Materials")
};

USTRUCT(BlueprintType)
struct FCardInfo
{
    GENERATED_BODY()

public:
    
    FCardInfo();

    FCardInfo(ECardSuit InCardSuit, uint8 InCardValue);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card Info")
	ECardSuit CardSuit;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Card Info")
	uint8 CardValue;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOG_API UMOGCardComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMOGCardComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Data)
	FCardInfo CardInfo;

	UFUNCTION(BlueprintCallable)
	FCardInfo GetCardInfo() { return CardInfo; }

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

    friend class AMOGCard;

    UFUNCTION(BlueprintCallable)
    void SetCardInfo(FCardInfo Info) { CardInfo = Info; }
    
    // Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
