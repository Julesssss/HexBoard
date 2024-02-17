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
	Territory* t1 = new Territory;
	Territories.Add(t1);
	Territories.Add(new Territory);
	Territories.Add(new Territory);

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
