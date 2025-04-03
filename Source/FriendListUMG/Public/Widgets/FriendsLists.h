// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../FriendListEntry.h"
#include "Engine/DataTable.h"
#include "FriendsLists.generated.h"

class UListView;
class UButton;
class UFriendsViewModel;
struct FFriend;
class UFriendToast;

/**
 * 
 */
UCLASS()
class FRIENDLISTUMG_API UFriendsLists : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(RowType="Friend"))
	FDataTableRowHandle Friends;

	UPROPERTY(EditAnywhere, Category = "Friends")
	TSubclassOf<UFriendListEntry> FriendListEntryClass; 

	UPROPERTY(EditAnywhere, Category = "Friends")
	TSubclassOf<UFriendToast> FriendToastClass;

	virtual void NativeOnInitialized() override;

protected: 
	UPROPERTY(meta=(BindWidget))
	UListView* OfflineFriends;

	UPROPERTY(meta=(BindWidget))
	UButton* OfflineFriendsBtn;

	UPROPERTY(meta=(BindWidget))
	UListView* OnlineFriends;

	UPROPERTY(meta=(BindWidget))
	UButton* OnlineFriendsBtn;

	UFriendsViewModel* FriendViewModel;

	void AddFriendToList(const FFriend& Friend);
	void UpdateFriendOnList(const FFriend& Friend);


private: 

	UFriendToast* FriendToastWidget;
	int32 ArraySize;

	UFUNCTION()
	void HandleOnFriendListChange(FFriend Friend);

	UFUNCTION()
	void ToggleOnlineFriendlist();

	UFUNCTION()
	void ToggleOfflineFriendList();

	UFUNCTION()
	void TimerToUpdateFriendStatus();

	UFUNCTION()
	void UpdateFriendStatus();

	UFUNCTION()
	void ShowToast(const FFriend& Friend);
};
