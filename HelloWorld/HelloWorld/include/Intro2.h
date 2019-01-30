////////////////////////////////////////////////////////////
// File: Intro2.h
// Author: Charlie Bullock
// Date Created: 14/11/2018
// Brief:  Intro2 bitmap header file
////////////////////////////////////////////////////////////

//======================================================================
//
//	Intro2, 240x160@8, 
//	+ palette 16 entries, not compressed
//	+ bitmap not compressed
//	Total size: 32 + 38400 = 38432
//
//	Time-stamp: 2018-11-30, 11:04:36
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_INTRO2_H
#define GRIT_INTRO2_H
//Bitmap length
#define Intro2BitmapLen 38400
//Bitmap data
extern const unsigned short Intro2Bitmap[19200];

#define Intro2PalLen 32
extern const unsigned short Intro2Pal[16];

#endif // GRIT_INTRO2_H

//}}BLOCK(Intro2)
