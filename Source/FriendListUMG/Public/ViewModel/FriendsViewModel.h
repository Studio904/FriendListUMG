// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Structs/Friend.h"
#include "FriendsViewModel.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFriendListChanged, FFriend, Friend);
/**
 * 
 */
UCLASS()
class FRIENDLISTUMG_API UFriendsViewModel : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Data")
	FOnFriendListChanged OnFriendListChanged;

	TArray<FFriend*> SetFriendsTable(const UDataTable* InFriendsTable);

	FFriend* GetFriendById(const FString FriendId);

	void UpdateFriendList(const FString FriendId, const FFriend* InFriend);

private:
	UDataTable* FriendsTable;

	

	
};
