#ifndef _PHYSICS_H
#define _PHYSICS_H
# include "Ccore.h"
# include "../geometrics/Ccircle.h"
# include "../time/Ctime.h"

# include "../geometrics/Cgeo.h"
# include "../graphics/Csprite.h"
#include "../../tools.h"
# include <math.h>



namespace engine { namespace physics {
class Cphysics
{
    public:

    engine::time::Ctime * iTime;/**< Common time */
    Ccore **cores;/**< Objeler */


    int NoC;/**< obje sayısı */


    engine::geometrics::Cvector gravity;/**< Bu dünyadaki yerçekimi */
    double lastTime;
    float freeMove; /**< 1 saniye kay */


    public:

    Cphysics();
    ~Cphysics();

    void registerCore(Ccore *c);
    void linkTime(engine::time::Ctime * t);
    void step(void);
    void init(void);


};
}
}
#endif
