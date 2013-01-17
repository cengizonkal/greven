#include "Ccamera.h"

Ccamera::Ccamera(void )
{
 init();

}
Ccamera::~Ccamera(void )
{


}
void Ccamera::init(void)
{
     this->position.Set(0,0);
     this->zoom=1;
     mode=CAM_FOLLOW;
     seekTime=0.5; //bir saniye içinde
     deadZone=5; //5 pxelden küçükse hareket etme
}
void Ccamera::setLink(Csprite *s)
{
     sprite=s;
     mode=CAM_FOLLOW;

}
Cvector  Ccamera::getPosition()
{

   return this->position;

}
