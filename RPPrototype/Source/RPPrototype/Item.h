// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include <bitset>

#include "Item.generated.h"

UENUM()
enum ItemID
{
	UNKNOWN_ITEM UMETA(DisplayName = "UNKNOWN"),
	DEFAULT_ITEM UMETA(DisplayName = "DEFAULT"),
	QUEST_ITEM UMETA(DisplayName = "QUEST"),
	RESOURCE_ITEM UMETA(DisplayName = "RESOURCE"),
};

class ItemDispatcher;

UCLASS()
class RPPROTOTYPE_API AItem : public AActor
{
	GENERATED_BODY()

	static const std::size_t EQUIPPABLE_POS = 0;
	static const std::size_t REUSABLE_POS = 1;
	static const std::size_t STACKABLE_POS = 2;
	static const std::size_t EQUIPPED_POS = 3;

	static const int ATTRIBUTE_COUNT = 3;

	ItemID mID;
	std::bitset<ATTRIBUTE_COUNT + 1> mAttributes;
	
public:	

	friend class ItemDispatcher;

	// Sets default values for this actor's properties'
	AItem();
	AItem(ItemID id, std::bitset<ATTRIBUTE_COUNT> attributes = std::bitset<ATTRIBUTE_COUNT>{});

	virtual void use(ItemDispatcher& dispatcher) PURE_VIRTUAL(AItem::use,;);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void setEquippable(bool eq);
	void setStackable(bool stack);
	void setReusable(bool reuse);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Item")
	bool reusable();
	UFUNCTION(BlueprintCallable, Category = "Item")
	bool stackable();
	UFUNCTION(BlueprintCallable, Category = "Item")
	bool equippable();
	UFUNCTION(BlueprintCallable, Category = "Item")
	bool isEquipped();

	UFUNCTION(BlueprintCallable, Category = "Item")
	ItemID id();

	UFUNCTION(BlueprintCallable, Category = "Item")
	void setEquip(bool eq);



};
