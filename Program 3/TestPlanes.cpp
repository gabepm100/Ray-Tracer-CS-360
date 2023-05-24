#include "Tuple.h"

bool rayHitsPlane( const Tuple& rayOriginPoint, const Tuple& rayDirectionVector, const Tuple& planePoint, const Tuple& planeNormalVector, double& t){
  //t=((P - Ro)*N)/(D*N)
  //cout<<rayDirectionVector<<endl;
  double tempt=((planePoint-rayOriginPoint).dot(planeNormalVector))/(planeNormalVector.dot(rayDirectionVector));
  if (tempt>=0)
  {
    t=tempt;
    return true;
  }
  else
  {
    return false;
  }
}