// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBoard.h"

GameBoard::GameBoard()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello World from GameBoard"));
}

void GameBoard::Init()
{
	IntArray.Init(0, 10);

	// Init Territories
	Territories.Add(new Territory(1));
	Territories.Add(new Territory(2));
	Territories.Add(new Territory(3));

	PrintBoardData();
}

void GameBoard::PrintBoardData()
{
	UE_LOG(LogTemp, Warning, TEXT("Number of territories: %i"), Territories.Num());

	FString TerritoryData;
	for (auto& Territory : Territories)
	{
		TerritoryData += FString::FromInt(Territory->id);
		TerritoryData += TEXT(", ");
	}
	UE_LOG(LogTemp, Warning, TEXT("Territories: %s"), *FString(TerritoryData));
}
