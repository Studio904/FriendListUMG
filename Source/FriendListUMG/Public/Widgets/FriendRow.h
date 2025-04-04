// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "FriendRow.generated.h"

class UImage;
class UTextBlock;
class UHorizontalBox;
class UBorder;

/**
 * 
 */
UCLASS()
class FRIENDLISTUMG_API UFriendRow : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FLinearColor OnlineColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FLinearColor OfflineColor;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> FriendToolTipWidgetClass;

protected:

	UPROPERTY(meta=(BindWidget))
	UImage* Avatar;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* NickName;

	UPROPERTY(meta=(BindWidget))
	UBorder* FriendBorder;

	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* TooltipHolder;

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject);

private:
	void SetToolTipWidget(int64& Level, FText& LastTimeConected, FText& Note);
	
};
