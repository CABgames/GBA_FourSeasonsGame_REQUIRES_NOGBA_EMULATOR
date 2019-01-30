////////////////////////////////////////////////////////////
// File: particles.h
// Author: Created by Jamie Stewart, modified and improved by Charlie Bullock
// Date Created: 14/11/2018
// Brief: Particles sprite header file
////////////////////////////////////////////////////////////

//======================================================================
//
//	particles, 64x16@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2017-11-08, 11:55:36
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PARTICLES_H
#define GRIT_PARTICLES_H

//Particles tiles length
#define particlesTilesLen 512
//Particle tile data
extern const unsigned short particlesTiles[256];
//Particles pallette length
#define particlesPalLen 32
//Spring palette
extern const unsigned short particlesPal[16];
//Winter palette
extern const unsigned short particlesPal2[16];
//Autumn palette
extern const unsigned short particlesPal3[16];
//Summer palette
extern const unsigned short particlesPal4[16];

#endif // GRIT_PARTICLES_H