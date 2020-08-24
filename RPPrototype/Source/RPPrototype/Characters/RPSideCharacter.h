// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CollisionComponent.h"
#include "InventoryComponent.h"
#include "../HUD_UI.h"
#include "RPSideCharacter.generated.h"


UCLASS(config = Game)
class RPPROTOTYPE_API ARPSideCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* SideViewCameraComponent;

public:
	// Sets default values for this character's properties
	ARPSideCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CollisionComponent)
		UCollisionComponent* collisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InventoryComponent)
		UInventoryComponent* inventoryComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
		UHUD_UI* hudDisplay;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for side to side input */
	void MoveRight(float Value);

	void OnClicked();
	void OnReleased();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return SideViewCameraComponent; }
};
