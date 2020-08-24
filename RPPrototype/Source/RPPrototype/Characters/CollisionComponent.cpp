// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionComponent.h"
#include "GameFramework/Character.h"
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
	Collider->OnComponentBeginOverlap.AddDynamic(this, &UCollisionComponent::OnBeginOverlap);
	Collider->OnComponentEndOverlap.AddDynamic(this, &UCollisionComponent::OnEndOverlap);

	closestActor = nullptr;
	overlappingActors = TArray<AActor*>();
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
	closestActor = nullptr;
	IInteractable* closestInteract = nullptr;
	float shortestDistance = FLT_MAX;

	for (auto actor : overlappingActors)
	{
		if (actor != owner)
		{
			IInteractable* it = Cast<IInteractable>(actor);
			if (it)
			{
				if (0 <= owner->GetActorForwardVector().DotProduct(owner->GetActorForwardVector(), actor->GetActorLocation() - owner->GetActorLocation()))
				{
					float distance = owner->GetDistanceTo(actor);
					if (distance < shortestDistance)
					{
						shortestDistance = distance;
						closestInteract = it;
						closestActor = actor;
					}
				}
				it = nullptr;
			}
		}
	}
}

void UCollisionComponent::SetupAttachment(ACharacter* owner_, USceneComponent* RootComponent)
{
	Collider->SetupAttachment(RootComponent);
	owner = owner_;
}

void UCollisionComponent::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void UCollisionComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Collider->GetOverlappingActors(overlappingActors);
}

void UCollisionComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Collider->GetOverlappingActors(overlappingActors);
}

void UCollisionComponent::onInteract()
{
	if (closestActor)
		Cast<IInteractable>(closestActor)->onUse(owner);
}

AActor* UCollisionComponent::GetClosestInteract()
{
	return closestActor;
}