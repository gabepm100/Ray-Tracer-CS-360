#include "Tuple.h"
#include <stdio.h>
#include <math.h>
#include "easyppm.h"
#include <list>
#include <map>
#include <iterator>

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
    //cout<<t<<endl;
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



int main(){
  list<Object>objlist;
  int myPixelWidth = 200;
	int myPixelHeight = 200;
  int w=4;
  int h=4;
  int front_clip = 4;
  int imagePixelSize = 200;
  Object Sphere1(Plane(),Sphere(Tuple(0,0,10),2.5),Tuple(255,0,0,0));
  Object Plane1(Plane(Tuple(0,0,10,0),Tuple(0,-1,-1,0)),Sphere(),Tuple(0,255,0));
  PPM myImage = easyppm_create(myPixelWidth, myPixelHeight, IMAGETYPE_PPM);

  // Clear all image pixels to RGB color white.
  easyppm_clear(&myImage, easyppm_rgb(0, 0, 0));
  Tuple X(1,0,0,0);
  Tuple Y(0,1,0,0);
  Tuple Z(0,0,1,0);
  Tuple Q(0,0,0,0);
  Tuple B(-w/2,-h/2,front_clip,1);
	// Nested outer loop over rows of image...
  for(double f= 0.0; f < myPixelWidth; f++){
		// Nested inner loop over columns of image...
		for(double u = 0.0; u < myPixelHeight; u++){
      float s=(f/(myPixelWidth/w));
      float d=(u/(myPixelHeight/h));
      Tuple P =B+((X*s)+(Y*d));
      Tuple V((P-Q));
      V.normalize();
      Ray one(V,Tuple(0,0,0,0));
      double t =-1.0;
      int count= 0;
      
      if(rayHitsPlane(one.origin,one.direction,Plane1.plane.PlanPoint,Plane1.plane.NormalDirection,t)){
        easyppm_set(&myImage, f, u, easyppm_rgb(Plane1.color.x, Plane1.color.y, Plane1.color.z));
      }
      
      if(rayHitsSphere(one.origin,one.direction,Sphere1.sphere.center,Sphere1.sphere.radius, t)){
        easyppm_set(&myImage, f, u, easyppm_rgb(Sphere1.color.x, Sphere1.color.y,Sphere1.color.z));
      }
      
    }   
  }
	// Write image to PPM file.
	// Use an online PPM image viewer app to see the image...
	// https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html
	// Or, install an image editor such as the free GNU Gimp program.ould be vector + vector = vector.  If any one of the two arguments is a point, then the add should yield a point. For subtract, point - point = vector, which you have.
  easyppm_write(&myImage, "project1Img.ppm");

	// Deallocate (release) memory used to store the image data.
  easyppm_destroy(&myImage);

	// Return error code of 0 to operating system to signal successful exit.
  return 0;
  
}



