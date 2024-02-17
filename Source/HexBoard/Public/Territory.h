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
	Territory(int id, FString name);

	int32 id;
	FString name;
};
