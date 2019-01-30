////////////////////////////////////////////////////////////
// File: gba_OAM.h
// Author: Utilising example given by Jamie Stewart
// Date Created: 14/11/2018
// Brief: <description of the purpose of the file>
////////////////////////////////////////////////////////////

#ifndef __GBA_OAM_H__
#define __GBA_OAM_H__

//Including:
#include "Intellisense.h"
#include "gba_Defines.h"
#include "gba_Math.h"

#define ENABLE_OBJECTS 0x1000
#define MAPPINGMODE_1D 0x0040

typedef struct ObjectAttributes {
	u16 attr0;
	u16 attr1;
	u16 attr2;
	s16 pad;
}__attribute__((packed, aligned(4))) ObjectAttributes;

typedef struct ObjectAffine {
	u16 fill0[3];
	s16 pa;
	u16 fill1[3];
	s16 pb;
	u16 fill2[3];
	s16 pc;
	u16 fill3[3];
	s16 pd;

}__attribute__((packed, aligned(4)))ObjectAffine;

extern ObjectAttributes obj_buffer[128];
extern ObjectAffine *const obj_aff_buffer;

#define MEM_OAM ((ObjectAttributes*) 0x07000000)
#define MEM_AFF_OAM ((ObjectAffine*) 0x07000000)

#define A0_YMASK 0xFF
#define A0_MODE_MASK 0xFCFF
//defines for Object mode - affine or regular, or double size affine
#define A0_MODE_REG		0x00
#define A0_MODE_AFF		0x01
#define A0_MODE_HIDE	0x02
#define A0_MODE_AFF_DBL 0x03



#define A0_YMASK 0xFF
//colour mode defines
#define A0_4BPP 0x0
#define A0_8BPP 0x1
//sprite shape
#define A0_SQUARE 0x00
#define A0_WIDE   0x01
#define A0_TALL   0x02
//x position mask
//\---------------------------------------------------------------------------------
//\Name: gba_OAM.h
//\Description:
//\Date: 15/11/2018
//\---------------------------------------------------------------------------------

#define A1_XMASK 0x1FF
#define A1_FLIPMASK 0x3
#define A1_SIZE_0 0x00
#define A1_SIZE_1 0x01
#define A1_SIZE_2 0x02
#define A1_SIZE_3 0x03
#define A1_AFF_INDEX_MASK 0x1F

INLINE u16 SetAttrib0(u8 a_y, u8 a_objMode, u8 a_gfxMode, u8 a_mosaic, u8 a_colorMode, u8 a_shape)
{
	u16 attrib0 = (a_y & A0_YMASK) | ((a_objMode & 0x3) << 8) | ((a_gfxMode & 0x3) << 10) |
		((a_mosaic & 0x1) << 12) | ((a_colorMode & 0x1) << 13) | ((a_shape & 0x3) << 14);
	return attrib0;
}

INLINE u16 SetAttrib1(u8 a_x, u8 a_flip, u8 a_size)
{
	u16 attrib1 = (a_x & A1_XMASK) | ((a_flip & A1_FLIPMASK) << 12) | ((a_size & 3) << 14);
	return attrib1;
}

INLINE u16 SetAttrib2(u8 a_tileIndex, u8 a_priority, u8 a_paletteBank)
{
	u16 attrib2 = (a_tileIndex & 0x3FF) | ((a_priority & 3) << 10) | ((a_paletteBank & 0xF) << 12);
	return attrib2;
}

INLINE void SetObjectPosition(ObjectAttributes* a_object, u8 a_x, u8 a_y)
{
	a_object->attr0 = (a_object->attr0 & 0xFF00) | (a_y & 0x00FF);
	a_object->attr1 = (a_object->attr1 & 0xFE00) | (a_x & 0x01FF);
}

INLINE void SetAttrib1AffineIndex(ObjectAttributes* a_object, u8 a_index)
{
	//use 0xC1FF to strip out bits 9 -> D
	a_object->attr1 = (a_object->attr1 & 0xC1FF) | ((a_index & A1_AFF_INDEX_MASK) << 9);
}

extern void obj_hide(ObjectAttributes* a_obj);
//! Unhide an object.
extern void obj_unhide(ObjectAttributes* a_obj, u8 mode);
extern void oam_init(ObjectAttributes* obj, u8 count);
extern void oam_copy(ObjectAttributes* a_dst, ObjectAttributes* a_src, u8 a_count);

//set the affine object matrix to an identity matrix
extern void obj_aff_identity(ObjectAffine* a_obj);
//set the rotation and scale of the object 
//uses the sine look up table to retrieve a value for sine & cosine
extern void obj_aff_rotscale(ObjectAffine* oaff, fixed sx, fixed sy, u16 alpha);

#endif//__GBA_OAM_H__