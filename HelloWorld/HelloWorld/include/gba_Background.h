////////////////////////////////////////////////////////////
// File: gba_Background.h
// Author: <your name>
// Date Created: 14/11/2018
// Brief: Responsible for loading the different backgrounds using BG map info in addition to collisions
////////////////////////////////////////////////////////////

#ifndef __GBA_BACKGROUND_H__
#define __GBA_BACKGROUND_H__

//Boolean method to check if player collides with collision tiles and return relevant bool value
bool CheckBackgroundCollision(u32 playerX, u32 playerY);
//Green background
//Method for loading the scrollinh tile background sky in the game
void LoadMovingBackgroundGreen();
//Green background
//Method for loading the static tile background in the game
void LoadFloorBackgroundGreen();
//Red background
//Method for loading the scrolling tile background sky in the game
void LoadMovingBackgroundRed();
//Red background
//Method for loading the static tile background in the game
void LoadFloorBackgroundRed();
//Blue background 
//Method for loading the scrolling tile background sky in the game
void LoadMovingBackgroundBlue();
//Blue background 
//Method for loading the static tile background in the game
void LoadFloorBackgroundBlue();
//White background
//Method for loading the scrolling tile background sky in the game
void LoadMovingBackgroundWhite();
//White background
//Method for loading the static tile background in the game
void LoadFloorBackgroundWhite();
#endif//__GBA_ASSETS_H__