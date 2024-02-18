// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include <GameBoard.h>
#include "HexBoardGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class HEXBOARD_API AHexBoardGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	void MakeExampleMoves();

public:
	GameBoard* gameBoard;
};
