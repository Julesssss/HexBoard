// Fill out your copyright notice in the Description page of Project Settings.


#include "GameBoard.h"

GameBoard::GameBoard()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello World from GameBoard"));
}

void GameBoard::Init()
{
	IntArray.Init(0, 10);
	PrintBoardData();
}

void GameBoard::PrintBoardData()
{
	FString BoardData;
	for (auto& Int : IntArray)
	{
		BoardData += FString::FromInt(Int);
		BoardData += TEXT(", ");
	}
	UE_LOG(LogTemp, Warning, TEXT("Distance: %s"), *FString(BoardData));
}
