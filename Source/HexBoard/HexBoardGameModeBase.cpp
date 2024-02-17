// Copyright Epic Games, Inc. All Rights Reserved.


#include "HexBoardGameModeBase.h"
#include <GameBoard.h>

void AHexBoardGameModeBase::BeginPlay()
{
	GameBoard* gameBoard = new GameBoard;
	if (gameBoard == NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to create gameboard"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Created gameboard"));
		gameBoard->Init();
	}
}
