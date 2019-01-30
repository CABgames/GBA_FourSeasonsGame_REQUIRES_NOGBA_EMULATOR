////////////////////////////////////////////////////////////
// File: SeasonTree.c
// Author: Charlie Bullock
// Date Created: 14/11/2018
// Brief: Season tree sprites header
////////////////////////////////////////////////////////////

//======================================================================
//
//	SeasonTree, 32x32@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2018-12-04, 15:50:34
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SEASONTREE_H
#define GRIT_SEASONTREE_H

//Autumn season tree sprite tile data
#define SeasonTreeTilesLen 512
extern const unsigned short SeasonTreeTiles[256];
//Autumn season tree sprite palette data
#define SeasonTreePalLen 32
extern const unsigned short SeasonTreePal[16];
//Spring season tree sprite tile data
#define SeasonTreeColdTilesLen 512
extern const unsigned short SeasonTreeColdTiles[256];
//Spring season tree sprite palette data
#define SeasonTreeColdPalLen 32
extern const unsigned short SeasonTreeColdPal[16];
//Winter season tree sprite tile data
#define SeasonTreeSpringTilesLen 512
extern const unsigned short SeasonTreeSpringTiles[256];
//Winter season tree sprite palette data
#define SeasonTreeSpringPalLen 32
extern const unsigned short SeasonTreeSpringPal[16];
//Summer season tree sprite tile data
#define SeasonTreeSummerTilesLen 512
extern const unsigned short SeasonTreeSummerTiles[256];
//Summer season tree sprite palette data
#define SeasonTreeSummerPalLen 32
extern const unsigned short SeasonTreeSummerPal[16];

#endif // GRIT_SEASONTREE_H