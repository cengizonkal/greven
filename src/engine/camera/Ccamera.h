#ifndef _CCAMERA_H
#define _CCAMERA_H

#include <windows.h>

#include "../gameObject/CgameObject.h"
#include "../geometrics/Cvector.h"
#include "../globals/globals.h"
#include "../../def.h"
#include "../../tools.h"




class Ccamera
{
  public:
    Cvector position;
    float zoom;
    float radius;
    int mode;
    CgameObject *gameObject; ///<Link to sprite
    float seekTime;
    float deadZone;
    Cvector speed;
    float speedA;





    Ccamera(void );
    ~Ccamera(void );
    void init(void );
    void setLink(CgameObject *go);
    Cvector getPosition(double deltaTime);


};
#endif
