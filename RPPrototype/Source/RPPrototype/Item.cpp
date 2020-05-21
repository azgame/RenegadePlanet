// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

// Sets default values

AItem::AItem()
{

}

AItem::AItem(ItemID id, std::bitset<ATTRIBUTE_COUNT> attributes)
	: mID{ id }
{
	mAttributes[EQUIPPABLE_POS] = attributes[EQUIPPABLE_POS];
	mAttributes[STACKABLE_POS] = attributes[STACKABLE_POS];
	mAttributes[REUSABLE_POS] = attributes[REUSABLE_POS];
	mAttributes[EQUIPPED_POS] = false;

	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::setEquip(bool eq)
{
	mAttributes[EQUIPPED_POS] = eq;
}

bool AItem::isEquipped()
{
	return mAttributes.test(EQUIPPED_POS);
}

bool AItem::equippable()
{
	return mAttributes.test(EQUIPPABLE_POS);
}

bool AItem::reusable()
{
	return mAttributes.test(REUSABLE_POS);
}

bool AItem::stackable()
{
	return mAttributes.test(STACKABLE_POS);
}

ItemID AItem::id()
{
	return mID;
}

void AItem::setEquippable(bool eq)
{
	mAttributes[EQUIPPABLE_POS] = eq;
}

void AItem::setStackable(bool stack)
{
	mAttributes[STACKABLE_POS] = stack;
}

void AItem::setReusable(bool reuse)
{
	mAttributes[REUSABLE_POS] = reuse;
}