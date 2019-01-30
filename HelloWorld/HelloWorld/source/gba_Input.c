////////////////////////////////////////////////////////////
// File: gba_Input.c
// Author: Utilising example given by Jamie Stewart
// Date Created: 14/11/2018
// Brief: Managing gba input
////////////////////////////////////////////////////////////

//Including:
#include "gba_Input.h"

//-----------------------------------------------------------------------------
//Define Extern variables for key input
//-----------------------------------------------------------------------------
//provide declarations for the extern values for key values
u16 __input_currKeys = 0, __input_prevKeys = 0;