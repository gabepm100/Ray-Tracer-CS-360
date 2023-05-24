#include "Object.h"

Object::Object(Plane p, Sphere s, Rgb col, Rgb mat){
    this->plane=p;
    this->sphere=s;
    this->color=col;
    this->materialReflectance=mat;
}
Object::Object(){
    this->plane=Plane();
    this->sphere=Sphere();
    this->color=Rgb();
    this->materialReflectance=Rgb();
}



ostream& operator<<(ostream& os, const Object & T){
    os <<"Object:"<<endl;
    os <<T.plane<<T.sphere;
    os<<"Color:("<<T.color<<")"<<endl;
    return os;
}