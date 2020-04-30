// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWeapon.h"
#include "Components/BoxComponent.h"
#include "Drill.generated.h"

/**
 * 
 */
UCLASS()
class RPPROTOTYPE_API ADrill : public ABaseWeapon
{
	GENERATED_BODY()
public:
	ADrill();
	UPROPERTY(editanywhere)
	UBoxComponent* CollisionMesh = nullptr;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PAttack1()override;
	virtual void PAttack2()override;
	virtual void SAttack1()override;
	virtual void SAttack2()override;
};
