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
	Territories.Add(new Territory(4, "Spain"));
}

void GameBoard::TakeStartingTerritory(Territory* territory, int ownerID)
{
	territory->takeTerritory(ownerID);
	territory->setArmyCount(StartingUnitCount);
}

void GameBoard::Attack(Territory* attackingTerritory, Territory* defendingTerritory, int attackUnitCount)
{
	UE_LOG(LogTemp, Warning, TEXT("%s attacking %s"), *attackingTerritory->_Name, *defendingTerritory->_Name);
	attackingTerritory->Reinforce(-attackUnitCount);

	// TODO: Calculate battle outcome
	if (true) { // TODO: Attacker always wins for now
		defendingTerritory->takeTerritory(attackingTerritory->_OwnerID);
		defendingTerritory->setArmyCount(attackUnitCount);
	}
}

void GameBoard::PrintBoardData()
{
	UE_LOG(LogTemp, Warning, TEXT("Number of territories: %i"), Territories.Num());

	for (auto& Territory : Territories)
	{
		FString TerritoryData;
		TerritoryData += TEXT("ID: ");
		TerritoryData += FString::FromInt(Territory->_ID);
		TerritoryData += TEXT(", ");
		TerritoryData += Territory->_Name;
		TerritoryData += TEXT(", owner:");
		TerritoryData += FString::FromInt(Territory->_OwnerID);
		TerritoryData += TEXT(", units: ");
		TerritoryData += FString::FromInt(Territory->_Units);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(TerritoryData));
	}

}
