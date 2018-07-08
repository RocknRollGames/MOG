// Fill out your copyright notice in the Description page of Project Settings.

#include "MOGPawn.h"


// Sets default values
AMOGPawn::AMOGPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMOGPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMOGPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMOGPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

