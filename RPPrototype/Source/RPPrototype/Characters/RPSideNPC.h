// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CollisionComponent.h"
#include "../Interfaces/Interactable.h"
#include "RPSideNPC.generated.h"

UCLASS()
class RPPROTOTYPE_API ARPSideNPC : public ACharacter, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPSideNPC();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CollisionComponent)
		UCollisionComponent* collisionComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void onUse(AActor* otherActor_) override;
};
