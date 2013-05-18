#ifndef _CCAMERA_H
#define _CCAMERA_H

#include <windows.h>

#include "../gameObject/CgameObject.h"
#include "../geometrics/Cvector.h"
#include "../globals/globals.h"
#include "../../def.h"
#include "../../tools.h"


namespace engine{ namespace camera{

class Ccamera
{
  public:
    engine::geometrics::Cvector position;
    float zoom;
    float radius;
    int mode;
    engine::gameobject::CgameObject *gameObject; ///<Link to sprite
    float seekTime;
    float deadZone;
    engine::geometrics::Cvector speed;
    float speedA;





    Ccamera(void );
    ~Ccamera(void );
    void init(void );
    void setLink(engine::gameobject::CgameObject *go);
    engine::geometrics::Cvector getPosition(double deltaTime);
    void setPosition(float x, float y);


};
}
}
#endif
