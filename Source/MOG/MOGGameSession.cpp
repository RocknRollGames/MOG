// Fill out your copyright notice in the Description page of Project Settings.

#include "MOGGameSession.h"




void AMOGGameSession::RegisterPlayer(APlayerController* NewPlayer, const TSharedPtr<const FUniqueNetId>& UniqueId, bool bWasFromInvite)
{
    Super::RegisterPlayer(NewPlayer, UniqueId, bWasFromInvite);
}
