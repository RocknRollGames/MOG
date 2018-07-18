// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "MOGGameSession.generated.h"

/**
 * 
 */
UCLASS()
class MOG_API AMOGGameSession : public AGameSession
{
	GENERATED_BODY()
	
public:

    virtual void RegisterPlayer(APlayerController* NewPlayer, const TSharedPtr<const FUniqueNetId>& UniqueId, bool bWasFromInvite) override;

	
};
