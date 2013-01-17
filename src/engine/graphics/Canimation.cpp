
#include "Canimation.h"

Canimation::Canimation(void )
{

        init();
}
Canimation::~Canimation(void )
{


}
void Canimation::setFrameSize(float w, float h)
{

       fh=h;
       fw=w;
       // eðer belirtilmedi ise boyut texture ile ayný
       if(this->h==0) this->h=h;
       if(this->w==0) this->w=w;

}

void Canimation::init()
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



}

