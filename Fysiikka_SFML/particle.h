#pragma once
#include "vector3.h"

class Particle
{
public:
	
	Particle() : pos(0.0, 0.0, 0.0), vel(0.0, 0.0, 0.0), acc(0.0, 0.0, 0.0), inverseMass(1.0), resultantForce(0.0, 0.0, 0.0) {};
	Particle(vector3 mypos) : pos(mypos) {};
	Particle(vector3 mypos, vector3 myvel, double mymass) : 
		pos(mypos), vel(myvel) {
		setMass(mymass);  // Mass cannot be very very small...
	};


	vector3 pos = vector3(0.0, 0.0, 0.0);  // Position 
	vector3 vel = vector3(0.0, 0.0, 0.0);  // Velocity
	vector3 acc = vector3(0.0, 0.0, 0.0);  // acceleration

	// Updates the physics model of this particle given delta time
	void update(double deltaTime);

	// Adds a force vector to this particle
	void addForce(vector3 force);

	void setInfiniteMass() {
		inverseMass = 0.0;
	}

	bool hasInfiniteMass() {
		return inverseMass == 0.0;
	}

	// get the mass
	double getMass() { 
		if (inverseMass == 0.0) {
			return 0.0;  // should not happen...maybe return largest possible double??
		}
		return 1.0 / inverseMass; 
	}

	// set the mass
	void setMass(double mass) { 
		if (mass < 0.01) {
			mass = 0.01; // smallest possible mass
		}
		this->inverseMass = 1.0 / mass;
	}

private:

	double inverseMass = 1.0;

	vector3 resultantForce = vector3(0.0, 0.0, 0.0);  // accumulator for all forces

};

