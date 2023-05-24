
#define TUPLE_HDR
#include <iostream>
#include<cmath>
using namespace std;
class Tuple{
    private:
        bool w;
    public:
        double x,y,z;
        Tuple();
        Tuple(double x, double y, double z);
        Tuple(double x, double y, double z, bool w);
        Tuple(const Tuple& source);
        bool isVector() const;
        bool isPoint() const;
        void add(const Tuple& otherTuple);
        void sub(const Tuple& otherTuple);
        void multScalar(double S);
        double magnitude() const;
        void normalize();
        double dot(const Tuple& otherTuple) const;
        void print() const;
        friend ostream& operator<<(ostream& os, const Tuple& T);
        friend Tuple operator+(const Tuple& a, const Tuple& b);
        friend Tuple operator-(const Tuple& a, const Tuple& b);
        friend Tuple operator*(const Tuple& a, double s);
        friend Tuple operator*(double s, const Tuple& a);
};
class Ray{
    private:

    public:
    Tuple direction;
    Tuple origin;    
    Ray(Tuple direction,Tuple origin);
};
class Sphere{
    private:

    public:
    Tuple center;
    double radius;

    Sphere();
    Sphere(Tuple center,double radius);
    friend ostream& operator<<(ostream& os, const Sphere& T);
};
class Plane{
    private:
    public:
    Tuple NormalDirection;
    Tuple PlanPoint;

    Plane();
    friend ostream& operator<<(ostream& os, const Plane& T);
    Plane(Tuple PlanPoint, Tuple NormalDirection);
};
class Object{
    private: 
    public:
    Plane plane;
    Sphere sphere;
    Tuple color;
    Object(Plane plane, Sphere sphere, Tuple color);
    friend ostream& operator<<(ostream& os, const Object& T);
};


