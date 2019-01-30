////////////////////////////////////////////////////////////
// File: Pause.h
// Author: Charlie Bullock
// Date Created: 14/11/2018
// Brief: Main menu header file
////////////////////////////////////////////////////////////

//======================================================================
//
//	Pause, 240x160@8, 
//	+ palette 16 entries, not compressed
//	+ bitmap not compressed
//	Total size: 32 + 38400 = 38432
//
//	Time-stamp: 2018-11-23, 10:03:28
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PAUSE_H
#define GRIT_PAUSE_H

#define PauseBitmapLen 38400
extern const unsigned short PauseBitmap[19200];

#define PausePalLen 32
extern const unsigned short PausePal[16];

#endif // GRIT_PAUSE_H