#ifndef _PHYSICS_H
#define _PHYSICS_H
# include "Ccore.h"
# include "../geometrics/Ccircle.h"
# include "../time/Ctime.h"

# include "../geometrics/Cgeo.h"
# include "../graphics/Csprite.h"
#include "../../tools.h"
# include <math.h>




class Cphysics
{
    public:

    Ctime * iTime;/**< Common time */
    Ccore **cores;/**< Objeler */


    int NoC;/**< obje sayısı */


    Cvector gravity;/**< Bu dünyadaki yerçekimi */
    double lastTime;
    float freeMove; /**< 1 saniye kay */


    public:

    Cphysics();
    ~Cphysics();

    void registerCore(Ccore *c);
    void linkTime(Ctime * t);
    void step(void);
    void init(void);


};

#endif
