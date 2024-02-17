// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Territory.h"
#include "CoreMinimal.h"

/**
 * 
 */
class HEXBOARD_API GameBoard
{
public:
	GameBoard();
    ~GameBoard();

    virtual void Init();

    TArray<Territory*> Territories;

private:

    TArray<int32> IntArray;

    virtual void TakeStartingTerritory(Territory* territory, int OwnerID);

    virtual void PrintBoardData();
};
