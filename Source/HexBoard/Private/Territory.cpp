// Fill out your copyright notice in the Description page of Project Settings.


#include "Territory.h"

Territory::Territory()
{

}

Territory::~Territory()
{
}

Territory::Territory(int _id, FString _name): id(_id), name(_name)
{
	units = 0;
	ownerID = -1;
}

void Territory::setArmyCount(int unitCount)
{
	units = unitCount;
}

void Territory::takeTerritory(int _ownerID)
{
	ownerID = _ownerID;
}
