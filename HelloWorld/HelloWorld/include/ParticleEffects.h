////////////////////////////////////////////////////////////
// File: ParticleEffects.h
// Author: Utilising example given by Jamie Stewart modified by Charlie Bullock
// Date Created: 14/11/2018
// Brief: Utilising example given by Jamie Stewart modified by Charlie Bullock
////////////////////////////////////////////////////////////

#ifndef __GBA_PARTICLEEFFECT_H__
#define __GBA_PARTICLEEFFECT_H__

//Including:
#include "gba_Defines.h"
#include "gba_Math.h"

//Structure containing position
typedef struct {
	fixed x, y;
}Emitter;

//Particle structure used for created particles, containes x and y for position in addition to x and y velocity and life of particle time
typedef struct {
	fixed x, y;
	fixed vx, vy;
	u32 life;
}Particle;

//Method for emitting particle effects
void EmitParticle(const Emitter* a_emitter, Particle* a_particle,s8 a_particleState);
//Method for updating particle effects, this is called via a loop for the different particle instance in game manager
void UpdateParticle(const Emitter* a_emitter, Particle* a_particle, s8 a_particleState);

#endif//__GBA_PARTICLEEFFECT_H__