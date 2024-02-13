#include "vector3.h"
#include <cmath>

double vector3::magnitude() {
	// sqrt( x^2 + y^2 + z^2 ) 
	return sqrt(x*x + y*y + z*z);
}

double vector3::sqMagnitude() {
	// sqrt( x^2 + y^2 + z^2 ) 
	return x * x + y * y + z * z;
}

void vector3::normalize() {
	double magn = this->magnitude();
	if (magn < 0.00001) // sanity check, could be done more wisely...
		return;
	x /= magn;
	y /= magn;
	z /= magn;
}

vector3 vector3::operator+(vector3 rhs) {
	vector3 result;
	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;
	result.z = this->z + rhs.z;
	return result;
}

vector3 vector3::operator-(vector3 rhs) {
	vector3 result;
	result.x = this->x - rhs.x;
	result.y = this->y - rhs.y;
	result.z = this->z - rhs.z;
	return result;
}

vector3 vector3::operator*(double scalar) {
	vector3 result;
	result.x = this->x * scalar;
	result.y = this->y * scalar;
	result.z = this->z * scalar;
	return result;
}


double vector3::dotProd(vector3 other) {
	return this->x * other.x + this->y * other.y + this->z * other.z;
}


vector3 vector3::crossProd(vector3 other) {
	vector3 result;
	result.x = this->y * other.z - this->z * other.y;
	result.y = this->z * other.x - this->x * other.z;
	result.z = this->x * other.y - this->y * other.x;
	return result;
}

double vector3::angleTo(vector3 other) {
	return atan2(this->crossProd(other).magnitude(), dotProd(other));
}

void vector3::clear(){
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}
