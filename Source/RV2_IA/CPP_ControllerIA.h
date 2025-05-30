#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CPP_ControllerIA.generated.h"

UCLASS()
class RV2_IA_API ACPP_ControllerIA : public AAIController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "AI")
    bool bIsChasing;

    void DecideBehavior(APawn* PlayerPawn);

};