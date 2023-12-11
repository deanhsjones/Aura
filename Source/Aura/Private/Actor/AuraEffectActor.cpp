// Copyright Dean Jones


#include "Actor/AuraEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "AbilitySystemComponent.h"
//#include "AbilitySystemInterface.h"
//#include "AbilitySystem/AuraAttributeSet.h"
//
//#include "Components/SphereComponent.h"


AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	//Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	//SetRootComponent(Mesh);
	//Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	//Sphere->SetupAttachment(GetRootComponent());

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
	
}

//void AAuraEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
//	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//
//	//TO DO: Change this to apply a Gameplay Effect; for now using const cast as a hack just to see how it works ;)
//
//	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
//	{
//		const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));
//		//here is the const cast! This is dangerous and should be changed!
//		UAuraAttributeSet* MutableAuraAttributeSet = const_cast<UAuraAttributeSet*>(AuraAttributeSet);
//		MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);
//		MutableAuraAttributeSet->SetMana(AuraAttributeSet->GetMana() - 25.f);
//		//that was the const cast! Change it later!
//		Destroy();
//	}
//}
//
//void AAuraEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
//	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
//{
//}

//void AAuraEffectActor::BeginPlay()
//{
//	//Super::BeginPlay();
//	//Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnOverlap);
//	//Sphere->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectActor::EndOverlap);
//}

void AAuraEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (TargetAbilitySystemComponent == nullptr) return;
	
	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
	TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}
