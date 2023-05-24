#include "Scene.h"

Scene::Scene(){
    list<Object>bjlist;
    list<Light>Lightlist;
    this->Objlist=bjlist;
    this->lightlist=Lightlist;
}

Scene::Scene(list<Object>objlist,list<Light>lightlist){
    this->Objlist=objlist;
    this->lightlist=lightlist;
}
void showlist(list<Object> g)
{
    list<Object>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
/* Goes through the objects and finds the closest object*/
Object Scene::closestIntersection(Ray one,double &t ,Rgb &closestcolor){
    double closestInter=10000000.0;
    Object ClosestObject;
    bool isinter=false;
    for (std::list<Object>::iterator it = Objlist.begin(); it != Objlist.end(); ++it){
        double PlaneHits=it->plane.hitsPlane(one );
        
        double SphereHits=it->sphere.rayHitsSphere(one);
        if ((PlaneHits<closestInter)&&(PlaneHits>0)){
            isinter=true;
            closestInter=PlaneHits;
            ClosestObject.plane=it->plane;
            ClosestObject.sphere=it->sphere;
            ClosestObject.materialReflectance=it->materialReflectance;
            ClosestObject.color=it->color;
            closestcolor.red=it->color.red;
            closestcolor.green=it->color.green; 
            closestcolor.blue=it->color.blue;

        }
        else if((SphereHits<=closestInter)&& (SphereHits>0)){
            isinter=true;
            ClosestObject.plane=it->plane;
            ClosestObject.sphere=it->sphere;
            ClosestObject.materialReflectance=it->materialReflectance;
            ClosestObject.color=it->color;
            closestInter=SphereHits;
            closestcolor.red=it->color.red;
            closestcolor.green=it->color.green;
            closestcolor.blue=it->color.blue;
        }
        else if(isinter=false){
            ClosestObject.plane=Plane();
            ClosestObject.sphere=Sphere();
            ClosestObject.materialReflectance=Rgb();
            ClosestObject.color=Rgb();
            closestcolor.red=0;
            closestcolor.green=0;
            closestcolor.blue=0;
       }
    }
    t=closestInter;
    return ClosestObject;
}
/*Adds an object to the scene*/
void Scene::AddObject(Object f){
    this->Objlist.push_back(f);
}
/*Adds a light to the Scene*/
void Scene::AddLight(Light f){
    this->lightlist.push_back(f);
}
/*Calcuates the lighting and changes the color value*/
int Scene::calculateLighting(Ray one,Rgb &closestcolor,Object ClosestObject,Tuple eyepoint,double specularExponant, Tuple pointOn){
    Rgb TotalAmb(0,0,0);
    Rgb TotalDif(0,0,0);
    Rgb TotalSpec(0,0,0);

    for (std::list<Light>::iterator it = lightlist.begin(); it != lightlist.end(); ++it){
        TotalAmb= TotalAmb +lightAmbient(ClosestObject.materialReflectance,it->coefficient);
        if(ClosestObject.isPlane()){
            TotalDif=TotalDif+lightDiffuse(ClosestObject.materialReflectance,pointOn,ClosestObject.plane.NormalDirection, it->coefficient,it->origin);
            TotalSpec=TotalSpec+lightSpecular(ClosestObject.materialReflectance,pointOn,ClosestObject.plane.NormalDirection,it->coefficient,it->origin,eyepoint,specularExponant);
        }
        else{
            Tuple NormalOfPoint;
            NormalOfPoint.x=(pointOn.x-ClosestObject.sphere.center.x)/ClosestObject.sphere.radius;
            NormalOfPoint.y=(pointOn.y-ClosestObject.sphere.center.y)/ClosestObject.sphere.radius;
            NormalOfPoint.z=(pointOn.z-ClosestObject.sphere.center.z)/ClosestObject.sphere.radius;
            TotalDif=TotalDif+lightDiffuse(ClosestObject.materialReflectance,pointOn,NormalOfPoint, it->coefficient,it->origin);
            TotalSpec=TotalSpec+lightSpecular(ClosestObject.materialReflectance,pointOn,NormalOfPoint,it->coefficient,it->origin,eyepoint,specularExponant);
        }
    }
    closestcolor=closestcolor*(TotalAmb+TotalDif+TotalSpec);
    return 1;
}
//takes a ray and finds and point on an object
Tuple FindPoint(Ray one,double distance){
    return (one.origin+(distance*one.direction));
}

/*
runs a loop and renders an image based on the scene
*/
int Scene::Render()
{
    int myPixelWidth = 600;
    int myPixelHeight = 600;
    int w=4;
    int h=4;
    int front_clip = 4;
    int imagePixelSize = 200;
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
        Ray one(V,Tuple(0,0 ,0,0));
        double t =-1.0;
        Rgb ClosestColor;
        
        Object ClosestObject=closestIntersection( one,t,ClosestColor);
        Tuple pointon =FindPoint(one,t);
        calculateLighting(one,ClosestColor, ClosestObject,Tuple(0,0,0),2,pointon);
        easyppm_set(&myImage, f, u, easyppm_rgb(ClosestColor.getR()*255, ClosestColor.getG()*255, ClosestColor.getB()*255));
      }   
  }
    // Write image to PPM file.
    // Use an online PPM image viewer app to see the image...
    // https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html
    // Or, install an image editor such as the free GNU Gimp program.ould be vector + vector = vector.  If any one of the two arguments is a point, then the add should yield a point. For subtract, point - point = vector, which you have.
    easyppm_write(&myImage, "project5Img.ppm");

    // Deallocate (release) memory used to store the image data.
    easyppm_destroy(&myImage);
    return 1;
}