#include "Ray.h"
Ray::Ray(Tuple th,Tuple tw){

    this->direction=th;
    this->origin=tw;
}

ostream& operator<<(ostream& os, const Ray& T){
    os <<"Ray:("<<T.direction<<","<<T.origin<<")"<<endl;
    return os;
}