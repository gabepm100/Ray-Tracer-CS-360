#pragma once
#ifndef RAY_HDR
#define RAY_HDR

#include "Tuple.h"
class Ray{
    private:

    public:
    Tuple direction;
    Tuple origin;    
    Ray(Tuple direction,Tuple origin);
    friend ostream& operator<<(ostream& os, const Ray& T);
};
#endif