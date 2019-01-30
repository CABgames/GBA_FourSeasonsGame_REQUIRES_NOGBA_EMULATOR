////////////////////////////////////////////////////////////
// File: gba_Video.c
// Author: Utilising example given by Jamie Stewart
// Date Created: 14/11/2018
// Brief: Gba video such as page flipping bitmaps
////////////////////////////////////////////////////////////

//Including:
#include "gba_Video.h"

//-----------------------------------------------------------------------------
// define video functions and extern variables
//-----------------------------------------------------------------------------

u16* __vid_page = vid_page_back;

//Method for flipping bitmap pages when in correct rendering mode
u16* page_flip()
{
	__vid_page = (u16*)((u32)__vid_page ^ VRAM_PAGE_SIZE);
	REG_DISPLAYCONTROL ^= VIDEO_PAGE; //update video control register
	return __vid_page;
}

vu16 setBG_Control_Register(u8 a_priority, u8 a_tileBlockID, u8 a_mosaic, u8 a_colourMode, u8 a_mapBlockID, u8 a_affineWrap, u8 a_bgSize)
{
	vu16 control = (a_priority & BGCNT_PRIORITY_MASK) | ((a_tileBlockID & BGCNT_TBID_MASK) << 2) | ((a_mosaic & BGCNT_MOS_MASK) << 6) | ((a_colourMode & BGCNT_COLOR_MASK) << 7) |
		((a_mapBlockID & BGCNT_TMID_MASK) << 8) | ((a_affineWrap & BGCNT_AFW_MASK) << 13) | ((a_bgSize & BGCNT_SIZE_MASK) << 14);
	return control;
}