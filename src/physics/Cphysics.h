#ifndef _PHYSICS_H
#define _PHYSICS_H
# include "Ccore.h"
# include "../geometrics/Ccircle.h"
# include "../time/Ctime.h"

# include "../geometrics/Cgeo.h"
# include "../graphics/Csprite.h"
# include <math.h>




class Cphysics
{
    public:
    //comon time
    Ctime * iTime;
    Ccore **cores;

    //number of cores
    int NoC;

    //world gravity
    Cvector gravity;
    double lastTime;
    float freeMove; //free slide time 1 second


    public:

    Cphysics();
    ~Cphysics();

    void registerSprite(Csprite *s);
    void linkTime(Ctime * t);
    void step(void);
    void init(void);


};

#endif
