// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FriendTooltip.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class FRIENDLISTUMG_API UFriendTooltip : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(meta=(BindWidget))
	UTextBlock* LastTimeConnected;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* Note;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* Level;

	FText LastTimeConnectedText;
	FText NoteText;
	int64 LeveNumber;

	UFUNCTION()
	void InitTooltipInfo();
	
};
