// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class HEXBOARD_API GameBoard
{
public:
	GameBoard();

    virtual void Init();

private:

    TArray<int32> IntArray;

    virtual void PrintBoardData();
};
