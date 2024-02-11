// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TextureReader.generated.h"

UCLASS()
class HEXBOARD_API ATextureReader : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATextureReader();
	void Test1();
	UFUNCTION(BlueprintCallable)
	TArray<FVector2D> LX_GetPixelsColors(UTexture2D* MyTexture2D);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
