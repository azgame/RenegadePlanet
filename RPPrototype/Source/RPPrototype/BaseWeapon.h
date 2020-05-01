// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseWeapon.generated.h"


UCLASS()
class RPPROTOTYPE_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();
	float damage;
	float maxAmmo;
	float ammo;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* mesh;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PAttack1();
	virtual void PAttack2();
	virtual void SAttack1();
	virtual void SAttack2();
};
