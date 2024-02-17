// Fill out your copyright notice in the Description page of Project Settings.


#include "Territory.h"

Territory::Territory()
{
	id = 1;
	name = "";
}

Territory::~Territory()
{
}

Territory::Territory(int _id, FString _name): id(_id), name(_name)
{
	id = _id;
	name = _name;
}
