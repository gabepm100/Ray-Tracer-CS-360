#include "Rgb.h"

// Default constructor - initializes r, g, b values to all 0.0
Rgb::Rgb() {
	this->red = this->green = this->blue = 0.0;
}
		
// Initializing constructor - initializes Rgb to have given values.
// Clamps given values so that they each range between 0.0 to 1.0, inclusive.
Rgb::Rgb(double r, double g, double b) {
	// Assign give argument values...
	this->red = r;
	this->green = g;
	this->blue = b;
	// Clamp updated r, g, b data member variables to valid range.
	this->clamp();
}
		
// Copy constructor - receives another Rgb as argument.
// Initialize this Rgb to hold identical r, g, and b values as the given argument.
Rgb::Rgb(const Rgb& src) {
	this->red = src.red;
	this->green = src.green;
	this->blue = src.blue;
}

// Clamps r, g, b values so they are all between 0.0 and 1.0, inclusive.
void Rgb::clamp() {
	if(this->red < 0.0)
		this->red = 0.0;
	if(this->red > 1.0)
		this->red = 1.0;
		
	if(this->green < 0.0)
		this->green = 0.0;
	if(this->green > 1.0)
		this->green = 1.0;
		
	if(this->blue < 0.0)
		this->blue = 0.0;
	if(this->blue > 1.0)
		this->blue = 1.0;
}
		
void Rgb::add( const Rgb& src ) {
	this->red= this->red + src.red;
	this->green = this->green + src.green;
	this->blue = this->blue + src.blue;
	this->clamp();
}
		
void Rgb::multScalar(double s) {
	this->red = this->red * s;
	this->green = this->green * s;
	this->blue = this->blue * s;
	this->clamp();
}

void Rgb::mult(const Rgb& src) {
	this->red = this->red * src.red;
	this->green = this->green * src.green;
	this->blue = this->blue * src.blue;
	this->clamp();
}

double Rgb::getR() const {
	return this->red;
}

double Rgb::getG() const {
	return this->green;
}

double Rgb::getB() const {
	return this->blue;
}
		
// Reference: https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
ostream& operator<<(ostream& os, const Rgb& T) {
	os << "(" << T.red << ", " << T.green << ", " << T.blue << ")";
	return os;
}
		
Rgb operator+(const Rgb& a, const Rgb& b) {
	Rgb result(a);
	result.add(b);
	return result;
}
		
Rgb operator*(const Rgb& a, double s) {
	Rgb result(a);
	result.multScalar(s);
	return result;
}
		
Rgb operator*(double s, const Rgb& a) {
	Rgb result(a);
	result.multScalar(s);
	return result;
}

Rgb operator*(const Rgb& a, const Rgb& b) {
	Rgb result(a);
	result.mult(b);
	return result;
}