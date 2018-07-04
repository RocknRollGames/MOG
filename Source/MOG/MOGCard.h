// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardComponents/MOGCardComponent.h"
#include "MOGPlayerController.h"
#include "MOGCard.generated.h"

UCLASS()
class MOG_API AMOGCard : public AActor
{
	GENERATED_BODY()

	friend class AMOGGameModeBase;

public:	
	// Sets default values for this actor's properties
	AMOGCard();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Data)
	UMOGCardComponent* CardComponent;

	UFUNCTION(BlueprintCallable)
	FCardInfo GetCardInfo() { return CardComponent->GetCardInfo(); }

	UPROPERTY(BlueprintReadOnly)
	AMOGPlayerController* OwnerController;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

    UFUNCTION(BlueprintCallable)
    void InitCard(FCardInfo Info);
	
};
