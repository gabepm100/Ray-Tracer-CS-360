#include "Sphere.h"


Sphere::Sphere(Tuple c,double r){
    this->center=c;
    this->radius=r;


}

Sphere::Sphere(){
    this->center=Tuple(0,0,0,1);
    this->radius=0.0;

}

ostream& operator<<(ostream& os, const Sphere & T){
    os <<"Sphere:("<<T.center<<","<<T.radius<<")"<<endl;
    return os;
}
double Sphere::rayHitsSphere( const Ray& ray) {
    double a=(ray.direction.dot(ray.direction));
    Tuple o=ray.origin-this->center;
    double b=2*(o.dot(ray.direction));

    double c=(o.dot(o)-(this->radius*this->radius));
    double discriminate=((b*b)-(4*a*c));
    
    if (discriminate>0){
        double int1=(-b+sqrt(discriminate))/(2*a);
        double int2=(-b-sqrt(discriminate))/(2*a);
        double MaybeT=min(int1,int2);
        return MaybeT;
    }
    else if (discriminate ==0){
        double MaybeT=-b/(2*a);

        return MaybeT;
        
    }
    else{
        return -1.0;
    }
}
