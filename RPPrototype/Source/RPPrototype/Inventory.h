// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include <memory>
#include "Containers/Map.h"
#include "Containers/SortedMap.h"
#include "Item.h"
#include "Inventory.generated.h"

/**
 * 
 */
UCLASS()
class RPPROTOTYPE_API AInventory : public AActor
{
	GENERATED_BODY()

	using inventory_type = TMap<FString, TPair<AItem*, int>>;
	using iterator = typename inventory_type::TIterator; // <item id, <Item pointer, count>>

	inventory_type items;
	AActor* owner;
	unsigned int itemCount;
	unsigned int maxSize;
public:
	AInventory();
	~AInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void Initialize(int maxSize_, AActor* owner_);

	// get contents
	//UFUNCTION(BlueprintCallable, Category = "Inventory")
	inventory_type getContents();
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		AItem* getItem(FString itemID_);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		AItem* takeItem(FString itemID_, int & stackSize_, int amount_ = 1);
	// add item
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void addItem(FString itemID_);
	// emplace item
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void emplaceItem(FString itemID_, AItem* item_);
	// use item
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void useItem(FString itemID_, AActor* user_ = nullptr);
	// remove item
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void removeItem(FString itemID_);
	// max size
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		int getMaxSize();
	// merge and merge fits util
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void merge(AInventory* other_);

	bool mergeFits(AInventory* other_);
	// transfer
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void transfer(AInventory* other_, FString itemID_, int amount_ = 0);
	// isempty
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool isEmpty();
	// isfull
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool isFull();
	// set owner
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void setInventoryOwner(AActor* owner_);
	// get owner
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		AActor* getInventoryOwner();
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool contains(FString itemID_);
	// get item count
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		int getItemCount(FString itemID_);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		int getCount();
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void clear();
};
