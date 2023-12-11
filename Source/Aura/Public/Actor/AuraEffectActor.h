// Copyright Dean Jones

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"


//class USphereComponent;
class UGameplayEffect;


UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();

	//UFUNCTION()
	//virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
	//	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//UFUNCTION()
	//virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
	//	UPrimitiveComponent* OtherComp,	int32 OtherBodyIndex);



protected:
	/*virtual void BeginPlay() override;*/

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

private:
	//UPROPERTY(VisibleAnywhere)
	//TObjectPtr<USphereComponent> Sphere;

	//UPROPERTY(VisibleAnywhere)
	//TObjectPtr<UStaticMeshComponent> Mesh;

};
