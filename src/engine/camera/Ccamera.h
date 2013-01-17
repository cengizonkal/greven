#ifndef _CCAMERA_H
#define _CCAMERA_H



#include "../graphics/Csprite.h"
#include "../geometrics/Cvector.h"
#include "../../def.h"




class Ccamera
{
  public:
    Cvector position;
    float zoom;
    float radius;
    int mode;
    Csprite *sprite; ///<Link to sprite
    float seekTime;
    float deadZone;




    Ccamera(void );
    ~Ccamera(void );
    void init(void );
    void setLink(Csprite *s);
    Cvector getPosition();


};
#endif
