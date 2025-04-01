// Fill out your copyright notice in the Description page of Project Settings.


#include "FriendListEntry.h"
#include "Structs/Friend.h"

void UFriendListEntry::SetFriendObject(const FFriend* InFriend)
{
	FriendData = *InFriend;
}
