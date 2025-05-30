#include "CPP_ControllerIA.h"
#include "Kismet/GameplayStatics.h"

void ACPP_ControllerIA::BeginPlay()
{
    Super::BeginPlay();
}

void ACPP_ControllerIA::DecideBehavior(APawn* PlayerPawn)
{
    if (!PlayerPawn) return;

    // Choisir un comportement aléatoire
    bIsChasing = FMath::RandBool();

    if (bIsChasing)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("L'IA te POURSUIT !"));
        MoveToActor(PlayerPawn, 5.0f);
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("L'IA FUIT !"));
        FVector FuiteDirection = GetPawn()->GetActorLocation() + (GetPawn()->GetActorLocation() - PlayerPawn->GetActorLocation()).GetSafeNormal() * 500.0f;
        MoveToLocation(FuiteDirection);
    }
}