////////////////////////////////////////////////////////////
// File: gba_Collision.c
// Author: Charlie Bullock utilising example project
// Date Created: 14/11/2018
// Brief: In game collision
////////////////////////////////////////////////////////////

//Including:
#include "gba_Collision.h"

//Check collision of two 2D rectangular or square objects and return relevant value
bool CheckCollision(u32 a_FirstX, u32 a_FirstY, u32 a_FirstWidth, u32 a_FirstHeight, u32 a_SecondX, u32 a_SecondY, u32 a_SecondWidth, u32 a_SecondHeight) {
	if (a_FirstX + a_FirstWidth < a_SecondX || a_FirstWidth > a_SecondX + a_SecondWidth) return false;
	if (a_FirstY + a_FirstHeight < a_SecondY || a_FirstHeight > a_SecondY + a_SecondHeight) return false;
	return false;
}
//Check collision of two 2D square objects and return relevant value
bool CheckCollisionCube(u32 a_FirstX, u32 a_FirstY, u32 a_FirstSize, u32 a_SecondX, u32 a_SecondY, u32 a_SecondSize) {
	return !(a_FirstX > (a_SecondX + a_SecondSize)
		|| (a_FirstX + a_FirstSize) < a_SecondX
		|| a_FirstY > (a_SecondY + a_SecondSize)
		|| (a_FirstY + a_FirstSize) < a_SecondY);
}

