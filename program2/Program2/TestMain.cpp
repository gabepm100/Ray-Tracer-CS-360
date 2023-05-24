#include "Tuple.h"
#include <stdio.h>
#include <math.h>
#include "easyppm.h"
int main(){
  int myPixelWidth = 200;
	int myPixelHeight = 200;
  int w=4;
  int h=4;
  int front_clip = 4;
  int imagePixelSize = 200;
	PPM myImage = easyppm_create(myPixelWidth, myPixelHeight, IMAGETYPE_PPM);

  // Clear all image pixels to RGB color white.
  easyppm_clear(&myImage, easyppm_rgb(255, 255, 255));
  Tuple X(1,0,0,0);
  Tuple Y(0,1,0,0);
  Tuple Z(0,0,1,0);
  Tuple B(-w/2,-h/2,front_clip,1);
  Ray one(Tuple(0,0,0,0),Tuple(0,0,0,1));
  Tuple Q(0,0,0,0);
	// Nested outer loop over rows of image...
  for(double f= 0.0; f < myPixelWidth; f++){
		// Nested inner loop over columns of image...
		for(double u = 0.0; u < myPixelHeight; u++){
      
        
        //Tuple P(-(myPixelWidth/2),-(myPixelHeight/2),front_clip,0);
        float s=(f/(myPixelWidth/w));
        float t=(u/(myPixelHeight/h));
        Tuple P =B+((X*s)+(Y*t));
        
        one.direction=P-Q;
        one.direction.normalize();
        double ang=acos(one.direction.dot(Z));
        ang=(ang*(180/3.141592))*7.28;
        cout<<ang<<endl;
  
        easyppm_set(&myImage, f, u, easyppm_rgb(ang, ang, ang));
      
  


    }
  }     
			//easyppm_set(&myImage, x, y, easyppm_rgb(0, 0, 255));

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
