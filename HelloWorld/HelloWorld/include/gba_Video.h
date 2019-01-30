////////////////////////////////////////////////////////////
// File: gba_Video.h
// Author: <your name>
// Date Created: 14/11/2018
// Brief: <description of the purpose of the file>
////////////////////////////////////////////////////////////

#ifndef __GBA_VIDEO_H__
#define __GBA_VIDEO_H__
		
//Including:
#include "gba_Defines.h"
#include "Intellisense.h"

//Definitions for screen width and height for the bitmap modes
#define SCREEN_WIDTH	240
#define SCREEN_HEIGHT	160
#define M3_WIDTH	SCREEN_WIDTH
#define M3_HEIGHT	SCREEN_HEIGHT
#define M4_WIDTH	SCREEN_WIDTH
#define M4_HEIGHT	SCREEN_HEIGHT
#define M5_WIDTH	160
#define M5_HEIGHT	128

// Register for display control
#define REG_DISPLAYCONTROL *((vu32*)(REG_BASE))
// Defines for video modes
#define VIDEOMODE_0 0x0000	//Tile Mode
#define VIDEOMODE_1 0x0001	//Tile Mode
#define VIDEOMODE_2 0x0002	//Tile Mode
#define VIDEOMODE_3 0x0003	// < Mode 3; 240x160 @16bpp
#define VIDEOMODE_4	0x0004	// < Mode 4; 240x160 @8 bpp
#define VIDEOMODE_5 0x0005  // < Mode 5; 
//background identifier defines
#define BGMODE_0	0x0100
#define BGMODE_1	0x0200
#define BGMODE_2	0x0400
#define BGMODE_3	0x0800

#define REG_VCOUNT (*(vu16*)(REG_BASE + 0x06))

#define VIDEO_PAGE			0x0010	//!< Page indicator

#define VRAM_PAGE_SIZE		0x0A000
#define VRAM_BACK	(VRAM+ VRAM_PAGE_SIZE)

// Palette memory location define
#define MEM_PALETTE		0x05000000
//defines for memory location of background and sprite palette memory
#define pal_bg_mem		((u16*)MEM_PALETTE)
#define pal_sp_mem		((u16*)(MEM_PALETTE+0x0200))
//on modes that support page flipping defines for video memory and front/back page locations
#define vid_mem			((u16*)VRAM)
#define vid_page_front	((u16*)VRAM)
#define vid_page_back	((u16*)VRAM_BACK)

//---------------------------------------------------------------------------------
// tile memory defines for 4bpp & 8bpp
#define tile_mem  ((TILEBLOCK*)0x06000000)
#define tile8_mem ((TILEBLOCK8*)0x06000000)


//---------------------------------------------------------------------------------
extern u16* __vid_page;
u16* page_flip();
//---------------------------------------------------------------------------------
INLINE void vsync()
{
	while (REG_VCOUNT >= 160); //wait till VDraw
	while (REG_VCOUNT < 160);  //wait till VBLANK
}

//---------------------------------------------------------------------------------
//Background control registers and functionality
//---------------------------------------------------------------------------------
//define a base registry address for the background controllers
//accessing this as REG_BGCNT[0] is controller 0
//accessing this as REG_BGCNT[1] is controller 1 or memory address REG_BGCNT + (sizeof(vu16) * 1) = 0x0400:000A
//accessing this as REG_BGCNT[2] is controller 2 or memory address REG_BGCNT + (sizeof(vu16) * 2) = 0x0400:000C
//accessing this as REG_BGCNT[3] is controller 3 or memory address REG_BGCNT + (sizeof(vu16) * 3) = 0x0400:000E
#define REG_BGCNT ((vu16*)(REG_BASE+0x0008))

//structure to control background offset x & y flags
typedef struct BackgroundOffsets
{
	s16 x, y;
}__attribute__((packed, aligned(4))) BGOffset;

//set up define for REG_BG_OFS accessed as an array to access offset data for bg 0-3 
//REG_BG_OFS[1].x accesses x .y accesses y value
#define REG_BG_OFS  ((BGOffset*)(REG_BASE+0x0010))

#define TILE_BLOCK_SIZE 0x4000
#define TILEMAP_BLOCK_SIZE 0x0800
//function to return the memory address (pointer) to one of the four tile block locations (0-3)
INLINE u16* tile_block_address(u32 a_blockNum)
{
	//each block is 16KB in size
	return (u16*)(VRAM + (a_blockNum * TILE_BLOCK_SIZE));
}
//function to return a pointer to address space for the tile map blocks location (0-31)
INLINE u16* tileMap_block_address(u32 a_blockNum)
{
	//each tilemap block is 2KB in size
	return (u16*)(VRAM + (a_blockNum * TILEMAP_BLOCK_SIZE));
}

#define BGCNT_PRIORITY_MASK 0x3
#define BGCNT_TBID_MASK		0x3
#define BGCNT_MOS_MASK		0x1
#define BGCNT_COLOR_MASK	0x1
#define BGCNT_TMID_MASK		0x1F
#define BGCNT_AFW_MASK		0x1
#define BGCNT_SIZE_MASK		0x3

#define BG_REG_SIZE_32x32 0x0
#define BG_REG_SIZE_64x32 0x1
#define BG_REG_SIZE_32x64 0x2
#define BG_REG_SIZE_64x64 0x3

vu16 setBG_Control_Register(u8 a_priority, u8 a_tileBlockID, u8 a_mosaic, u8 a_colourMode, u8 a_mapBlockID, u8 a_affineWrap, u8 a_bgSize);

INLINE u16* palette_bg_block_address(u32 a_blockNum)
{
	//the multiply 16 is due to each palette block having 16 entries per row for a total of 256 colours
	return (u16*)(pal_bg_mem + (a_blockNum * 16));
}

INLINE u16* palette_sp_block_address(u32 a_blockNum)
{
	//the multiply 16 is due to each palette block having 16 entries per row for a total of 256 colours
	return (u16*)(pal_sp_mem + (a_blockNum * 16));
}

INLINE u16* sprite_tile_block_address(u32 a_tile_number)
{
	//each block is 16KB in size sprites occur on block 4 of tile memory (blocks 0-3 are for bg tiles)
	return (u16*)(VRAM + (4 * TILE_BLOCK_SIZE) + ((a_tile_number & 0x3FF) * sizeof(TILE)));

}

#endif//__GBA_VIDEO_H__