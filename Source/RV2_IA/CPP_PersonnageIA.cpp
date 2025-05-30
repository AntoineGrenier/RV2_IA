#include "CPP_PersonnageIA.h"
#include "CPP_ControllerIA.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"

// Constructeur
ACPP_PersonnageIA::ACPP_PersonnageIA()
{
    PrimaryActorTick.bCanEverTick = true;
    PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
    PawnSensingComp->SightRadius = 1000.0f;  // Distance de détection
    PawnSensingComp->SetPeripheralVisionAngle(60.0f);  // Champ de vision
    PawnSensingComp->bOnlySensePlayers = true; // Détection seulement des joueurs
}

// Initialisation au démarrage
void ACPP_PersonnageIA::BeginPlay()
{
    Super::BeginPlay();

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("IA initialisée !"));
    }

    PawnSensingComp->OnSeePawn.AddDynamic(this, &ACPP_PersonnageIA::OnPlayerSpotted);
}

// Détection du joueur
void ACPP_PersonnageIA::OnPlayerSpotted(APawn* PlayerPawn)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Joueur détecté !"));
    }

    ACPP_ControllerIA* AIController = Cast<ACPP_ControllerIA>(GetController());
    if (!AIController || !PlayerPawn) return;

    // Appeler la fonction de décision du contrôleur IA
    AIController->DecideBehavior(PlayerPawn);

}

// Tick (mise à jour chaque frame)
void ACPP_PersonnageIA::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Configuration des inputs (inutile pour une IA)
void ACPP_PersonnageIA::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}