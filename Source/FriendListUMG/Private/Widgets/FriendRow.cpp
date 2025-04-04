// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/FriendRow.h"
#include "FriendListEntry.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Widgets/FriendTooltip.h"
#include "Components/HorizontalBox.h"
#include "Components/Border.h"

void UFriendRow::SetToolTipWidget(int64& Level, FText& LastTimeConected, FText& Note)
{
	if (FriendToolTipWidgetClass) {
		UFriendTooltip* FrienTooltipWidget = CreateWidget<UFriendTooltip>(this, FriendToolTipWidgetClass);
		FrienTooltipWidget->LeveNumber = Level;
		FrienTooltipWidget->LastTimeConnectedText = LastTimeConected;
		FrienTooltipWidget->NoteText = Note;
		FrienTooltipWidget->InitTooltipInfo();

		if (FrienTooltipWidget) {
			TooltipHolder->SetToolTip(FrienTooltipWidget);
		}

	}
}

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

		if (FriendBorder && FriendListEntry) {
			if (FriendListEntry->FriendData.bConnected) {
				FriendBorder->SetBrushColor(OnlineColor);
			}
			else {
				FriendBorder->SetBrushColor(OfflineColor);
			}
		}

		if (FriendListEntry && TooltipHolder) {
			FText LastTimeConnectedText;
			if (FriendListEntry->FriendData.bConnected) {
				LastTimeConnectedText = FText::FromString("Connected");
			}
			else {
				LastTimeConnectedText = FriendListEntry->FriendData.LastTimeConnected;
			}

			SetToolTipWidget(FriendListEntry->FriendData.Level, LastTimeConnectedText, FriendListEntry->FriendData.Note);
		}
	}
}
