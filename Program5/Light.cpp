#include "Light.h"

Light::Light(){
    this->origin=Tuple();
    this->coefficient=Rgb();
}
Light::Light(Tuple tw,Rgb Coe){

    this->origin=tw;
    this->coefficient=Coe;
}