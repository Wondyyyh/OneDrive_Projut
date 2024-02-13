#include "EffectParticle.h"

void EffectParticle::update(double deltatime) {

	// Check elapsed time vs. start time
	if (!isAlive) {
		// add deltatime to counter
		age += deltatime;
		// if counter >= start time
		if (age >= start_time) {
			isAlive = true;
		}
		return;
	}
	//call particle-class's update
	particle::update(deltatime);

	//update the lifetime left
	if (lifetime_left > 0.0)
		lifetime_left -= deltatime;
	else
		lifetime_left = 0.0;

	//update the alpha-valu according to the lifetime
	A = 255 * (lifetime_left / lifetime);



}