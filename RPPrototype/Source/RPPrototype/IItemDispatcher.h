// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Item.h"

/**
 * 
 */
class RPPROTOTYPE_API IItemDispatcher
{
public:
	IItemDispatcher(AActor* target);
	~IItemDispatcher();

	virtual void dispatch(AItem& item) = 0;

	void setTarget(AActor* target);

protected:
	AActor* target();

private:
	AActor* mTarget;
};
