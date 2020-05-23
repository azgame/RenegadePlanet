// Fill out your copyright notice in the Description page of Project Settings.


#include "IItemDispatcher.h"

IItemDispatcher::IItemDispatcher(AActor* target) : mTarget(target)
{
}

IItemDispatcher::~IItemDispatcher() = default;

void IItemDispatcher::setTarget(AActor* target)
{
	mTarget = target;
}

AActor* IItemDispatcher::target()
{
	return mTarget;
}
