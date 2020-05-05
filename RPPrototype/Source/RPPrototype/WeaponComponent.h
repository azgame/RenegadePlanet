// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseWeapon.h"
#include "WeaponComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPPROTOTYPE_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();
	UPROPERTY(editanywhere)
	ABaseWeapon* currentWeapon;
	UPROPERTY(editanywhere)
	ABaseWeapon* otherWeapon;
	void PA();
	void PAReleased();
	void SA();
	void SAReleased();
	void SetPHeld();
	void SetSHeld();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	int pHoldTime;
	int pHoldTimeMax;
	int sHoldTime;
	int sHoldTimeMax;
	bool sHeld;
	bool pHeld;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	

		
};
