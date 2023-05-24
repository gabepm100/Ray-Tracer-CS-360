#include "Scene.h"



int main(){
  Scene Scene1;
  
  
  Object Sphere1(Plane(),Sphere(Tuple(0,0,9),2.5),Rgb(1,0,0),Rgb(0.3,0.3,0.3));
  Object Sphere2(Plane(),Sphere(Tuple(0,2,9),2.5),Rgb(1,0.5,0),Rgb(0.4,0.4,0.4));
  Object Plane1(Plane(Tuple(0,0,10,1),Tuple(0,-1,-1,0)),Sphere(),Rgb(0,0.5,0),Rgb(0.5,0.5,0.5));
	Object Plane2(Plane(Tuple(0,0,10,1),Tuple(0,1,-1,0)),Sphere(),Rgb(0,0,1),Rgb(0.1,0.1,0.1));
  Object Plane3(Plane(Tuple(0,0,10,1),Tuple(-1,-1,-1,0)),Sphere(),Rgb(0,0.5,1),Rgb(0.8,0.8,0.8));
  Light Light1(Tuple(1,-6,3),Rgb(0.8,0.8,0.8));
  Light Light2(Tuple(1,6,3),Rgb(0.7,0.7,0.7));
  Scene1.AddLight(Light1);
  Scene1.AddLight(Light2);
  Scene1.AddObject(Plane1);
  Scene1.AddObject(Plane2);
  Scene1.AddObject(Sphere1);
  Scene1.AddObject(Sphere2);
  Scene1.AddObject(Plane3);

  Scene1.Render();

	// Return error code of 0 to operating system to signal successful exit.
  return 0;
  
}





