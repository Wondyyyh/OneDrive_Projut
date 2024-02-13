#pragma once
#include "particle.h"
#include "gameobject.h"
#include "box.h"

class Ball : public GameObject
{
public:

	Ball(vector3 _pos, vector3 _vel, double _mass, double _radius) :
		p(_pos, _vel, _mass), radius(_radius) {};

	// particle
	Particle p;

	inline double getRadius() { return this->radius; }

	void update(double _deltatime);

	bool detectCollision(GameObject* other);

	// Resolve a ball-ball collision:
	// - resolve interpenetration
	// - resolve velocities
	void resolveCollision(GameObject* other);


	bool bColliding = false;

private:

	void resolveInterpenetration(GameObject* other);
	void resolveVelocities(GameObject* other);

	double radius;

};

