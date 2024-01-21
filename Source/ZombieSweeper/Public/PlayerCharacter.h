//
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class ZOMBIESWEEPER_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	void Move(const FInputActionValue& Value);
	//void Turn(const FInputActionValue& Value);


	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* InputContext;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MovementAction;

	//UPROPERTY(EditAnywhere, Category = Input)
	//UInputAction* TurnAction;

	//UPROPERTY(EditAnywhere, Category = Camera)
	//UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(EditAnywhere)
	UCameraComponent* ThirdPersonCameraComponent;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* CameraArm;
};
