// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SphereComponent.h"
#include "Components/SceneComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "Engine.h"
#include "Engine/TriggerBox.h"
#include "../Interfaces/Interactable.h"
#include "CollisionComponent.generated.h"

class ACharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPPROTOTYPE_API UCollisionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCollisionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Custom Collision")
		void SetupAttachment(ACharacter* owner_, USceneComponent* RootComponent);

	UPROPERTY(EditAnywhere, Category = "Custom Collision")
		USphereComponent* Collider;

	UPROPERTY(EditAnywhere, Category = "Custom Collision")
		float radius;

	UFUNCTION(BlueprintCallable, Category = "Custom Collision")
		void OnCollision(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Custom Collision")
		void OnBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Custom Collision")
		void OnEndOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable, Category = "Custom Collision")
		void onInteract();

	UFUNCTION(BlueprintCallable, Category = "Custom Collision")
		AActor* GetClosestInteract();

	TArray<AActor*> overlappingActors;
	AActor* closestActor;
	ACharacter* owner;

	
};
