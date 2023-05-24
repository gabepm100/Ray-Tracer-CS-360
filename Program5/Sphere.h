#pragma once
#ifndef SPHERE_HDR
#define SPHERE_HDR
#include "Tuple.h"
#include "Ray.h"
class Sphere{
    private:

    public:
    Tuple center;
    double radius;

    Sphere();
    Sphere(Tuple center,double radius);
    friend bool operator==(const Sphere, const Sphere);
    friend ostream& operator<<(ostream& os, const Sphere& T);
    double rayHitsSphere( const Ray& ray);
};

#endif