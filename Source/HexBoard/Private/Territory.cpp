// Fill out your copyright notice in the Description page of Project Settings.


#include "Territory.h"

Territory::Territory()
{

}

Territory::~Territory()
{
}

Territory::Territory(int id, FString name): _ID(id), _Name(name)
{
	_Units = 0;
	_OwnerID = -1;
}

void Territory::setArmyCount(int unitCount)
{
	_Units = unitCount;
}

void Territory::Reinforce(int unitCount)
{
	_Units += unitCount;
	if (unitCount >= 0) {
		UE_LOG(LogTemp, Warning, TEXT("%s units reinforced by %s"), *_Name, *FString::FromInt(unitCount));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s units reduced by %s"), *_Name, *FString::FromInt(unitCount));
	}
}

void Territory::takeTerritory(int ownerID)
{
	_OwnerID = ownerID;
}
