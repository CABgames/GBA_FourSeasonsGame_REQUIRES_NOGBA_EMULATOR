////////////////////////////////////////////////////////////
// File: gba_Drawings.c
// Author: Charlie Bullock referencing example projects
// Date Created: 14/11/2018
// Brief: Usability of drawing lines and geomotry
////////////////////////////////////////////////////////////

//Including:
#include "gba_Drawings.h"
#include "gba_MathUtil.h"

//This method draws a rectangle shape at the specified location with specified size and color
void drawRect(u32 a_left, u32 a_top, u32 a_width, u32 a_height, u16 a_color)
{
	for (u32 y = 0; y < a_height; ++y)
	{
		for (u32 x = 0; x < a_width; ++x)
		{
			SCREENBUFFER[(a_top + y) * SCREEN_W + a_left + x] = a_color;
		}
	}
}

//This method draws a circle shape at the specified location with specified size and color
void drawCircle(u32 a_left, u32 a_top, u32 a_width, u32 a_height, u16 a_color)
{
	for (int x = -a_width; x < a_width; ++x)
	{
		for (int y = -a_width; y < a_width; ++y)
		{
			if (x*x + y * y <= a_width * a_width) 
			{
				SCREENBUFFER[(a_top - y) * SCREEN_W + a_left + x] = a_color;
			}
		}
	}
}

//This method draws a line between the specified locations with specified color
void drawLine(s32 a_x, s32 a_y, s32 a_x2, s32 a_y2, u16 a_color)
{
	s32 w = a_x2 - a_x;
	s32 h = a_y2 - a_y;
	s32 dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
	if (w < 0) dx1 = -1; else if (w > 0) dx1 = 1;
	if (h < 0) dy1 = -1; else if (h > 0) dy1 = 1;
	if (w < 0) dx2 = -1; else if (w > 0) dx2 = 1;
	s32 longest = abs(w);
	s32 shortest = abs(h);
	if (!(longest > shortest)) 
	{
		longest = abs(h);
		shortest = abs(w);
		if (h < 0) dy2 = -1; else if (h > 0) dy2 = 1;
		dx2 = 0;
	}
	s32 numerator = longest >> 1;
	for (s32 i = 0; i <= longest; i++) 
	{
		SCREENBUFFER[a_y * SCREEN_W + a_x] = a_color;
		numerator += shortest;
		if (!(numerator < longest)) 
		{
			numerator -= longest;
			a_x += dx1;
			a_y += dy1;
		}
		else 
		{
			a_x += dx2;
			a_y += dy2;
		}
	}
}
