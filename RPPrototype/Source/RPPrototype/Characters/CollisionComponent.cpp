// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionComponent.h"
#include "RPSideCharacter.h"
#include "Engine.h"

// Sets default values for this component's properties
UCollisionComponent::UCollisionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("InteractSphereCollider"));
	Collider->SetGenerateOverlapEvents(true);
}


// Called when the game starts
void UCollisionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Collider->SetSphereRadius(radius, false);
}


// Called every frame
void UCollisionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCollisionComponent::SetupAttachment(USceneComponent* RootComponent)
{
	Collider->SetupAttachment(RootComponent);
}

void UCollisionComponent::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void UCollisionComponent::onInteract()
{
	TArray<AActor*> overlappingActors = TArray<AActor*>();
	Collider->GetOverlappingActors(overlappingActors);

	IInteractable* closestInteract = nullptr;
	float shortestDistance = FLT_MAX;

	for (auto actor : overlappingActors)
	{
		if (actor != owner)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("actor: %s"), *actor->GetName()));
			IInteractable* it = Cast<IInteractable>(actor);
			if (it)
			{
				float distance = owner->GetDistanceTo(actor);
				if (distance < shortestDistance)
				{
					shortestDistance = distance;
					closestInteract = it;
				}
			}
			it = nullptr;
		}
	}

	if (closestInteract)
		closestInteract->onUse(owner);

	closestInteract = nullptr;
}

