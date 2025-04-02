// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Structs/Friend.h"
#include "FriendListEntry.generated.h"

/**
 * 
 */
UCLASS()
class FRIENDLISTUMG_API UFriendListEntry : public UObject
{
	GENERATED_BODY()


public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FFriend FriendData;

	void SetFriendObject(const FFriend& InFriend);
	
};
