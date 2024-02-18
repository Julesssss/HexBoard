// Copyright Epic Games, Inc. All Rights Reserved.


#include "HexBoardGameModeBase.h"

AHexBoardGameModeBase::AHexBoardGameModeBase()
{
	gameBoard = new GameBoard;
	if (gameBoard == NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to create gameboard"));
	}
	else {
		CreateGameBoard();
	}
}


void AHexBoardGameModeBase::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AHexBoardGameModeBase BeginPlay"));
}

void AHexBoardGameModeBase::CreateGameBoard() {
	UE_LOG(LogTemp, Warning, TEXT("Initialised gameboard"));
	gameBoard->Init();
}

void AHexBoardGameModeBase::MakeExampleMoves() {
	gameBoard->TakeStartingTerritory(gameBoard->Territories[0], 1);
	gameBoard->TakeStartingTerritory(gameBoard->Territories[1], 2);

	gameBoard->Attack(gameBoard->Territories[0], gameBoard->Territories[3], 5);

	gameBoard->PrintBoardData();
}
