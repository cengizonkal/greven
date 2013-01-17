#ifndef _CGEO_H
#define _CGEO_H

#ifndef PI
#define PI 3.14159
#endif

#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include "Cpoint.h"
#include "Ccircle.h"

/***
   geometrik iþlemler için class
**/
class Cgeo
{
  public:
    
         
    Cgeo(void );
    ~Cgeo(void );
    void init(void);
    void rotatePoint(double *dx,double *dy,double sx,double sy,double angle);
    void rotatePoint(Cpoint *pnt,Cpoint pPnt,double angle);
    void rotatePoint(double *dx,double *dy,Cpoint pPnt,double angle);
    void rotateCircle(Ccircle *crc,Cpoint pPnt,double angle);
    void rotateCircle(Ccircle *crc,Ccircle pPnt,double angle);

};
#endif
