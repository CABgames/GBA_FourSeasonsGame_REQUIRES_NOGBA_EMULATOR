////////////////////////////////////////////////////////////
// File: gba_Input.h
// Author: <your name>
// Date Created: 14/11/2018
// Brief: 
////////////////////////////////////////////////////////////

#ifndef __GBA_INPUT_H__
#define __GBA_INPUT_H__
			  
//Including:
#include "gba_Defines.h"

//---------------------------------------------------------------------------------
//Typedef for GBA physical inputs 
typedef enum KEYS
{
	A = (1 << 0),
	B = (1 << 1),
	SELECT = (1 << 2),
	START = (1 << 3),
	RIGHT = (1 << 4),
	LEFT = (1 << 5),
	UP = (1 << 6),
	DOWN = (1 << 7),
	R = (1 << 8),
	L = (1 << 9),

	KEYIRQ_ENABLE = (1 << 14),	/*!< Enable keypad interrupt */
	KEYIRQ_OR = (0 << 15),		/*!< interrupt logical OR mode */
	KEYIRQ_AND = (1 << 15),		/*!< interrupt logical AND mode */


}KEYS;
//---------------------------------------------------------------------------------
//Key mask to and with the Register for Key input on the GBA to test for key presses
#define KEY_MASK 0x03FF // 0b001111111111
//---------------------------------------------------------------------------------
//Externed Vars to hold the current and previous state of the hardware keys
//These values should be defined in main.c prior to use
//Global variable allows for use without an instance of an object - no OO here!
extern u16 __input_currKeys, __input_prevKeys;

//---------------------------------------------------------------------------------
//Function to test for Hardware Key Depress
// Stores value in __currentKeys as previous frames key values then
// uses bitwise and to get latest values from input register
INLINE void PollKeys()
{
	__input_prevKeys = __input_currKeys;
	__input_currKeys = ~REG_KEYINPUT & KEY_MASK;
}
//---------------------------------------------------------------------------------
INLINE u16		input_currentKeyState() { return __input_currKeys; }
INLINE u16		input_prevKeyState() { return __input_prevKeys; }
INLINE u32		input_keyDown(u32 a_key) { return __input_currKeys & a_key; }
INLINE u32		input_keyUp(u32 a_key) { return ~__input_currKeys & a_key; }
INLINE u32		input_keyHeld(u32 a_key) { return (__input_currKeys & __input_prevKeys) & a_key; }
INLINE u32		input_keyReleased(u32 a_key) { return (~__input_currKeys & __input_prevKeys) & a_key; }
INLINE u32		input_keyHit(u32 a_key) { return (__input_currKeys & ~__input_prevKeys) & a_key; }
INLINE u32		input_keyStateChange(u32 a_key) { return (__input_currKeys ^ __input_prevKeys) & a_key; }

//---------------------------------------------------------------------------------
//Define a horizontal and vertical axis to enable functionality to test for axis aligned
//input values
typedef enum INPUT_AXIS
{
	HORIZONTAL = 0,
	VERTICAL

}AXIS;
//---------------------------------------------------------------------------------
// getAxis(s32) function to get an input value -1,0,1 for axis input values
INLINE s32		input_getAxis(AXIS a_val)
{
	switch (a_val)
	{
	case HORIZONTAL:
		//shift __currKeys down 4 to move the value for RIGHT to the lowest bit & with 1 do the same for LEFT and subtract
		//if right is pressed the equation becomes 1 - 0 = 1, if Left is pressed then 0 - 1 = -1.
		return ((__input_currKeys >> 4) & 1) - ((__input_currKeys >> 5) & 1);
	case VERTICAL:
		//This is the same logic as above however uses UP and DOWN.
		return ((__input_currKeys >> 6) & 1) - ((__input_currKeys >> 7) & 1);
	default:
		return 0;
	}
}

#endif//__GBA_INPUT_H__