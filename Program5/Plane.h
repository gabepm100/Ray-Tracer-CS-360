#ifndef PLANE_HDR
#define PLANE_HDR
#include "Ray.h"
#include "Tuple.h"

class Plane{
    private:
    public:
    Tuple NormalDirection;
    Tuple PlanPoint;

    Plane();
    friend ostream& operator<<(ostream& os, const Plane& T);
    friend bool operator==(const Plane, const Plane);
    Plane(Tuple PlanPoint, Tuple NormalDirection);
    double hitsPlane(Ray ra);
};
#endif