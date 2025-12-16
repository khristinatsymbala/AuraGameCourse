// Copyright Kris


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"

AAuraPlayerController::AAuraPlayerController()
{
	/*Replication essentially in multiplayer is when an entity changes on the server.
	 *That change that took place on the server will replicate or be sent down to all clients connected to it the server.
	 *So we have the concept of changes being made on multiple machines.
	 *One of those machines is the server and all other machines are clients, so replication is responding to data, 
	 *updating on the server and sending that down to clients.
	 */
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	check(AuraContext);//double check pointer to mapping context
	
	//Gets an Enhanced Input subsystem tied to the local player to control its input schemes.
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);
	
	//MouseCursor
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	/*Data structure used to set up an input mode that allows the UI to respond to user input
	 *Now the struct  input mode game and UI is an input mode struct and if we use this input mode then
	 *we'll be able to use input from our keyboard and mouse, and we'll also be able to use input to affect UI 
	 *such as widgets.
	 */
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
	
	
}
