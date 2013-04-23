#ifndef _CCORE_H
#define _CCORE_H


#include "../geometrics/Cvector.h"
#include "../geometrics/Cpoint.h"
#include "../geometrics/Ccircle.h"

#include <stdio.h>
#include <stdlib.h>
namespace engine { namespace physics {

class Ccore {
  public:

    engine::geometrics::Cvector velocity;
    engine::geometrics::Cvector force;
    engine::geometrics::Cvector position;
    double mass;
    bool hasGravity;
    bool movable;


    Ccore(void );
    void init(void);
    void addForce(engine::geometrics::Cvector force);

};
}
}
#endif
