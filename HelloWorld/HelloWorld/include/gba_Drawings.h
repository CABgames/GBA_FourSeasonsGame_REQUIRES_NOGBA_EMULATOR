////////////////////////////////////////////////////////////
// File: gba_Drawings.h
// Author: <your name>
// Date Created: 14/11/2018
// Brief: <description of the purpose of the file>
////////////////////////////////////////////////////////////

#ifndef __GBA_DRAWINGS_H__
#define __GBA_DRAWINGS_H__

//Including:
#include "gba_defines.h"

#define SCREENBUFFER ((vu16*)(VRAM))

//Screen width and height definitions
#define SCREEN_W 240
#define SCREEN_H 160

//Getting and returning color values via RGB values
INLINE u16 setColor(u8 a_red, u8 a_green, u8 a_blue)
{
	return (a_red & 0x1F) | (a_green & 0x1F) << 5 | (a_blue & 0x1f) << 10;
}
//This method draws a rectangle shape at the specified location with specified size and color
void drawRect(u32 a_left, u32 a_top, u32 a_width, u32 a_height, u16 a_color);
//This method draws a circle shape at the specified location with specified size and color
void drawCircle(u32 a_left, u32 a_top, u32 a_width, u32 a_height, u16 a_color);
//This method draws a line between the specified locations with specified color
void drawLine(s32 a_x, s32 a_y, s32 a_x2, s32 a_y2, u16 a_color);


#endif//__GBA_DRAWINGS_H__