
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimInstance.generated.h"

UCLASS()
class CPP1211_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		float Speed;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		bool bEquipped;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		float Direction;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		bool bAiming;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		float Pitch;

	//부모클래스 함수 두개를 오버라이드
public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	class ACharacter* OwnerCharacter;
};
