// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/FriendToast.h"
#include "UObject/Object.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UFriendToast::InitToastInfo(UTexture2D* AvatarImage, FText& InNickName, int64& InLevel)
{
	if (Avatar) {
			UObject* ImageObject = Cast<UObject>(AvatarImage);
			FSlateBrush Brush;
			Brush.SetResourceObject(AvatarImage);
			Brush.ImageSize = FVector2D(AvatarImage->GetSizeX(), AvatarImage->GetSizeY());
			Avatar->SetBrush(Brush);
	}
	if (NickName) {
		FText NickNameText = InNickName;
		NickName->SetText(NickNameText);
	}

		if (Level) {
			int64 LevelNumber = InLevel;
			FText LevelText = FText::AsNumber(LevelNumber);
			NickName->SetText(LevelText);
		}
	}
