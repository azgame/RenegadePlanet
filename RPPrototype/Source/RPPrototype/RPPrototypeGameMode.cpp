// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RPPrototypeGameMode.h"
#include "Planet/RPPrototypeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPPrototypeGameMode::ARPPrototypeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/RPDev/EarthDev/Characters/SidePersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
