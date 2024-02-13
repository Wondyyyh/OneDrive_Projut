#pragma once
#include "particle.h"
class EffectParticle : public particle
{
public:

	//color
	int R, G, B, A;

	//lifetime
	double lifetime;
	double lifetime_left;

	// Start time
	double start_time;
	double age;

	// is alive?
	bool isAlive;

	//Update
	void update(double deltatime);


};

