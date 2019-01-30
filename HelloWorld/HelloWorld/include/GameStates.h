////////////////////////////////////////////////////////////
// File: GameStates.h
// Author: Charlie Bullock using help from provided tutorials and exaple projects
// Date Created: 14/11/2018
// Brief: This is the header of most critical file in the solution responsible for the different game states and functionality of the project
////////////////////////////////////////////////////////////
#ifndef __GAMESTATES_H__
#define __GAMESTATES_H__

//Including:
#include "gba_Core.h" 
#include "gba_Background.h" 

//Enum for the four season states which shall be switched between in a switch statement in main game
enum STATES
{
	AUTUMN = 0,
	WINTER = 1,
	SPRING = 2,
	SUMMER = 3,
}STATES;

//Method responsible for short startup intro, in this method images are switched between into two images in order to show
void Intro();
//This is the method responsible for main menu and is reached after the intro has completed, this simply displays a bitrmap image and checks for input
void MainMenu();
//This is the method responsible for the pause state of the game which is reached inbetween returning the menu from the main game function, this simply displays a bitrmap image and checks for input
void Pause();
// This is the method responsible for the main state of the game and most of its aspects such as input, particles, season changing, etc
void Game();

#endif//__GAMESTATES_H__