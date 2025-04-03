// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/FriendTooltip.h"
#include "../../../../../../../Source/Runtime/UMG/Public/Components/TextBlock.h"

void UFriendTooltip::InitTooltipInfo()
{
	if (Level && LeveNumber) {
		FText LevelText = FText::AsNumber(LeveNumber);
		Level->SetText(LevelText);
	}

	if (Note) {
		Note->SetText(NoteText);
	}

	if (LastTimeConnected) {
		LastTimeConnected->SetText(LastTimeConnectedText);
	}
}
