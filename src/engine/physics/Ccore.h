#ifndef _CCORE_H
#define _CCORE_H


#include "../geometrics/Cvector.h"
#include "../geometrics/Cpoint.h"
#include "../geometrics/Ccircle.h"

#include <stdio.h>
#include <stdlib.h>

class Ccore {
  public:

    int id;
    Cvector velocity;
    Cvector force;
    Cvector position;
    float radius;
    double mass;
    bool hasGravity;
    bool movable;


    Ccore(void );
    void init(void);
    void addForce(Cvector force);
    void setRadius(float r);

};
#endif
