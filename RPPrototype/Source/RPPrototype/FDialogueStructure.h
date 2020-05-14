// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "EngineMinimal.h"
#include "FDialogueStructure.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct RPPROTOTYPE_API FDialogueStructure : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName RowID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int characterID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName characterName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString text;

	FDialogueStructure() {}
};
