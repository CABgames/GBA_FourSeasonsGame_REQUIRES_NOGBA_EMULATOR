////////////////////////////////////////////////////////////
// File: gba_Defines.h
// Author: Utilising example given by Jamie Stewart
// Date Created: 14/11/2018
// Brief: <description of the purpose of the file>
////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------
//This file defines the base register addresses for I/O VRAM etc
//This file additionally defines integral types defined for GBA use
//---------------------------------------------------------------------------------

#ifndef __GBA_DEF_H__
#define __GBA_DEF_H__

//Including:
#include <stdint.h>
#include <stdbool.h>

#ifndef	NULL

#define	NULL	(void*)0
#endif


//---------------------------------------------------------------------------------
// Type defines for Integral Data types
//---------------------------------------------------------------------------------
typedef	uint8_t			u8;		/**< Unsigned 8 bit value	*/
typedef	uint16_t		u16;	/**< Unsigned 16 bit value	*/
typedef	uint32_t		u32;	/**< Unsigned 32 bit value	*/
typedef	int8_t			s8;		/**< Signed 8 bit value	*/
typedef	int16_t			s16;	/**< Signed 16 bit value	*/
typedef	int32_t			s32;	/**< Signed 32 bit value	*/
//---------------------------------------------------------------------------------
// Type defines for Volatile Integral Data types -- Registers that may change via hardware
//---------------------------------------------------------------------------------
typedef	volatile u8		vu8;	/**< volatile Unsigned 8 bit value	*/
typedef	volatile u16	vu16;	/**< volatile Unigned 16 bit value	*/
typedef	volatile u32	vu32;	/**< volatile Unsigned 32 bit value	*/
typedef	volatile s8		vs8;	/**< volatile Signed 8 bit value	*/
typedef	volatile s16	vs16;	/**< volatile Signed 8 bit value	*/
typedef	volatile s32	vs32;	/**< volatile Signed 8 bit value	*/
//---------------------------------------------------------------------------------
//Type defines for Screen block entries
//---------------------------------------------------------------------------------
typedef u16 COLOR;
typedef u16 SCR_ENTRY, SE; //Each Screen block entry is a 16 bit value
//define Screen tiles
typedef struct TILE { u32 data[8]; } TILE, TILE4;	//4bpp tiles
typedef struct TILE8 { u32 data[16]; } TILE8;		//8bpp tiles

typedef SCR_ENTRY	SCREENBLOCK[1024];
typedef TILE		TILEBLOCK[512];
typedef TILE8		TILEBLOCK8[256];

//---------------------------------------------------------------------------------
// BASE Defines
//---------------------------------------------------------------------------------
#define INLINE static inline

//---------------------------------------------------------------------------------
// Base Defines for Core membory addresses
//---------------------------------------------------------------------------------
/*
* Define the Base Address for External (on-board) Work RAM (WRAM)
* This is 256K in Size
*/
#define	EWRAM		0x02000000
#define	EWRAM_END	0x02040000 // From This address up to 0x02FFFFFF is not utilised
/*
* Define the Base Address for Internal (on-chip) Work RAM (WRAM)
* This is 32K in Size
*/
#define IWRAM 0x03000000
/*
* Define the Base Address for I/O or Hardware Registers
*
*/
#define REG_BASE 0x04000000
/*
* Define for Hardware Key Input Register
*/
#define REG_KEYINPUT	*(vu16*)(REG_BASE + 0x130)
/*
* Define for Hardware Key Interrupt Control Register
*/
#define REG_KEYCNT		*(vu16*)(REG_BASE + 0x132)

/*
* Define the Base Address for Video RAM (VRAM)
* This is 96K in Size
*/
#define VRAM 0x06000000		// no 8bit write
/*
* Define the Base Address for Cart Save RAM (VRAM)
* This is 64K (Max) in Size
*/
#define	SRAM		0x0E000000



#endif //__GBA_DEF_H__