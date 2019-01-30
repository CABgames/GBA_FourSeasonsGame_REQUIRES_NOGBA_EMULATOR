////////////////////////////////////////////////////////////
// File: ParticleEffects.c
// Author: Original example by Jamie Stewart, modified by Charlie Bullock
// Date Created: 14/11/2018 
// Brief: This C file is responsible for emitting and updating the particle fx for the game 
////////////////////////////////////////////////////////////

//Including:
#include "ParticleEffects.h"
#include "gba_MathUtil.h"

//Method for emitting particle effects
void EmitParticle(const Emitter* a_emitter, Particle* a_particle, s8 a_particleState)
{
	a_particle->x = a_emitter->x; //Set particle position to the emmiter
	a_particle->y = a_emitter->y;

	//Setting up particles width and range by assigning it these values, these vary depending upon the tree season
	if (a_particleState == 0)
	{
		a_particle->vx = int2fix(qran_range(-30, 30)); 
		a_particle->vy = int2fix(25 + qran_range(0,5));
	}
	else if (a_particleState == 1)
	{
		a_particle->vx = int2fix(qran_range(-20, 20));
		a_particle->vy = int2fix(20 + qran_range(0, 5));
	}
	else if (a_particleState == 2)
	{
		a_particle->vx = int2fix(qran_range(-15, 15));
		a_particle->vy = int2fix(30 + qran_range(0, 5));
	}
	else if (a_particleState == 3) {
		a_particle->vx = int2fix(qran_range(-10, 10));
		a_particle->vy = int2fix(20 + qran_range(0, 5));
	}
		a_particle->life = 2;
}
//Method for updating particle effects, this is called via a loop for the different particle instance in game manager
void UpdateParticle(const Emitter* a_emmiter, Particle* a_particle, s8 a_particleState)
{
	fixed xDisplacement = fixMul(a_particle->vx, getFrameTime());
	fixed yDisplacement = fixMul(a_particle->vy, getFrameTime());
	//Conversion of displacement values to pixel values
	xDisplacement = fixMul(xDisplacement, getPixel2Meters());
	yDisplacement = fixMul(yDisplacement, getPixel2Meters());
	a_particle->x = fixAdd(a_particle->x, xDisplacement);
	a_particle->y = fixAdd(a_particle->y, yDisplacement);
	//Alter speed based on gravity
	a_particle->vy -= fixMul(getGravity(), getFrameTime());
	a_particle->life += 16;

	if ((a_particle->y - a_emmiter->y) > int2fix(50)) {
		EmitParticle(a_emmiter, a_particle, a_particleState);
	}
}