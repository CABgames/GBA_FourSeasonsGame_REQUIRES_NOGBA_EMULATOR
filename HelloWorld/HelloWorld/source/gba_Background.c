////////////////////////////////////////////////////////////
// File: gba_Background.c
// Author: Charlie Bullock using help from tutorial projects
// Date Created: 14/11/2018
// Brief: Responsible for loading the different backgrounds using BG map info in addition to collisions
////////////////////////////////////////////////////////////

//Including:
#include "BG_Maps.h"
#include "BG_Palette.h"
#include "BG_Tiles.h"
#include "BG_Collisions.h"
#include "gba_Core.h"
#include "gba_background.h"
#include <string.h>

//Boolean method to check if player collides with collision tiles and return relevant bool value
bool CheckBackgroundCollision(u32 playerX, u32 playerY)
{
	u32 Xtiles = (u32)(playerX >> 4);
	u32 Ytiles = (u32)(playerY >> 4);
	u32 tilesIndex = (Xtiles * 32) + Ytiles;
		//If the tile is a collision tile then return true
		if (bgCollision[tilesIndex] == 0x1000)
		{
			return true;
		}
		else
		{
			return false;
		}
}
//Green background
//Method for loading the scrollinh tile background sky in the game
void LoadMovingBackgroundGreen()
{
	memcpy(pal_bg_mem, bgPalette, 32);
	u16* tileMemoryLoc = tile_block_address(0);
	memcpy(tileMemoryLoc, bgTiles, bgTilesLen << 1);
	u16* tilemapMemoryLocation = tileMap_block_address(16);
	memcpy(tilemapMemoryLocation, bgMap1, bgMapLen1 << 1);
	REG_BGCNT[0] = setBG_Control_Register(-2, 0, 0, A0_4BPP, 16, 0, BG_REG_SIZE_32x32);

}
//Green background
//Method for loading the static tile background in the game
void LoadFloorBackgroundGreen()
{
	memcpy(palette_bg_block_address(32), bgPalette, 32);
	u16* tileMemoryLoc = tile_block_address(1);
	memcpy(tileMemoryLoc, bgTiles, bgTilesLen << 1);
	u16* tilemapMemoryLocation = tileMap_block_address(14);
	memcpy(tilemapMemoryLocation, bgMap2, bgMapLen2 << 1);
	REG_BGCNT[1] = setBG_Control_Register(-2, 1, 0, A0_4BPP, 14, 0, BG_REG_SIZE_32x32);
}
//Red background
//Method for loading the scrolling tile background sky in the game
void LoadMovingBackgroundRed()
{
	memcpy(pal_bg_mem, bgPaletteRed, 32);
	u16* tileMemoryLoc = tile_block_address(0);
	memcpy(tileMemoryLoc, bgTilesRed, bgTilesLenRed << 1);
	u16* tilemapMemoryLocation = tileMap_block_address(16);
	memcpy(tilemapMemoryLocation, bgMap1Red, bgMap1LenRed << 1);
	REG_BGCNT[0] = setBG_Control_Register(-2, 0, 0, A0_4BPP, 16, 0, BG_REG_SIZE_32x32);

}
//Red background
//Method for loading the static tile background in the game
void LoadFloorBackgroundRed()
{
	memcpy(palette_bg_block_address(32), bgPaletteRed, 32);
	u16* tileMemoryLoc = tile_block_address(1);
	memcpy(tileMemoryLoc, bgTilesRed, bgTilesLenRed << 1);
	u16* tilemapMemoryLocation = tileMap_block_address(14);
	memcpy(tilemapMemoryLocation, bgMap2Red, bgMap2LenRed << 1);
	REG_BGCNT[1] = setBG_Control_Register(-2, 1, 0, A0_4BPP, 14, 0, BG_REG_SIZE_32x32);
}
//Blue background 
//Method for loading the scrolling tile background sky in the game
void LoadMovingBackgroundBlue()
{
	memcpy(pal_bg_mem, bgPaletteBlue, 32);
	u16* tileMemoryLoc = tile_block_address(0);
	memcpy(tileMemoryLoc, bgTilesBlue, bgTilesLenBlue << 1);
	u16* tilemapMemoryLocation = tileMap_block_address(16);
	memcpy(tilemapMemoryLocation, bgMap1Blue, bgMapLen1Blue << 1);
	REG_BGCNT[0] = setBG_Control_Register(-2, 0, 0, A0_4BPP, 16, 0, BG_REG_SIZE_32x32);

}
//Blue background 
//Method for loading the static tile background in the game
void LoadFloorBackgroundBlue()
{
	memcpy(palette_bg_block_address(32), bgPaletteBlue, 32);
	u16* tileMemoryLoc = tile_block_address(1);
	memcpy(tileMemoryLoc, bgTilesBlue, bgTilesLenBlue << 1);
	u16* tilemapMemoryLocation = tileMap_block_address(14);
	memcpy(tilemapMemoryLocation, bgMap2Blue, bgMapLen2Blue << 1);
	REG_BGCNT[1] = setBG_Control_Register(-2, 1, 0, A0_4BPP, 14, 0, BG_REG_SIZE_32x32);
}
//White background
//Method for loading the scrolling tile background sky in the game
void LoadMovingBackgroundWhite()
{
	memcpy(pal_bg_mem, bgPaletteWhite, 32);
	u16* tileMemoryLoc = tile_block_address(0);
	memcpy(tileMemoryLoc, bgTilesWhite, bgTilesLenWhite << 1);
	u16* tilemapMemoryLocation = tileMap_block_address(16);
	memcpy(tilemapMemoryLocation, bgMap1White, bgMapLen1White << 1);
	REG_BGCNT[0] = setBG_Control_Register(-2, 0, 0, A0_4BPP, 16, 0, BG_REG_SIZE_32x32);

}
//White background
//Method for loading the static tile background in the game
void LoadFloorBackgroundWhite()
{
	memcpy(palette_bg_block_address(32), bgPaletteWhite, 32);
	u16* tileMemoryLoc = tile_block_address(1);
	memcpy(tileMemoryLoc, bgTilesWhite, bgTilesLenWhite << 1);
	u16* tilemapMemoryLocation = tileMap_block_address(14);
	memcpy(tilemapMemoryLocation, bgMap2White, bgMapLen2White << 1);
	REG_BGCNT[1] = setBG_Control_Register(-2, 1, 0, A0_4BPP, 14, 0, BG_REG_SIZE_32x32);
}