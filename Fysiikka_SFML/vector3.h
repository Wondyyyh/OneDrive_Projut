#pragma once
class vector3
{
public:

	vector3() : x(0.0), y(0.0), z(0.0) { };
	vector3(double xval, double yval, double zval) : x(xval), y(yval), z(zval) {};

	double x, y, z;
	// computes the magnitude of this vector
	double magnitude();

	// squared magnitude (for optimization)
	double sqMagnitude();
	 
	// normalizes this vector
	void normalize();

	// dot prod
	double dotProd(vector3 other);


	// plus operation
	vector3 operator+(vector3 rhs);

	// minus operation
	vector3 operator-(vector3 rhs);

	// multiply operation
	vector3 operator*(double scalar);

	// insert more functions here!
	// ...
	// cross-product
	vector3 crossProd(vector3 other);

	// angle to other vector
	double angleTo(vector3 other);

	void clear();

};