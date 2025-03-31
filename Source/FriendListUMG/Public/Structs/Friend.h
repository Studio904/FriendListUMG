// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Friend.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FRIENDLISTUMG_API FFriend : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString Id;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText NickName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Note;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText LastTimeConnected;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int64 Level;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bConnected;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTexture2D* Image;

};
