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
	TArray<FVector2D> GetPixelsColors(UTexture2D* MyTexture2D);

	UFUNCTION(BlueprintCallable)
		void PaintPixel (UTexture2D* MyTexture2D, FColor Color, FVector2D Coords);

	UFUNCTION(BlueprintCallable)
		UTexture2D* CreateNewTextureAtRuntime(int32 Width, int32 Height, int32 SquareSize);

	UFUNCTION(BlueprintCallable)
		void MoveVertexOnMesh(UStaticMeshComponent* Mesh, int32 VertexNum);

	void PaintVertex();

	UFUNCTION(BlueprintCallable)
		void ApplyTextureToMaterial(UTexture2D* Texture);

	TMap<FVector, FColor> GetMeshVertexColors(UStaticMeshComponent* Mesh);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* CenterCube;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UInstancedStaticMeshComponent* CenterCube2;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
