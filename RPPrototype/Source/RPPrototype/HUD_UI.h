// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUD_UI.generated.h"

/**
 * 
 */
UCLASS()
class RPPROTOTYPE_API UHUD_UI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void DisplayDialogue(const FText& name_, const FText& msg_);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void ExitDialogue();
};
