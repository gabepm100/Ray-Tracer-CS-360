#ifndef RGB_HDR
#define RGB_HDR

/*
Red, Green, and Blue coefficients each expressed as a type double
value between 0.0 and 1.0
*/
#include <iostream>
using namespace std;

class Rgb {
	private:
		
		
		// Clamps r, g, b values so they are all between 0.0 and 1.0, inclusive.
		void clamp();
		
	public:
		double red, green, blue;
		// Default constructor - initializes r, g, b values to all 0.0
		Rgb();
		
    // Initializing constructor - initializes Rgb to have given values.
		// Clamps given values so that they each range between 0.0 to 1.0, inclusive.
    Rgb(double red, double green, double blue);		
		
    // Copy constructor - receives another Rgb as argument.
    // Initialize this Rgb to hold identical r, g, and b values as the given argument.
		Rgb(const Rgb& src);
		
		void add( const Rgb& src );
		
		void multScalar(double s);
		
		void mult( const Rgb& src );
		
		double getR() const;
		double getG() const;
		double getB() const;
		
    // Reference: https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
    friend ostream& operator<<(ostream& os, const Rgb& T);
		
		friend Rgb operator+(const Rgb& a, const Rgb& b);
		
		friend Rgb operator-(const Rgb& a, const Rgb& b);
		
		friend Rgb operator*(const Rgb& a, double s);
		
		friend Rgb operator*(double s, const Rgb& a);
		
		friend Rgb operator*(const Rgb& a, const Rgb& b);
};

#endif
