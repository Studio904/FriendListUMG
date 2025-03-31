// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FriendListEntry.generated.h"

struct FFriend;

/**
 * 
 */
UCLASS()
class FRIENDLISTUMG_API UFriendListEntry : public UObject
{
	GENERATED_BODY()


public:

	UPROPERTY(EditDefaultsOnly)
	FFriend* FriendData;

	UFUNCTION()
	void SetFriendObject(const FFriend* InFriend);
	
};
