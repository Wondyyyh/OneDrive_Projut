#include "force.h"

void AnchorSpringForce::updateForce(Particle& p, double deltatime) {

	// No force for infinite mass particles
	if (p.hasInfiniteMass())
		return;

	//Hooke's law: F = -k x
	vector3 force = pos - p.pos; // from the particle to the anchor point
	double x = force.magnitude();
	force.normalize();  // magnitude is now 1

	force = force * (k * x);
	p.addForce(force);
}

void AirblowerForce::updateForce(Particle& p, double deltatime) {

	// No force for infinite mass particles
	if (p.hasInfiniteMass())
		return;

	// If the particle is outside the rectangle, just return
	if (p.pos.x < pos.x)
		return;
	if (p.pos.x > pos.x + width)
		return;
	if (p.pos.y < pos.y)
		return;
	if (p.pos.y > pos.y + height)
		return;

	// The particle is inside the rectangle, so add the force
	vector3 force(0.0, F, 0.0); // force vector upwards
	p.addForce(force);
}

void PlanetaryForce::updateForce(Particle& p, double deltatime) {

	// No force for infinite mass particles
	if (p.hasInfiniteMass())
		return;

	// Get the vector from the particle to the planet
	vector3 force = this->pos - p.pos;
	double r = force.magnitude();  // distance
	force.normalize();  // normalize the force vector i.e. magnitude is 1

	// F = G * m1 * m2 / r^2
	//double F = G * mass * p.getMass() / (r * r);
	//force = force * F;
	force = force * (G * mass * p.getMass() / (r * r));
	p.addForce(force);
}


void GravityForce::updateForce(Particle& p, double deltatime) {
	
	// Does the particle have infinite mass?
	if (p.hasInfiniteMass()) {
		return;  // no force
	}

	// F = ma --> G = mg
	vector3 force;
	force.y = - p.getMass() * gravity;
	p.addForce(force);

}


void ForceRegistry::add(Particle* p, Force* f) {
	// create a new registration
	ParticleForceRegistration pfr;
	pfr.particle = p;  // add the particle
	pfr.force = f;     // add the force
	// add this registration to our registry
	registrations.push_back(pfr);
}

void ForceRegistry::updateForces(double deltatime){
	// go through all particle-force pairs
	// and call updateForce() on each
	for (auto it = registrations.begin(); it != registrations.end(); it++) {
		it->force->updateForce(*(it->particle), deltatime);
	}
}

