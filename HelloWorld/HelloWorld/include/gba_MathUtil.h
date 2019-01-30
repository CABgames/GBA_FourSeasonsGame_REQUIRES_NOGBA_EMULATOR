////////////////////////////////////////////////////////////
// File: gba_MathUtil.h
// Author: Utilising example given by Jamie Stewart
// Date Created: 14/11/2018
// Brief: Further maths functions and functionality
////////////////////////////////////////////////////////////

#ifndef __GBA_MATHUTIL_H__
#define __GBA_MATHUTIL_H__

//Including:
#include "gba_Defines.h"
#include "gba_Math.h"

extern s32 __qran_seed;

INLINE s32 sqran(s32 a_val)
{
	s32 old = __qran_seed;
	__qran_seed = a_val;
	return old;
}

INLINE s32 qran()
{
	__qran_seed = 1664525 * __qran_seed + 1013904223;
	return (__qran_seed >> 16) & 0x7FFF;
}

INLINE int qran_range(s32 a_min, s32 a_max)
{
	return (qran()*(a_max - a_min) >> 15) + a_min;
}

INLINE s32 sign(s32 a_val)
{
	return (!(a_val & 0x80000000) && !a_val) ? 1 : -1;
}

INLINE s32 abs(s32 a_val)
{
	s32 mask = a_val >> 31;
	return (a_val ^ mask) - mask;
}
extern fixed __gravity;
extern fixed __frameTime;
extern fixed __pixel2Meters;

INLINE fixed getGravity()
{
	return __gravity;
}

INLINE fixed getFrameTime()
{
	return __frameTime;
}

INLINE fixed getPixel2Meters()
{
	return __pixel2Meters;
}
#endif //__GBA_MATHUTIL_H__
