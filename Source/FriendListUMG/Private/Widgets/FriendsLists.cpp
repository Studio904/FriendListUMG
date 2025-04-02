// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/FriendsLists.h"
#include "FriendListEntry.h"
#include "Structs/Friend.h"
#include "Engine/DataTable.h"
#include "Components/ListView.h"
#include "ViewModel/FriendsViewModel.h"

void UFriendsLists::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	 

	FDataTableRowHandle test;

	FriendViewModel = NewObject<UFriendsViewModel>();
	FriendViewModel->OnFriendListChanged.AddDynamic(this, &UFriendsLists::HandleOnFriendListChange);
	FriendViewModel->SetFriendsTable(Friends.DataTable);
	TArray<FFriend*> FriendsList = FriendViewModel->GetFriendsArray();

	for (const auto Friend: FriendsList)
	{
		AddFriendToList(*Friend);
	}

	TimerToUpdateFriendStatus();

}

void UFriendsLists::HandleOnFriendListChange(FFriend Friend)
{
	UpdateFriendOnList(Friend);
}

void UFriendsLists::AddFriendToList(const FFriend& Friend)
{
	if (OfflineFriends && OnlineFriends) {
		UFriendListEntry* FriendListEntry = NewObject<UFriendListEntry>();
		FriendListEntry->SetFriendObject(Friend);

		if (Friend.bConnected) {
			OnlineFriends->AddItem(FriendListEntry);
		}
		else {
			OfflineFriends->AddItem(FriendListEntry);
		}
	}
}





void UFriendsLists::UpdateFriendOnList(const FFriend& InFriend)
{
	if (InFriend.bConnected) {
		TArray<UObject*> OfflineFriendsEntryArray = OfflineFriends->GetListItems();
		for (int32 i = 0; UObject* OfflineFriend : OfflineFriendsEntryArray) {
			const UFriendListEntry* CastOfflineFriend = Cast<UFriendListEntry>(OfflineFriend);
			if (InFriend.Id == CastOfflineFriend->FriendData.Id) {
				UObject* FriendToRemove = OfflineFriends->GetItemAt(i);
				OfflineFriends->RemoveItem(FriendToRemove);
			}
		}
	}
	else {
		TArray<UObject*> OnlineFriendsEntryArray = OnlineFriends->GetListItems();
		for (int32 i = 0; UObject* OnlineFriend : OnlineFriendsEntryArray) {
			const UFriendListEntry* CastOnlineFriend = Cast<UFriendListEntry>(OnlineFriend);
			if (InFriend.Id == CastOnlineFriend->FriendData.Id) {
				UObject* FriendToRemove = OnlineFriends->GetItemAt(i);
				OnlineFriends->RemoveItem(FriendToRemove);
			}
		}
	}
	AddFriendToList(InFriend);
}

void UFriendsLists::ToggleOnlineFriendlist()
{

}

void UFriendsLists::ToggleOfflineFriendList()
{

}

void UFriendsLists::TimerToUpdateFriendStatus()
{
	FTimerHandle TimerHandleUpdateFriendStatus;
	GetWorld()->GetTimerManager().SetTimer(TimerHandleUpdateFriendStatus, this, &UFriendsLists::UpdateFriendStatus, 5.0f, true);
}

void UFriendsLists::UpdateFriendStatus()
{
	if (FriendViewModel) {
		TArray<FFriend*> FriendsList = FriendViewModel->GetFriendsArray();
		int32 FriendListSize = FriendsList.Num()-1;
		int32 RandomFriendIndex = FMath::RandRange(0, FriendListSize);
		FFriend FriendAux = *FriendsList[RandomFriendIndex];
		FriendAux.bConnected = !FriendAux.bConnected;

		FriendViewModel->UpdateFriendList(FriendAux.Id, &FriendAux);
	}
}
