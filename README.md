# UMG
![2025-04-0319-29-46-ezgif com-video-to-gif-converter (1)](https://github.com/user-attachments/assets/3ede3f11-d8d3-49a9-9036-0ef4af0c7d0c)

## Project 
A Friend List that updates itself with their connection status every 5 seconds. 

## Tasks
1. Create a struct for Friend which includes all the properties of a friend status : (Avatar, NickName, Level, and more)
2. Create a View Model Object where the List of Friends is held and where those are updated respectively
3. Create ListData Entry required view the ViewList to add and update the list. 
4. Create the Friend Row widgets based on this Object List data Entry
5. Create the Lists Widget with the UListView component for online and offline friends.
6. Do a POC in blueprint with the current widgets to evaluate the functionality of UListView
7. Create Functionalities to update the list of friends and the friend connection status.
8. Create functionalities to add the updated friend to the UListView.
9. Removed BluePrint POC.
10. Create Toast and Hover Widgets and create Blueprints POC.
11. Implement functionalities in the FriendRow Widget to show a tooltip (Hover) and the Toast in the FriendLists Widget.
12. Apply design and add assets of all widgets.
13. Add animation on both C++ and blueprint for toast and hide and show friends list.
14. Clean up code. 


## Features
- MVVM Pattern
- UListView
- ObjectListViewEntry
- Dynamic creation of row Widgets
- Single source of truth with Data Table
  

## Installation
1. Clone repository:
   ```bash
   git clone https://github.com/DaStickMan/UMG_UIExercise.git
   ```
2. Open in Unreal Engine 5.3+

## Issue found in the way
- The UList View RemoveItem() does not work properly, I have to use the clearList and with the DataTable reRender the list.
- The binding of the delegate in the service that uses the model is unbound randomly, where the update is sudden.
- The Use of ObjectListEntry Class to add items and remove them from the UListView. 
---
⭐ Star this is you project to look for new updates and improvements
