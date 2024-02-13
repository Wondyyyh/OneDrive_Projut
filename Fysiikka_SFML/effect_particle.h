#pragma once
#include "particle.h"
class EffectParticle : public Particle
{
public:

	// Color
	int R, G, B, A;

	// Lifetime values
	double lifetime;
	double lifetime_left;

	// Start time
	double start_time;
	double age;

	// is alive?
	bool isAlive;

	void update(double deltatime);

};

