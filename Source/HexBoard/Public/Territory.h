// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>

/**
 * 
 */
class HEXBOARD_API Territory
{
public:
	Territory();
	~Territory();

	// Constructor with params
	Territory(int, FString);

	int32 _ID;
	FString _Name;
	int32 _OwnerID;
	int32 _Units;

	virtual void setArmyCount(int);

	virtual void Reinforce(int);

	virtual void takeTerritory(int);
};
