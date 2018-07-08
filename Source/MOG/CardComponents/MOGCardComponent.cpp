// Fill out your copyright notice in the Description page of Project Settings.

#include "MOGCardComponent.h"


// Sets default values for this component's properties
UMOGCardComponent::UMOGCardComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMOGCardComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMOGCardComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FCardInfo::FCardInfo(ECardSuit InCardSuit, uint8 InCardValue)
    : CardSuit(InCardSuit), CardValue(InCardValue)
{
}

FCardInfo::FCardInfo()
{

}
