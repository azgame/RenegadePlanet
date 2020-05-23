// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Inventory.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPPROTOTYPE_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

	AInventory* inventory;
	AActor* owner;

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FORCEINLINE void setPlayerRef(AActor* owner_) { owner = owner_; }

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		AInventory* getInventory();
};
