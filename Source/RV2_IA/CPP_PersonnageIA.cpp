#include "CPP_PersonnageIA.h"
#include "CPP_ControllerIA.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"

// Constructeur
ACPP_PersonnageIA::ACPP_PersonnageIA()
{
    PrimaryActorTick.bCanEverTick = true;
    PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
    PawnSensingComp->SightRadius = 1000.0f;  // Distance de d�tection
    PawnSensingComp->SetPeripheralVisionAngle(60.0f);  // Champ de vision
    PawnSensingComp->bOnlySensePlayers = true; // D�tection seulement des joueurs
}

// Initialisation au d�marrage
void ACPP_PersonnageIA::BeginPlay()
{
    Super::BeginPlay();

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("IA initialis�e !"));
    }

    PawnSensingComp->OnSeePawn.AddDynamic(this, &ACPP_PersonnageIA::OnPlayerSpotted);
}

// D�tection du joueur
void ACPP_PersonnageIA::OnPlayerSpotted(APawn* PlayerPawn)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Joueur d�tect� !"));
    }

    ACPP_ControllerIA* AIController = Cast<ACPP_ControllerIA>(GetController());
    if (!AIController || !PlayerPawn) return;

    // Appeler la fonction de d�cision du contr�leur IA
    AIController->DecideBehavior(PlayerPawn);

}

// Tick (mise � jour chaque frame)
void ACPP_PersonnageIA::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Configuration des inputs (inutile pour une IA)
void ACPP_PersonnageIA::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}