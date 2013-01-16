#include "Cgeo.h"
Cgeo::Cgeo(void) 
{
}

Cgeo::~Cgeo(void) 
{
}

void Cgeo::init(void){};

void Cgeo::rotatePoint(double *dx,double *dy,double sx,double sy,double angle)
{
     double tx=0,ty=0;
     angle=angle*PI;
     
     
     tx=*dx;
     ty=*dy;
     *dx = sx + (tx - sx) * cos(angle) - (ty - sy) * sin(angle);
     *dy = sy + (tx - sx) * sin(angle) + (ty - sy) * cos(angle);
     
     
}

void Cgeo::rotatePoint(Cpoint *pnt,Cpoint pPnt,double angle)
{
     double tx=0,ty=0;
     angle=angle*3.14/180;

     tx=pnt->x;
     ty=pnt->y;
     pnt->x = pPnt.x + (tx - pPnt.x) * cos(angle) - (ty - pPnt.y) * sin(angle);
     pnt->y = pPnt.y + (tx - pPnt.x) * sin(angle) + (ty - pPnt.y) * cos(angle);
     
     
}

void Cgeo::rotatePoint(double *dx,double *dy,Cpoint pPnt,double angle)
{
     double tx=0,ty=0;
     angle=angle*3.14/180;

     tx=*dx;
     ty=*dy;
     *dx = pPnt.x + (tx - pPnt.x) * cos(angle) - (ty - pPnt.y) * sin(angle);
     *dy = pPnt.y + (tx - pPnt.x) * sin(angle) + (ty - pPnt.y) * cos(angle);
     
     
}
void Cgeo::rotateCircle(Ccircle *crc,Cpoint pPnt,double angle)
{
     double tx=0,ty=0;
     angle=angle*3.14/180;

     tx=crc->x;
     ty=crc->y;
     crc->x = pPnt.x + (tx - pPnt.x) * cos(angle) - (ty - pPnt.y) * sin(angle);
     crc->y = pPnt.y + (tx - pPnt.x) * sin(angle) + (ty - pPnt.y) * cos(angle);
     
}

void Cgeo::rotateCircle(Ccircle *crc,Ccircle pPnt,double angle)
{
     double tx=0,ty=0;
     angle=angle*3.14/180;

     tx=crc->x;
     ty=crc->y;
     crc->x = pPnt.x + (tx - pPnt.x) * cos(angle) - (ty - pPnt.y) * sin(angle);
     crc->y = pPnt.y + (tx - pPnt.x) * sin(angle) + (ty - pPnt.y) * cos(angle);
     
}
