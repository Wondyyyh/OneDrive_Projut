#pragma once
#include "particle.h"
#include <vector>

// Base class for all forces
class Force {
public:
	// a pure virtual function --> this class is an interface!
	virtual void updateForce(Particle& p, double deltatime) = 0;
};

// A registry for force-particle-pairs
class ForceRegistry {
public:
	// A "pair" having one specific particle and one specific force
	struct ParticleForceRegistration {
		Particle* particle;
		Force* force;
	};

	typedef std::vector<ParticleForceRegistration> Registry;
	Registry registrations;

	// Adds one particle-force registration to the registry
	void add(Particle* p, Force* f);
	//...
	//more methods here!!!
	// Removes a particle-force registration
	// void remove(Particle* p, Force* f);
	// Updates all forces in this registry
	void updateForces(double deltatime);
};

class AnchorSpringForce : public Force {

public:
	AnchorSpringForce() : pos(0.0, 0.0, 0.0), k(1.0) { };
	AnchorSpringForce(vector3 p, double constant) : pos(p), k(constant) { };

	virtual void updateForce(Particle& p, double deltatime);

private:
	vector3 pos;  // anchor point
	double k; // spring constant
};


class AirblowerForce : public Force {

public:
	AirblowerForce() : pos(0.0, 0.0, 0.0), width(1.0), height(1.0), F(1.0) { };
	AirblowerForce(vector3 p, double w, double h, double f) : pos(p), width(w), height(h), F(f) { };

	virtual void updateForce(Particle& p, double deltatime);

private:
	vector3 pos;
	double width, height;
	double F;  // Amount of force _upwards_ !!! could be done with vector as well...
};

class PlanetaryForce : public Force {

public:
	PlanetaryForce() : pos(0.0, 0.0, 0.0), mass(6000000000000000000000.0) { };
	PlanetaryForce(vector3 p, double m) : pos(p), mass(m) { };

	virtual void updateForce(Particle& p, double deltatime);

private:
	vector3 pos;
	double mass;
	constexpr static double G = 0.000000000006674;
};

class GravityForce : public Force {

public:
	GravityForce() { };
	GravityForce(double g) { gravity = g; };

	virtual void updateForce(Particle& p, double deltatime);

private:
	double gravity = 9.81;  // default Earth gravity
};