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

	Territories[0]->takeTerritory(0);
	Territories[0]->setArmyCount(10);
	Territories[1]->takeTerritory(1);
	Territories[1]->setArmyCount(10);

	PrintBoardData();
}

void GameBoard::PrintBoardData()
{
	UE_LOG(LogTemp, Warning, TEXT("Number of territories: %i"), Territories.Num());

	for (auto& Territory : Territories)
	{
		FString TerritoryData;
		TerritoryData += TEXT("ID: ");
		TerritoryData += FString::FromInt(Territory->id);
		TerritoryData += TEXT(", ");
		TerritoryData += Territory->name;
		TerritoryData += TEXT(", owner:");
		TerritoryData += FString::FromInt(Territory->ownerID);
		TerritoryData += TEXT(", units: ");
		TerritoryData += FString::FromInt(Territory->units);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(TerritoryData));
	}

}
