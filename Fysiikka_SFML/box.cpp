#include "box.h"
#include <iostream>

void Box::update(double _deltatime)
{
	p.update(_deltatime);
}

bool Box::detectCollision(Box* other)
{
	bool isColliding = true;

	// TODO:
	// Detect collision with other-box using AABB
	// and update isColliding boolean

	double minXa = this->p.pos.x - this->getWidth() / 2.0;
	double maxXa = this->p.pos.x + this->getWidth() / 2.0;
	double minYa = this->p.pos.y - this->getHeight() / 2.0;
	double maxYa = this->p.pos.y + this->getHeight() / 2.0;

	double minXb = other->p.pos.x - other->getWidth() / 2.0;
	double maxXb = other->p.pos.x + other->getWidth() / 2.0;
	double minYb = other->p.pos.y - other->getHeight() / 2.0;
	double maxYb = other->p.pos.y + other->getHeight() / 2.0;

	// Diff X 1: MinXa - MaxXb (>0 ?)
	//std::cout << "DiffX1: " << minXa - maxXb << std::endl;
	if (maxXb <= minXa) {
		isColliding = false;
	}
	// Diff X 2: MinXb - MaxXa (>0 ?)
	//std::cout << "DiffX2: " << minXb - maxXa << std::endl;
	else if (maxXa <= minXb) {
		isColliding = false;
	}
	// Diff Y 1: MinYa - MaxYb (>0 ?)
	//std::cout << "DiffY1: " << minYa - maxYb << std::endl;
	else if (maxYb <= minYa) {
		isColliding = false;
	}
	// Diff Y 2: MinYb - MaxYa (>0 ?)
	//std::cout << "DiffY2: " << minYb - maxYa << std::endl;
	else if (maxYa <= minYb) {
		isColliding = false;
	}

	// Set the booleans for the boxes
	if (!this->bColliding)
		this->bColliding = isColliding;
	if (!other->bColliding)
		other->bColliding = isColliding;

	return isColliding;
}

void Box::resolveCollision(Box* other)
{
	// What now?!?

	// Compute x- and y-overlaps
	Box* pleft = nullptr;
	Box* pright = nullptr;
	//this->p.pos.x < other->p.pos.x ? this : other;

	if (this->p.pos.x < other->p.pos.x) {
		pleft = this;
		pright = other;
	}
	else {
		pleft = other;
		pright = this;
	}
	double x_overlap = (pleft->p.pos.x + pleft->getWidth() / 2.0) - 
				       (pright->p.pos.x - pright->getWidth() / 2.0);

	Box* plower = nullptr;
	Box* pupper = nullptr;
	if (this->p.pos.y < other->p.pos.y) {
		plower = this;
		pupper = other;
	}
	else {
		plower = other;
		pupper = this;
	}
	double y_overlap = (plower->p.pos.y + plower->getHeight() / 2.0) -
					   (pupper->p.pos.y - pupper->getHeight() / 2.0);


	double totMass = pleft->p.getMass() + pright->p.getMass();
	// Which is smaller???
	if (x_overlap < y_overlap) {
		// Collision in x-axis
		// Remove interpenetration, dependant on masses
		pright->p.pos.x += x_overlap * (pleft->p.getMass() / totMass);
		pleft->p.pos.x -= x_overlap * (pright->p.getMass() / totMass);
		// Resolve velocity in x-axis

		// this.vel after:
		// this.vel * (this.mass - other.mass)/totmass +
		// other.vel * 2*other.mass/totmass
		double pright_vel = pright->p.vel.x;
		double pleft_vel = pleft->p.vel.x;

		pright->p.vel.x = pright_vel * (pright->p.getMass() - pleft->p.getMass()) / totMass +
						  pleft_vel * 2.0 * pleft->p.getMass() / totMass;

		pleft->p.vel.x = pleft_vel * (pleft->p.getMass() - pright->p.getMass()) / totMass +
			pright_vel * 2.0 * pright->p.getMass() / totMass;

	}
	else {
		// Collision in y-axis
		// Remove interpenetration, dependant on masses
		pupper->p.pos.y += y_overlap * (plower->p.getMass() / totMass);
		plower->p.pos.y -= y_overlap * (pupper->p.getMass() / totMass);
		// Resolve velocity in y-axis

		double pupper_vel = pupper->p.vel.y;
		double plower_vel = plower->p.vel.y;

		pupper->p.vel.y = pupper_vel * (pupper->p.getMass() - plower->p.getMass()) / totMass +
			plower_vel * 2.0 * plower->p.getMass() / totMass;

		plower->p.vel.y = plower_vel * (plower->p.getMass() - pupper->p.getMass()) / totMass +
			pupper_vel * 2.0 * pupper->p.getMass() / totMass;

	}





}
