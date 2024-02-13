// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)
class TWINSTICKSHOOTER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	//Make healt property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
		float Health = 100;

	//Make isDead property
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base Character")
		bool isDead = false;

	//Calculate death function (helper)
	virtual void CalculateDead();

	//Calculate healt function
	UFUNCTION(BlueprintCallable, Category = "Base Character")
		virtual void CalculateHealth(float delta);

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
		override;
#endif


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
