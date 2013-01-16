
#include "CgameObject.h"

CgameObject::CgameObject(void ){

        init();
}

void CgameObject::init(void )
{
    core.init();
    animation.init();
}

void CgameObject::setAnimation(double fps, int id, float w, float h)
{

        animation.fps=fps;
        animation.textId=id;
        animation.setFrameSize(w,h);
        linkAnimation();
}
void CgameObject::linkAnimation()
{









}


