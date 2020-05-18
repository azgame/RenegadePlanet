// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inventory.generated.h"

/**
 * 
 */
UCLASS()
class RPPROTOTYPE_API AInventory : public AActor
{
	GENERATED_BODY()
public:
	AInventory();
	~AInventory();

	UPROPERTY(EditAnywhere, Category = "Inventory")
		int sz;

	void Add(AActor* class_, int id);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		int getInvSize();
};
