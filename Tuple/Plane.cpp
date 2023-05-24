#include "Plane.h"


Plane::Plane(Tuple PP, Tuple ND){
    this->NormalDirection=ND;
    this->PlanPoint=PP;

}

Plane::Plane(){
    this->NormalDirection=Tuple(0,0,0,0);
    this->PlanPoint=Tuple(0,0,0,1);

}
ostream& operator<<(ostream& os, const Plane & T){
    os <<"Plane:("<<T.NormalDirection<<","<<T.PlanPoint<<")"<<endl;
    return os;
}
double Plane::hitsPlane(Ray ra){
    double discriminate =this->NormalDirection.dot(ra.direction);
    if (discriminate==0){
        return -1.0;
    }
    return((this->PlanPoint-ra.origin).dot(this->NormalDirection))/discriminate;
}