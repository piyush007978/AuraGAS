// Downbeatwolf


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interface/ActorHoverInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
    bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);
    CursorTrace();
}

void AAuraPlayerController::BeginPlay()
{
    Super::BeginPlay();
    check(AuraContext);

    UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    if(subSystem)
    {
        subSystem->AddMappingContext(AuraContext, 0);
	}

    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;

    FInputModeGameAndUI inputModeData;
    inputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    inputModeData.SetHideCursorDuringCapture(false);
    SetInputMode(inputModeData);

}

void AAuraPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    
    UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
    enhancedInputComponent->BindAction(InputAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& anInputActionValue)
{
   const FVector2D inputAxisVector = anInputActionValue.Get<FVector2D>();

    const FRotator yawRotation = FRotator(0.f, GetControlRotation().Yaw, 0);
    
    const FVector rightDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
    const FVector forwardDirection = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);

    if (APawn* pawn = GetPawn<APawn>())
    {
        pawn->AddMovementInput(forwardDirection, inputAxisVector.Y);
        pawn->AddMovementInput(rightDirection, inputAxisVector.X);
    }
}

void AAuraPlayerController::CursorTrace()
{
    FHitResult result;
    GetHitResultUnderCursor(ECC_Visibility, false, result);
    if(!result.bBlockingHit)
        return;
    
    TScriptInterface<IActorHoverInterface> LastActor = CursorActor;
    CursorActor = result.GetActor();
    if (!LastActor && CursorActor)
    {
        CursorActor->HighlightActor();
    }
    
    else if(LastActor)
    {
        if (!CursorActor)
        {
            LastActor->UnHighlightActor();
        }
        else if (CursorActor != LastActor)
        {
            CursorActor->HighlightActor();
            LastActor->UnHighlightActor();
        }
    }
}
