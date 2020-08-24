// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemDispatcher.h"

ItemDispatcher::ItemDispatcher(AActor* target) : IItemDispatcher(target)
{
}

ItemDispatcher::~ItemDispatcher() = default;

void ItemDispatcher::dispatch(AItem& item)
{
	// does nothing to base Item
}
