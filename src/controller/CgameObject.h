#ifndef _CGAMEOBJECT_H
#define _CGAMEOBJECT_H


#include "../physics/Ccore.h"
#include "../graphics/Canimation.h"

class CgameObject {
  public:
    Ccore core;
    Canimation animation;

    CgameObject(void );

    void init(void );

    void setAnimation(double fps, int id, float w, float h);
    //private:
    void linkAnimation();
};
#endif
