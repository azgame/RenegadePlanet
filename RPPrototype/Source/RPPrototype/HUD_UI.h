// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FDialogueStructure.h"
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
		void DisplayDialogue(const FDialogueStructure& dialogue_);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void AskQuestion(const FDialogueStructure& prompt_, const TArray<FDialogueStructure>& choices_);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void ExitDialogue();
};
