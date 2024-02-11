// Fill out your copyright notice in the Description page of Project Settings.


#include "TextureReader.h"
//from: https://forums.unrealengine.com/t/dynamic-runtime-textures/67777/2
// https://isaratech.com/ue4-reading-the-pixels-from-a-utexture2d/
// To generate maps at runtime we need to create 1 map that is just for the visuals,
// And one map that sets the countries/regions.
// For this we will need a texture with different colors.
// Each color corresponding to a country.
// This actor will read the texture and assign each color to a region.
// Each player will start with some regions.
// 
// This way we can procedurally generate any map.
// Though this will be quite some hard work here.
ATextureReader::ATextureReader()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATextureReader::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void ATextureReader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATextureReader::Test1() {

}

TArray<FVector2D> ATextureReader::LX_GetPixelsColors(UTexture2D* MyTexture2D) {
    const FColor* FormatedImageData = static_cast<const FColor*>(MyTexture2D->PlatformData->Mips[0].BulkData.LockReadOnly());
    TArray<FVector2D> BrazilRegion;
    FColor SeaColor = FColor(0, 255, 255);
    int32 InvX = MyTexture2D->GetSizeX();
    int32 InvY = MyTexture2D->GetSizeY();
    for (int32 X = 0; X < MyTexture2D->GetSizeX(); X++)
    {
        InvX--;
        for (int32 Y = 0; Y < MyTexture2D->GetSizeY(); Y++)
        {
            InvY--;
            FColor PixelColor = FormatedImageData[Y * MyTexture2D->GetSizeX() + X];
            // 
            if (PixelColor != SeaColor) {
                //BrazilRegion.Add(FVector2D(X, Y));
                //needs inverted X, Y because its bugging otherwise

                // Mirror the X-coordinate along the Y-axis
                int32 MirroredX = MyTexture2D->GetSizeX() - 1 - X;
                BrazilRegion.Add(FVector2D(InvY, X));
            }
            //That should do it.
            //Untested.
        }
         InvY = MyTexture2D->GetSizeY();

    }

    MyTexture2D->PlatformData->Mips[0].BulkData.Unlock();

    return BrazilRegion;
}

