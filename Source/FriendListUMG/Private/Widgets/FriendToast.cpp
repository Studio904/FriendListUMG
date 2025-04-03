// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/FriendToast.h"
#include "UObject/Object.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"


	

void UFriendToast::InitToastInfo()
{
	if (Avatar) {
		UObject* ImageObject = Cast<UObject>(AvatarImage);
		FSlateBrush Brush;
		Brush.SetResourceObject(AvatarImage);
		Brush.ImageSize = FVector2D(AvatarImage->GetSizeX(), AvatarImage->GetSizeY());
		Avatar->SetBrush(Brush);
	}
	if (NickName) {
		NickName->SetText(NickNameText);
	}

	if (Level) {
		FText LevelText = FText::AsNumber(LevelNumber);
		Level->SetText(LevelText);
	}

}

void UFriendToast::PlayAnim()
{
	if (FadeInAnim) {
		PlayAnimation(FadeInAnim);
	}
}
