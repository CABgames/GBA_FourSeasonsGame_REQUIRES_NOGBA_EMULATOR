////////////////////////////////////////////////////////////
// File: gba_Collision.h
// Author: <your name>
// Date Created: 14/11/2018
// Brief: <description of the purpose of the file>
////////////////////////////////////////////////////////////
   
#ifndef __GBA_COLLISION_H__
#define __GBA_COLLISION_H__

//Including:
#include "gba_Defines.h"

//Check collision of two 2D rectangular or square objects and return relevant value
bool CheckCollision(u32 a_FirstX, u32 a_FirstY, u32 a_FirstWidth, u32 a_FirstHeight, u32 a_SecondX, u32 a_SecondY, u32 a_SecondWidth, u32 a_SecondHeight);	
//Check collision of two 2D square objects and return relevant value
bool CheckCollisionCube(u32 a_FirstX, u32 a_FirstY, u32 a_FirstSize, u32 a_SecondX, u32 a_SecondY, u32 a_SecondSize);

#endif//__GBA_COLLISION_H__