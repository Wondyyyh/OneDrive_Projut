#include "ball.h"

void Ball::update(double _deltatime)
{
	p.update(_deltatime);
}

bool Ball::detectCollision(GameObject* other)
{
	Ball* IssaBall = dynamic_cast<Ball*>(other);
	if (IssaBall)
	{
		// Vector between this ball and the other ball
		vector3 d = IssaBall->p.pos - this->p.pos;

		// If the magnitude of the vector is smaller
		// than sum of radii --> can be optimized using d.sqMagnitude() !!!
		if (d.magnitude() < this->getRadius() + IssaBall->getRadius()) {
			// collision 
			this->bColliding = true;
			IssaBall->bColliding = true;
			return true;
		}

		return false;
	}
	// Box happenings here
	Box* IssaBox = dynamic_cast<Box*>(other);
	if (IssaBox)
	{
		// Vector between this ball and the other ball
		vector3 d = IssaBox->p.pos - this->p.pos;

		// If the magnitude of the vector is smaller
		// than sum of radii --> can be optimized using d.sqMagnitude() !!!
		if (d.magnitude() < this->getRadius() + IssaBox->getHeight()/2) {
			// collision 
			this->bColliding = true;
			IssaBox->bColliding = true;
			return true;
		}

		return false;
	}
}

void Ball::resolveCollision(GameObject* other)
{
	resolveInterpenetration(other);
	resolveVelocities(other);
}

void Ball::resolveInterpenetration(GameObject* other)
{
	Ball* IssaBall = dynamic_cast<Ball*>(other);
	if (IssaBall)
	{
		// vector between balls - from this ball to the other
		vector3 d = IssaBall->p.pos - this->p.pos;

		// calculate overlap
		double overlap = (this->getRadius() + IssaBall->getRadius()) - d.magnitude();

		// get the normal vector from d
		d.normalize();

		// overlap vector (from this ball towards the IssaBall)
		d = d * overlap;

		// remove overlap:
		// TODO: 
		// - move this ball in proportion to the IssaBall ball's mass
		double totmass = this->p.getMass() + IssaBall->p.getMass();
		this->p.pos = this->p.pos - d * (IssaBall->p.getMass() / totmass);

		// PARTLY DONE:
		// - move the IssaBall in proportion to this ball's mass
		IssaBall->p.pos = IssaBall->p.pos + d * (this->p.getMass() / totmass);
	}

	// Box happenings here
	Box* IssaBox = dynamic_cast<Box*>(other);
	if (IssaBox)
	{
		// vector between balls - from this ball to the other
		vector3 d = IssaBox->p.pos - this->p.pos;

		// calculate overlap
		double overlap = (this->getRadius() + IssaBox->getHeight()/2) - d.magnitude();

		// get the normal vector from d
		d.normalize();

		// overlap vector (from this ball towards the IssaBox)
		d = d * overlap;

		// remove overlap:
		// TODO: 
		// - move this ball in proportion to the IssaBox ball's mass
		double totmass = this->p.getMass() + IssaBox->p.getMass();
		this->p.pos = this->p.pos - d * (IssaBox->p.getMass() / totmass);

		// PARTLY DONE:
		// - move the IssaBox in proportion to this ball's mass
		IssaBox->p.pos = IssaBox->p.pos + d * (this->p.getMass() / totmass);
	}
}

void Ball::resolveVelocities(GameObject* other)
{
	Ball* IssaBall = dynamic_cast<Ball*>(other);
	if (IssaBall) 
	{

		//TODO:
		// Actually solve these...

		vector3 x1_x2 = this->p.pos - IssaBall->p.pos;
		vector3 v1_v2 = this->p.vel - IssaBall->p.vel;
		vector3 x2_x1 = IssaBall->p.pos - this->p.pos;
		vector3 v2_v1 = IssaBall->p.vel - this->p.vel;
		double tot_mass = this->p.getMass() + IssaBall->p.getMass();

		// velocity of this ball
		this->p.vel = this->p.vel - x1_x2 * (2.0 * IssaBall->p.getMass() / (tot_mass)) * (v1_v2.dotProd(x1_x2) / x1_x2.sqMagnitude());

		// velocity of other ball
		IssaBall->p.vel = IssaBall->p.vel - x2_x1 * (2.0 * this->p.getMass() / (tot_mass)) * (v2_v1.dotProd(x2_x1) / x2_x1.sqMagnitude());

		return;
	}

	// Box happenings here
	Box* IssaBox = dynamic_cast<Box*>(other);
	if(IssaBox)
	{
		vector3 x1_x2 = this->p.pos - IssaBox->p.pos;
		vector3 v1_v2 = this->p.vel - IssaBox->p.vel;
		vector3 x2_x1 = IssaBox->p.pos - this->p.pos;
		vector3 v2_v1 = IssaBox->p.vel - this->p.vel;
		double tot_mass = this->p.getMass() + IssaBox->p.getMass();

		// velocity of this ball
		this->p.vel = this->p.vel - x1_x2 * (2.0 * IssaBox->p.getMass() / (tot_mass)) * (v1_v2.dotProd(x1_x2) / x1_x2.sqMagnitude());

		// velocity of other ball
		IssaBox->p.vel = IssaBox->p.vel - x2_x1 * (2.0 * this->p.getMass() / (tot_mass)) * (v2_v1.dotProd(x2_x1) / x2_x1.sqMagnitude());

		return;
	}

}
