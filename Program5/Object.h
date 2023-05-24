#ifndef OBJECT_HDR
#define OBJECT_HDR
#include "Tuple.h"
#include "Sphere.h"
#include "Plane.h"
#include "Rgb.h"
class Object{
    private: 
    public:
    Plane plane;
    Sphere sphere;
    Rgb color;
    Rgb materialReflectance;
    Object();
    Object(Plane plane, Sphere sphere, Rgb color, Rgb materialReflectance);
    bool isSphere();
    bool isPlane();
    friend ostream& operator<<(ostream& os, const Object& T);
};

#endif