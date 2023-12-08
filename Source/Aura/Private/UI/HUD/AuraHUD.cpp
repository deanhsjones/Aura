// Copyright Dean Jones


#include "UI/HUD/AuraHUD.h"


#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);

		return OverlayWidgetController;

	}
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	//validity checks with useful error messages
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class Uninitialised, please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Class Uninitialised, please fill out BP_AuraHUD"));
	
	
	//construct widget
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);
	
	//construct widgetcontroller
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	//set widget's widgetcontroller
	OverlayWidget->SetWidgetController(WidgetController);
	
	//add to viewport
	Widget->AddToViewport();
}

//void AAuraHUD::BeginPlay()
//{
//	Super::BeginPlay();
//
//	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
//	Widget->AddToViewport();
//
//}
