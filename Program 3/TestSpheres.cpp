#include "Tuple.h"
bool rayHitsSphere( const Tuple& rayOriginPoint, const Tuple& rayDirectionVector, const Tuple& sphereCenterPoint, double sphereRadius, double& t){
  double a=(rayDirectionVector.dot(rayDirectionVector));
  Tuple o=rayOriginPoint-sphereCenterPoint;
  double b=2*(o.dot(rayDirectionVector));

  double c=(o.dot(o)-(sphereRadius*sphereRadius));
  double discriminate=((b*b)-(4*a*c));

  if (discriminate>0){
    double int1=(-b+sqrt(discriminate))/(2*a);
    double int2=(-b-sqrt(discriminate))/(2*a);
    double MaybeT=min(int1,int2);
    t=MaybeT;
    return true;
  }
  else if (discriminate ==0){
    double MaybeT=-b/(2*a);
    t=MaybeT;
    return true;

  }
  else{
    t=-1; 
    return false;
  }
}
