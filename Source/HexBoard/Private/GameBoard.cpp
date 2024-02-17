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
	Territories.Add(new Territory(1, "England"));
	Territories.Add(new Territory(2, "Portugal"));
	Territories.Add(new Territory(3, "France"));

	PrintBoardData();
}

void GameBoard::PrintBoardData()
{
	UE_LOG(LogTemp, Warning, TEXT("Number of territories: %i"), Territories.Num());

	FString TerritoryData;
	for (auto& Territory : Territories)
	{
		TerritoryData += FString::FromInt(Territory->id);
		TerritoryData += TEXT(" ");
		TerritoryData += Territory->name;
		TerritoryData += TEXT(", ");
	}
	UE_LOG(LogTemp, Warning, TEXT("Territories: %s"), *FString(TerritoryData));
}
