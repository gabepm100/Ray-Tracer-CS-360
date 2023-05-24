
#include "Tuple.h"
// Default constructor - initializes Tuple to be a vector having coordinate
// values (x 0, y 0, z 0, w 0)
Tuple::Tuple(){
    this->w=false;
    this->x=0;
    this->y=0;
    this->z=0;
}

// Vector constructor - initializes Tuple to be a vector having coordinate
// values x, y, and z as given. The w value will be automatically set to 0.
Tuple::Tuple(double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
    this->w=false;
}

// Point constructor - initializes Tuple to be a point having coordinate
// values x, y, and z as given. The fourth argument is expected to be any
// positive value, but will be always stored as w = 1.0 
// The C++ compiler will call this version when it sees four type double arguments.
Tuple::Tuple(double x, double y, double z, bool w){
    this->x=x;
    this->y=y;
    this->z=z;
    this->w=w;
}

// Copy constructor - receives another Tuple as argument.
// Initialize this Tuple to hold identical x, y, z, and w values as the given argument Tuple.
Tuple::Tuple(const Tuple& source){
    this->x=source.x;
    this->y=source.y;
    this->z=source.z;
    this->w=source.w;
}

// Return true if this Tuple is a vector (has w value of zero)
// Hint: Use the absolute value function check for zero.
// If the absolute value of w is less than 0.001 (or similar small epsilon value), then we 
// assume that the w value is "equal" to zero.
// When using float or double the == can often report false when the two
// values are close enough to being equal.
// https://cplusplus.com/reference/cmath/abs/
bool Tuple::isVector() const{
    if (this->w){
        return false;
    }
    else{
        return true;
    }
}

// Return true if this Tuple is a point (has w value > 0)
bool Tuple::isPoint() const{
    if (this->w){
    return true;
}
else{
    return false;
}
}

// Increments this x, y, z, and w by respective values from otherTuple.
// If this tuple and otherTuple are both points whose w values are 1, then
// the addition will leave this->w at 2.0. If we find this->w > 1, then set this->w = 1.
void Tuple::add(const Tuple& otherTuple){
    this->x=this->x + otherTuple.x;
    this->y=this->y + otherTuple.y;
    this->z=this->z + otherTuple.z;
    if(this->w==false and otherTuple.w==false){
        this->w=false;
    }
    else{
        this->w=true;
    }
}

// Decrements this x, y, z, and w by respective values from otherTuple.
// If this tuple is a vector and otherTuple a point whose w values are 1, then
// the subtraction will leave this->w at -1. If we find this->w < -0.5, then set this->w = 1
// so that the result is a point.
void Tuple::sub(const Tuple& otherTuple){
    this->x=this->x - otherTuple.x;
    this->y=this->y - otherTuple.y;
    this->z=this->z - otherTuple.z;
    if(this->w==true and otherTuple.w==true){
        this->w=true;
        
    }
    else{
        this->w=false;
    }
}

// Multiplies x, y, and z values of this Tuple by the given scalar value S.
// Tuple's w value is not changed.
void Tuple::multScalar(double S){

    this->x = this->x*S;
    this->y = this->y*S;
    this->z = this->z*S;
}

// Return the length or magnitude of this point or vector.
// If Tuple is a point, then length is the distance of this point from the origin point (0,0,0).
// If Tuple is a vector, then length is the magnitude of the vector.
// The Tuple's w value does not contribute to its length.
double Tuple::magnitude() const{
    if (this->w==0){
        return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
    }
    else{
        return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));;
    }
}

// Change this vector to unit-length. 
// A unit-length vector is one whose length or magnitude is 1.0.
// pre-condition: This Tuple must be a vector. If is a point, then do nothing.
// First, find the magnitude of this vector.
// Second, if the magnitude is > 0, then divide this Tuple's
// x, y, and z values by the magnitude.
// Do not divide when the magnitude is 0 since this will cause a divide by zero crash.
// Normalize does not change the Tuple's w value.
void Tuple::normalize(){
    
    if(this->w ==false){
        double m = this->magnitude();
        if (m>0){
            this->x=this->x/m;
            this->y=this->y/m;
            this->z=this->z/m;
        }
    }
}

// Return the dot product of two vectors.
// pre-condition: this Tuple and otherTuple must both be vectors.
// returns dot product of this Tuple and otherTuple using only their x, y, and z values.
// Otherwise, return 0 if this Tuple and otherTuple are not both vectors.
double Tuple::dot(const Tuple& otherTuple) const{
    if (this->w==false and otherTuple.w==false){
    return (this->x *otherTuple.x)+(this->y *otherTuple.y)+(this->z *otherTuple.z);
    }
    else{
        return 0;
    }
}

// Print formatted display of Tuple to std::cout.
// Example print out: (1, 2, 3, 0) for a vector.
// Print the values in order of x, y, z, and w.
void Tuple::print() const{
    cout<<"("<<x<<","<<y<<","<<z<<","<<this->w<<")"<<endl;
}

//operator overloads the << function to prin t out the tuple
ostream& operator<<(ostream& os, const Tuple& T){
    os <<"("<<T.x<<","<<T.y<<","<<T.z<<","<<T.w<< ")"<<"";
    return os;
}

//--- Allows us to write A + B to compute the Tuple that results from calling A.add(B)
//--- Code-reuse tip - Call on your add method
Tuple operator+(const Tuple& a, const Tuple& b){
    Tuple result(a);
    result.add(b);
    return result;
}

//--- Allows us to write A - B to compute the Tuple that results from calling A.sub(B)
//--- Code-reuse tip - Call on your sub method    
Tuple operator-(const Tuple& a, const Tuple& b){
    Tuple result(a);
    result.sub(b);
    return result;
}

bool operator==(const Tuple& a, const Tuple& b){
if ((a.w==b.w)&&(a.x==b.x)&&(a.z==b.z)&&(a.y==b.y)){
    return true;
}
return false;
}
//--- Allows us to write A * 1.5 to compute the Tuple that results from calling A.multScalar(1.5)
//--- Code-reuse tip - Call on your multScalar method
Tuple operator*(const Tuple& a, double s){
    Tuple result(a);
    result.multScalar(s);
    return result;
}

//--- Allows us to write 1.5 * A to compute the Tuple that results from calling A.multScalar(1.5)
//--- Code-reuse tip - Call on your multScalar method    
Tuple operator*(double s, const Tuple& a){
    Tuple result(a);
    result.multScalar(s);
    return result;

}

