// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include "Drill.h"
// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	currentWeapon = CreateDefaultSubobject<ADrill>(TEXT("currentWeapon"));
	if (currentWeapon)
	{

	pHoldTimeMax = currentWeapon->pChargeTime;
	sHoldTimeMax = currentWeapon->sChargeTime;
	}
	// ...
}


// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	if (currentWeapon)
	{

		pHoldTimeMax = currentWeapon->pChargeTime;
		sHoldTimeMax = currentWeapon->sChargeTime;
	}
	// ...
	
}
void UWeaponComponent::PA()
{
	
	if (pHoldTime < pHoldTimeMax)
	{
		pHoldTime++;
	}
	else
	{
		//possibly add animation or something to indicate charge is ready
	}
}
void UWeaponComponent::PAReleased()
{
	if (pHoldTime < pHoldTimeMax)
	{
		
		currentWeapon->PAttack1();
	}
	else
	{
		currentWeapon->PAttack2();
	}
	sHoldTime = 0;
	pHoldTime = 0;
	pHeld = false;
	pHeld = false;
}
void UWeaponComponent::SA()
{

	if (sHoldTime < sHoldTimeMax)
	{
		sHoldTime++;
	}
	else
	{
		//possibly add animation or something to indicate charge is ready
	}
}
void UWeaponComponent::SAReleased()
{
	if (sHoldTime < sHoldTimeMax)
	{
		currentWeapon->SAttack1();
	}
	else
	{
		currentWeapon->SAttack2();
	}
	sHoldTime = 0;
	pHoldTime = 0;
	pHeld = false;
	pHeld = false;
}
// Called every frame
void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (pHeld)
	{
		PA();
	}
	else if (sHeld)
	{
		SA();
	}
	// ...
}
void UWeaponComponent::SetPHeld()
{
	pHeld = true;
	sHeld = false;
}
void UWeaponComponent::SetSHeld()
{
	pHeld = false;
	sHeld = true;
}