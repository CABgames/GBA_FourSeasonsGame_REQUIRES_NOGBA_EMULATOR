////////////////////////////////////////////////////////////
// File: gba_OAM.c
// Author: Utilising example given by Jamie Stewart
// Date Created: 14/11/2018
// Brief: OAM
////////////////////////////////////////////////////////////

//Including:
#include "gba_OAM.h"

ObjectAttributes obj_buffer[128];
ObjectAffine *const obj_aff_buffer = (ObjectAffine*)obj_buffer;

void obj_hide(ObjectAttributes* a_obj)
{
	a_obj->attr0 = (a_obj->attr0 & A0_MODE_MASK) | (A0_MODE_HIDE << 8);
}

//! Unhide an object.
void obj_unhide(ObjectAttributes* a_obj, u8 mode)
{
	a_obj->attr0 = (a_obj->attr0 & A0_MODE_MASK) | ((mode & 0x3) << 8);
}

void oam_init(ObjectAttributes* obj, u8 count)
{
	u32 nn = count;
	ObjectAttributes *dst = obj;

	// Hide each object
	while (nn--)
	{
		dst->attr0 = 0;
		dst->attr1 = 0;
		dst->attr2 = 0;
		dst->pad = 0;
		obj_hide(dst);
		++dst;
	}
	// init oam
	oam_copy(MEM_OAM, obj, count);
}

void oam_copy(ObjectAttributes* a_dst, ObjectAttributes* a_src, u8 a_count)
{

	u32 *dstw = (u32*)a_dst, *srcw = (u32*)a_src;
	while (a_count--)
	{
		*dstw++ = *srcw++;
		*dstw++ = *srcw++;
	}

}


//set the affine object matrix to an identity matrix
void obj_aff_identity(ObjectAffine* a_obj)
{
	a_obj->pa = 0x01001;		a_obj->pb = 0;
	a_obj->pc = 0;			a_obj->pd = 0x0100;
}

//set the rotation and scale of the object 
//uses the sine look up table to retrieve a value for sine & cosine
void obj_aff_rotscale(ObjectAffine* oaff, fixed sx, fixed sy, u16 alpha)
{
	int ss = lu_sin(alpha), cc = lu_cos(alpha);
	//shifts values down 12 to account for fixed point multiply to keep values as .8 fixed
	oaff->pa = cc * sx >> 12;	oaff->pb = -ss * sx >> 12;
	oaff->pc = ss * sy >> 12;	oaff->pd = cc * sy >> 12;
}