
#include "Csprite.h"
namespace engine { namespace graphics{
Csprite::Csprite(void )
{

        init();
}
Csprite::~Csprite(void )
{

}
void Csprite::setFrameSize(float w, float h)
{

       fh=h;
       fw=w;
       // eðer belirtilmedi ise boyut texture ile aynı
       if(this->h==0) this->h=h;
       if(this->w==0) this->w=w;

}
void Csprite::setActive()
{
    isPlaying=true;
}
void Csprite::setPassive()
{
    isPlaying=false;
}
void Csprite::setFPS(int fps)
{
    this->fps=fps;
}
void Csprite::setTextureMap(int textureId)
{
    textId=textureId;
}
void Csprite::limitFrames(int from,int to)
{
    fromFrame=from;
    toFrame=to;
}
engine::geometrics::Cvector Csprite::getPosition()
{
    return this->core.position;
}


void Csprite::init()
{


    id=0;
    textId=0;
    fps=25;
    w=0;
    h=0;
    fh=0;
    fw=0;
    fc=0;
    isPlaying=true;
    invert=0;
    fromFrame=0;
    toFrame=0;
    debug=true;



}
}}
