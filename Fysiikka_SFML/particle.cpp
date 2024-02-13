#include "particle.h"
#include <iostream>

void Particle::update(double deltaTime) {

	// v = v0 + at
	//vel = vel + acc * deltaTime;
	//vel = vel * 0.999;

	// From physics: s = s0 + vt (+ 0.5at^2)
	pos = pos + vel * deltaTime;

	// update acceleration according to resultant force
	vector3 result_acc = acc;  // basic acceleration of the particle
	result_acc = result_acc + resultantForce * inverseMass;
	//std::cout << "resforce: " << resultantForce.x << "," << resultantForce.y << "," << resultantForce.z << std::endl;
	//std::cout << "resacc: " << result_acc.x << "," << result_acc.y << "," << result_acc.z << std::endl;
	vel = vel + result_acc * deltaTime;
	//vel = vel * 0.999;

	// clear resultant force
	resultantForce.clear();
}

void Particle::addForce(vector3 force){
	resultantForce = resultantForce + force;
}
