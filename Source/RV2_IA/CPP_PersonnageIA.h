#pragma once

#include "CoreMinimal.h"
#include "Perception/PawnSensingComponent.h"
#include "GameFramework/Character.h"
#include "CPP_PersonnageIA.generated.h"

UCLASS()
class RV2_IA_API ACPP_PersonnageIA : public ACharacter
{
    GENERATED_BODY()

public:
    ACPP_PersonnageIA(); // Constructeur

    UPROPERTY(VisibleAnywhere, Category = "AI")
    UPawnSensingComponent* PawnSensingComp;


protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnPlayerSpotted(APawn* PlayerPawn);

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};