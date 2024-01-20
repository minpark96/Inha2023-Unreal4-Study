#include "CDrawDebug.h"
#include "Global.h"

ACDrawDebug::ACDrawDebug()
{
	PrimaryActorTick.bCanEverTick = true;

	InitLocation[0] = FVector::ZeroVector;
	InitLocation[1] = FVector(0, 400, 0);
	InitLocation[2] = FVector(0, 1000, 0);
	InitLocation[3] = FVector(0, 1600, 0);
	InitLocation[4] = FVector(300, 1000, 0);
	
	Box = FBox(FVector(-50, -100, -50), FVector(50, 100, 50));

	Transform.SetLocation(FVector(200, 1600, 0));

}

void ACDrawDebug::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < 5;i++)
	{
		Location[i] = InitLocation[i] + GetActorLocation();
	}
	
	DrawDebugBox(GetWorld(), Location[0] + Box.GetCenter(), Box.GetExtent(), FColor::Red, true);

}

void ACDrawDebug::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (int32 i = 0; i < 5;i++)
	{
		Location[i] = InitLocation[i] + GetActorLocation();
	}

	DrawDebugSolidBox(GetWorld(), Location[0] + Box.GetCenter(), Box.GetExtent(), FColor::Red);
	DrawDebugPoint(GetWorld(), Location[1], 50, FColor::Red);
	DrawDebugSphere(GetWorld(), Location[2], 100, 50, FColor::Green, false, -1, 3);
	DrawDebugCircle(GetWorld(), Location[3], 100, 60, FColor::Blue);

	DrawDebugLine(GetWorld(), Location[2], Location[3], FColor::Magenta, false, -1, 0, 2);

	FVector location = Location[1];
	location.X += 100; 
	location.Z += 100;
	location.Y += sin(GetWorld()->GetTimeSeconds() * 3.0f) * 300.0f;//3은 빨리 움직이게 하기 위한거, 300은 진폭
	DrawDebugPoint(GetWorld(), location, 100, FColor::Emerald);

	DrawDebugDirectionalArrow(GetWorld(), location, Location[3], 350, FColor::Yellow, false, -1, 4, 10);

}

