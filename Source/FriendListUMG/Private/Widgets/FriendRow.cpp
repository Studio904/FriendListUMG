// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/FriendRow.h"
#include "FriendListEntry.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UFriendRow::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	if (ListItemObject) {
		UFriendListEntry* FriendListEntry = Cast<UFriendListEntry>(ListItemObject);

		if (Avatar && FriendListEntry) {
			UTexture2D* AvatarTexture = FriendListEntry->FriendData.Image;
			if (AvatarTexture) {
				FSlateBrush Brush;
				Brush.SetResourceObject(AvatarTexture);
				Brush.ImageSize = FVector2D(AvatarTexture->GetSizeX(), AvatarTexture->GetSizeY());
				Avatar->SetBrush(Brush);
			}
		}

		if (NickName && FriendListEntry) {
			FText NickNameText = FriendListEntry->FriendData.NickName;
			NickName->SetText(NickNameText);
		}
	}
}
