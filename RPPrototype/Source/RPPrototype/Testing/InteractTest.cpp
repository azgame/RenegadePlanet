// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractTest.h"
#include "../Characters/RPSideCharacter.h"
#include "../Planet/RPPrototypeCharacter.h"

// Sets default values
AInteractTest::AInteractTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	rotate = 1.f;
	yaw = 0.0f;
	item = NewObject<AItem>();
}

// Called when the game starts or when spawned
void AInteractTest::BeginPlay()
{
	Super::BeginPlay();
	item->Initialize(ItemID::DEFAULT_ITEM, "basic item", std::bitset<3>("110"));
}

// Called every frame
void AInteractTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	yaw += rotate;

	SetActorRelativeRotation(FRotator(0.0f, yaw, 0.0f));
}

void AInteractTest::onUse(AActor* otherActor_)
{
	ARPSideCharacter* player = Cast<ARPSideCharacter>(otherActor_);

	if (player)
	{
		rotate *= -1;
		player->inventoryComponent->getInventory()->emplaceItem(item->name(), item);
	}

	ARPPrototypeCharacter* playerThird = Cast<ARPPrototypeCharacter>(otherActor_);

	if (playerThird)
		rotate *= -1;
}