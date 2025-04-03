// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FriendToast.generated.h"

class UTextBlock;
class UImage;

/**
 * 
 */
UCLASS()
class FRIENDLISTUMG_API UFriendToast : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(BindWidget))
	UImage* Avatar;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* NickName;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* Level;


	UFUNCTION()
	void InitToastInfo(UTexture2D* AvatarImage, FText& InNickName, int64& InLevel);
	
};
