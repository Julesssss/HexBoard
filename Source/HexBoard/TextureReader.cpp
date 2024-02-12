// Fill out your copyright notice in the Description page of Project Settings.


#include "TextureReader.h"
#include "Engine/TextureRenderTarget2D.h"

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
    CenterCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    SetRootComponent(CenterCube);
}

// Called when the game starts or when spawned
void ATextureReader::BeginPlay()
{
	Super::BeginPlay();

   UTexture2D* TestTex = CreateNewTextureAtRuntime(100, 100, 16);
   PaintPixel(TestTex, FColor::Emerald, FVector2D(0, 0));
   ApplyTextureToMaterial(TestTex);
}

// Called every frame
void ATextureReader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATextureReader::Test1() {

}

TArray<FVector2D> ATextureReader::GetPixelsColors(UTexture2D* MyTexture2D) {
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

void ATextureReader::PaintPixel(UTexture2D* MyTexture2D, FColor Color, FVector2D Coords) {
    UTexture2D* Texture = MyTexture2D;
    Texture->MipGenSettings = TMGS_NoMipmaps;
    Texture->Filter = TF_Nearest;
    int32 SizeX = Texture->GetSizeX();
    FColor* Pixels = (FColor*)Texture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
    Pixels[(int32)Coords.X + (int32)Coords.Y * SizeX] = Color;
    Texture->PlatformData->Mips[0].BulkData.Unlock();
    Texture->UpdateResource();

}

UTexture2D* ATextureReader::CreateNewTextureAtRuntime(int32 Width, int32 Height, int32 SquareSize) {
    //This will create a checkerboard texture of blue and red.
    //FString MaterialPath = "/Game/NewMaterial.NewMaterial";
    UTexture2D* Texture = UTexture2D::CreateTransient(Width, Height, PF_B8G8R8A8);
    Texture->MipGenSettings = TMGS_NoMipmaps;
    Texture->Filter = TF_Nearest;
    FColor* Pixels = (FColor*)Texture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);

    for (int32 y = 0; y < Height; y++) {
        for (int32 x = 0; x < Width; x++) {
            if (((x / SquareSize) + (y / SquareSize)) % 2 == 0) {
                // Set to blue
                Pixels[x + y * Width] = FColor(0, 0, 255, 255);
            }
            else {
                // Set to red
                Pixels[x + y * Width] = FColor(255, 0, 0, 255);
            }
        }
    }


    Texture->PlatformData->Mips[0].BulkData.Unlock();
    Texture->UpdateResource();
    return Texture;
}

void ATextureReader::ApplyTextureToMaterial(UTexture2D* Texture) {
    FString MaterialPath = "/Game/NewMaterial.NewMaterial"; //just for testing purposes, make sure this material exists.
    UMaterialInterface* Material = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, *MaterialPath));

    UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);
    DynamicMaterial->SetTextureParameterValue(FName(TEXT("Texture")), Texture);
    // Set the dynamic material instance on the mesh component
    CenterCube->SetMaterial(0, DynamicMaterial);

}

TMap<FVector, FColor> ATextureReader::GetMeshVertexColors(UStaticMeshComponent* Mesh) {
    UStaticMesh* StaticMesh2 = Mesh->GetStaticMesh();
    TMap<FVector, FColor> MeshVertexData;

    StaticMesh2->GetVertexColorData(MeshVertexData);
    int32 numvert = StaticMesh2->GetNumVertices(0);

    //StaticMesh->SetVertexColorData();
    GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Orange, " numvert : " + FString::FromInt(numvert));


    for (auto Iter = MeshVertexData.CreateIterator(); Iter; ++Iter)
    {
    	auto& Elem = *Iter;
    	FVector key2 = Elem.Key;
    	FColor value = Elem.Value;
    	GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Orange, "MeshVertexData vector : " +key2.ToString());
    	GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Orange, "MeshVertexData color : " + MeshVertexData[key2].ToString());
    	GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Orange, "MeshVertexData color : ");


    }

    return MeshVertexData;

}

void ATextureReader::PaintVertex() {
    //to be done later.
    //from: https://forums.unrealengine.com/t/painting-vertex-colours-from-code/6902/5
    //fixed and altered the code, untested.

    /*
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Verts %d: "), CenterCube->GetStaticMesh()->GetNumVertices(0)));

    CenterCube->SetLODDataCount(1, CenterCube->LODData.Num());

    FStaticMeshComponentLODInfo* InstanceMeshLODInfo = &CenterCube->LODData[0];

    InstanceMeshLODInfo->PaintedVertices.Empty();

    InstanceMeshLODInfo->OverrideVertexColors = new FColorVertexBuffer;

    FStaticMeshLODResources& LODModel = CenterCube->GetStaticMesh()->RenderData->LODResources[0];

    if ((int32)LODModel.VertexBuffers.ColorVertexBuffer.GetNumVertices() >= LODModel.GetNumVertices())
    {
        InstanceMeshLODInfo->OverrideVertexColors->InitFromColorArray(&LODModel.VertexBuffers.ColorVertexBuffer.VertexColor(0), LODModel.GetNumVertices());
    }
    else
    {
        InstanceMeshLODInfo->OverrideVertexColors->InitFromSingleColor(FColor::Green, LODModel.GetNumVertices());
    }

    BeginInitResource(InstanceMeshLODInfo->OverrideVertexColors); //commented in original code, double check
    CenterCube->MarkRenderStateDirty(); //commented in original code, double check

        for (uint32 i = 0; i < InstanceMeshLODInfo->OverrideVertexColors->GetNumVertices(); i++)
        {
            InstanceMeshLODInfo->OverrideVertexColors->VertexColor(i) = FColor::Green;
        }
        */
}

void ATextureReader::MoveVertexOnMesh(UStaticMeshComponent* Mesh, int32 VertexNum) {
    //UStaticMeshComponent* StaticMeshComponent = FindComponentByClass<UStaticMeshComponent>();
    if (Mesh)
    {
        UStaticMesh* StaticMesh = Mesh->GetStaticMesh();
        if (StaticMesh && StaticMesh->GetRenderData())
        {
            FPositionVertexBuffer& VertexBuffer = StaticMesh->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer;

            //FPositionVertexBuffer& VertexBuffer = StaticMesh->RenderData->LODResources[0].PositionVertexBuffer;
            if (VertexBuffer.GetNumVertices() > 0)
            {
                FVector& VertexLocation = VertexBuffer.VertexPosition(0);
                GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Orange, "VertexBuffer vector : " + VertexLocation.ToString());
                VertexLocation += FVector(500, 300, 0); //this might be enough.
                //VertexLocation += FVector(100, 0, 0);
                //VertexBuffer.SetVertexPosition(0, VertexLocation);
                //interesting.

                ////VertexBuffer.InitRHIResources();
                //VertexBuffer.InitRHIResources();
                Mesh->MarkRenderStateDirty();
            }
        }
    }
}