#include "Scene.h"



int main(){
  Scene Scene1;
  
  
  Object Sphere1(Plane(),Sphere(Tuple(0,-2,9),2.5),Rgb(1,0,0),Rgb(0.5,0.5,0.5));
  Object Sphere2(Plane(),Sphere(Tuple(0,2,9),2.5),Rgb(1,0.5,0),Rgb(0.5,0.5,0.5));
  Object Plane1(Plane(Tuple(0,0,10,1),Tuple(0,-1,-1,0)),Sphere(),Rgb(0,1,0),Rgb(0.5,0.5,0.5));
	Object Plane2(Plane(Tuple(0,0,10,1),Tuple(0,1,-1,0)),Sphere(),Rgb(0,0,1),Rgb(0.5,0.5,0.5));
  Object Plane3(Plane(Tuple(0,0,10,1),Tuple(-1,-1,-1,0)),Sphere(),Rgb(0,0.5,1),Rgb(0.5,0.5,0.5));
  Light Light1(Tuple(2,2,2),Rgb(1,1,1));
  Scene1.AddLight(Light1);
  Scene1.AddObject(Plane1);
  Scene1.AddObject(Plane2);
  Scene1.AddObject(Sphere1);
  Scene1.AddObject(Sphere2);
  Scene1.AddObject(Plane3);

  Scene1.Render();

	// Return error code of 0 to operating system to signal successful exit.
  return 0;
  
}





