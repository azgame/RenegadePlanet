// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IItemDispatcher.h"

/**
 * 
 */
class RPPROTOTYPE_API ItemDispatcher : public IItemDispatcher
{
public:
	ItemDispatcher(AActor* target);
	~ItemDispatcher();

	void dispatch(AItem& item);
};
