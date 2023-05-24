#pragma once
#ifndef SCENE_HDR
#define SCENE_HDR
#include "Ray.h"
#include "Scene.h"
#include <list>
#include "Rgb.h"
#include <iterator>
#include "Tuple.h"
#include "easyppm.h"
#include "Object.h"
#include "Light.h"
#include "Lighting.h"


class Scene{
    private:

    public:
    list<Object>Objlist;
    list<Light>lightlist;
    Scene();
    Scene(list<Object>objlist,list<Light>lightlist);
    Object closestIntersection(Ray one,double& t ,Rgb& color);
    void AddObject(Object);
    void AddLight(Light);
    int calculateLighting(Ray one,Rgb &closestcolor,Object closestObject);
    int Render();
};
#endif