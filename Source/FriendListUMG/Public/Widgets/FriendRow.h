// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "FriendRow.generated.h"

class UImage;
class UTextBlock;
class UHorizontalBox;

/**
 * 
 */
UCLASS()
class FRIENDLISTUMG_API UFriendRow : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(BindWidget))
	UImage* Avatar;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* NickName;

	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* TooltipHolder;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> FriendToolTipWidgetClass;

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject);

private:
	void SetToolTipWidget(int64& Level, FText& LastTimeConected, FText& Note);
	
};
