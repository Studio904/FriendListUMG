// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/FriendsLists.h"
#include "FriendListEntry.h"
#include "Structs/Friend.h"
#include "Engine/DataTable.h"
#include "Components/ListView.h"
#include "ViewModel/FriendsViewModel.h"
#include "Widgets/FriendToast.h"

void UFriendsLists::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	 

	FDataTableRowHandle test;

	FriendViewModel = NewObject<UFriendsViewModel>();
	FriendViewModel->OnFriendListChanged.AddDynamic(this, &UFriendsLists::HandleOnFriendListChange);
	TArray<FFriend*> FriendsList =  FriendViewModel->SetFriendsTable(Friends.DataTable);
	ArraySize = FriendsList.Num() - 1;

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
		
		ShowToast(InFriend);
	}

	OfflineFriends->ClearListItems();
	OnlineFriends->ClearListItems();
	TArray<FFriend*> FriendsList = FriendViewModel->SetFriendsTable(Friends.DataTable);
	ArraySize = FriendsList.Num() - 1;

	for (const auto Friend : FriendsList)
	{
		AddFriendToList(*Friend);
	}
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
		TArray<FFriend*> FriendsList = FriendViewModel->SetFriendsTable(Friends.DataTable);
		int32 FriendListSize = FriendsList.Num()-1;
		int32 RandomFriendIndex = FMath::RandRange(0, FriendListSize);
		FFriend FriendAux = *FriendsList[RandomFriendIndex];
		FriendAux.bConnected = !FriendAux.bConnected;


		FriendViewModel->UpdateFriendList(FriendAux.Id, &FriendAux);
	}
}

void UFriendsLists::ShowToast(const FFriend& Friend)
{
	if (FriendToastClass) {
		FriendToastWidget = CreateWidget<UFriendToast>(GetWorld(), FriendToastClass);
		

		if (FriendToastWidget)
		{
			FriendToastWidget->NickNameText = Friend.NickName;
			FriendToastWidget->LevelNumber = Friend.Level;
			FriendToastWidget->AvatarImage = Friend.Image;
			FriendToastWidget->InitToastInfo();
			FriendToastWidget->AddToViewport();
			FriendToastWidget->PlayAnim();
			FTimerHandle RemoveFromViewPortHandle;
			GetWorld()->GetTimerManager().SetTimer(RemoveFromViewPortHandle, [this]()
				{
					this->FriendToastWidget->RemoveFromParent();
				}, 4.0f, false);
		}

	}
	
}
