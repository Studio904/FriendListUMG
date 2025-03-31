// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewModel/FriendsViewModel.h"
#include "Structs/Friend.h"

void UFriendsViewModel::SetFriendsTable(const UDataTable* InFriendsTable)
{
	//Holds the original Data from the Data table create in Blueprints
	FriendsTable = const_cast<UDataTable*>(InFriendsTable);
}

TArray<FFriend*> UFriendsViewModel::GetFriendsArray()
{
	TArray<FFriend*> FriendsArray;
	FriendsTable->GetAllRows<FFriend>("", FriendsArray);
	return FriendsArray;
}

FFriend* UFriendsViewModel::GetFriendById(const FString FriendId)
{
	if (!FriendsTable) {
		return nullptr;
	}

	TArray<FFriend*> LocalFriendsArray = GetFriendsArray();
	for (FFriend* Friend : LocalFriendsArray) {
		if (Friend && Friend->Id == FriendId) {
			return Friend;
		}
	}

	return nullptr;
}

void UFriendsViewModel::UpdateFriendList(const FString FriendId, const FFriend* InFriend)
{
	FFriend* OutFriend = GetFriendById(FriendId);

	OutFriend->bConnected = InFriend->bConnected;
	OutFriend->Note = InFriend->Note;
	OutFriend->Level = InFriend->Level;

	OnFriendListChanged.Broadcast(*OutFriend);
}
