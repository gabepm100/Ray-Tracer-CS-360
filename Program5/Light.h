#ifndef Light_HDR
#define Light_HDR
#include "Tuple.h"
#include "Rgb.h"

class Light{
    private:

    public:

    Tuple origin;
    Rgb coefficient;
    Light();
    Light(Tuple origin,Rgb coefficient);
};
#endif