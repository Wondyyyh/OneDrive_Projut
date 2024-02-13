#pragma once
#include "particle.h"
#include "gameobject.h"

class Box : public GameObject
{
public:

	Box() : p(), width(10.0), height(10.0) {};
	Box(vector3 _pos, vector3 _vel, double _mass, double _width, double _height) :
	  p(_pos, _vel, _mass), width(_width), height(_height) {};

	void update(double _deltatime);

	bool detectCollision(Box* other);
	

	// particle
	Particle p;

	inline double getWidth() { return width; }
	inline double getHeight() { return height; }

	inline bool isColliding() { return bColliding; }

	void resolveCollision(Box* other);

	bool bColliding = false;


private:
	// width & height
	double width;
	double height;


};

