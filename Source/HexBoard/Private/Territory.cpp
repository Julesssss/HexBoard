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

void Territory::takeTerritory(int ownerID)
{
	_OwnerID = ownerID;
}
