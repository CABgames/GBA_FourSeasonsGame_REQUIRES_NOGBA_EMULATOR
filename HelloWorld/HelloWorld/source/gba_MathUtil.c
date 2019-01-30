////////////////////////////////////////////////////////////
// File: gba_MathUtil.c
// Author: Utilising example given by Jamie Stewart
// Date Created: 14/11/2018
// Brief: Further maths functions and functionality
////////////////////////////////////////////////////////////

//Including:
#include "gba_MathUtil.h"

s32 __qran_seed = 42;

//declare our external values 
fixed __gravity = -0x9CC;
fixed __frameTime = 0x04;
//Every 5 pixels is one metre
fixed __pixel2Meters = 5 << 8;