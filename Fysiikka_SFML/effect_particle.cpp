#include "effect_particle.h"

void EffectParticle::update(double deltatime) {

	// Check elapsed time vs. start time
	if (!isAlive) {
		// add deltatime to counter
		age += deltatime;
		// if counter >= start time and there's still lifetime left
		if (age >= start_time && lifetime_left > 0.0) {
			isAlive = true;
		}
		return;
	}

	// call particle-class's update
	Particle::update(deltatime);

	// update the lifetime left
	if (lifetime_left > 0.0)
		lifetime_left -= deltatime;
	else {
		lifetime_left = 0.0;
		isAlive = false;
	}

	// update the alpha-value according to the lifetime
	A = 255 * (lifetime_left / lifetime);


}