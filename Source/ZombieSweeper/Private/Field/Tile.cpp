//
#include "Field/Tile.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

ATile::ATile()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));

	PaperMesh = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperMesh"));
	PaperMesh->SetupAttachment(RootComponent);

    CollideBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
    CollideBox->SetupAttachment(RootComponent);
}

void ATile::BeginPlay()
{

    Super::BeginPlay();

    CollideBox->OnComponentBeginOverlap.AddDynamic(this, &ATile::OnOverlap);
    SetSprite();
}

void ATile::SetSprite()
{
    UE_LOG(LogTemp, Log, TEXT("Change Sprite"));
    if (TileSprites.IsValidIndex(static_cast<int32>(TileType)))
    {
        UPaperSprite* CurrentMesh = TileSprites[static_cast<int32>(TileType)];

        if (CurrentMesh)
        {
            PaperMesh->SetSprite(CurrentMesh);
        }
    }
    else
    {
        //PaperMesh->SetSprite(TileSprites[0]);
    }
}

void ATile::DisableCollision()
{
    CollideBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ATile::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    OnTileOverlapEvent.Broadcast(this->TileIndex);
}
