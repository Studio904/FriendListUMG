// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FriendToast.generated.h"

class UTextBlock;
class UImage;
class UWidgetAnimation;

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

	FText NickNameText;
	int64 LevelNumber;
	UTexture2D* AvatarImage;


	UFUNCTION()
	void InitToastInfo();

	UFUNCTION()
	void PlayAnim();


private:
	UPROPERTY(Transient, meta=(BindWidgetAnim))
	UWidgetAnimation* FadeInAnim;
	
};
