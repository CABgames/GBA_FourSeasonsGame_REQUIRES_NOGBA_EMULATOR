////////////////////////////////////////////////////////////
// File: gba_Math.h
// Author: Utilising example given by Jamie Stewart
// Date Created: 14/11/2018
// Brief: Maths functions and functionality header
////////////////////////////////////////////////////////////
 
#ifndef __GBA_MATH_H__
#define __GBA_MATH_H__

//Including:
#include "gba_Defines.h"

//\---------------------------------------------------------------------------------
//\ Fixed Point mathematics implementation
//\---------------------------------------------------------------------------------

//Define for amount to shift fixed point numbers by, defines number of bits reserved
//for decimal notation. GBA hardware utilises 8.8 fixed values for OAM Affine transforms
#define FIX_SHIFT		8

#define FIX_SCALE		( 1 << FIX_SHIFT	)
#define FIX_MASK		( FIX_SCALE -1		)
#define FIX_SCALEF		( (float)FIX_SCALE	)
#define FIX_SCALEF_INV	( 1.0f/FIX_SCALEF	)

#define FIX_ONE			FIX_SCALE

//using a signed 32 bit value for fixed point 24.8 fixed
//the additional 16 bits compared to the native GBA 8.8 fixed will allow for better numerical accuracy
typedef		s32		fixed;
//functionality to convert 
extern fixed		int2fix(s32 a_i);
extern fixed		float2fix(float a_f);
//convert from fixed point notation to integral value representation
extern u32			fix2uint(fixed a_f);
extern u32			fix2ufrac(fixed a_f);
extern s32			fix2int(fixed a_f);
extern float		fix2float(fixed a_f);

//functions to undertake fixed point addition subtraction, multiplication and division
extern fixed fixAdd(fixed a_f1, fixed a_f2);
extern fixed fixSub(fixed a_f1, fixed a_f2);
extern fixed fixMul(fixed a_f1, fixed a_f2);
extern fixed fixDiv(fixed a_f1, fixed a_f2);

//\-------------------------------------------------------------------------------------
//\ Functionality to handle retrieval of sin/cosine values
//\-------------------------------------------------------------------------------------
extern s32 lu_sin(u32 theta);
extern s32 lu_cos(u32 theta);

#endif//__GBA_MATH_H__
