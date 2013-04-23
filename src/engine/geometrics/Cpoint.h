#ifndef _CPOINT_H
#define _CPOINT_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/***
   geometrik iþlemler için class
**/
namespace engine { namespace geometrics{
class Cpoint
{
  public:
  float x;
  float y;

    Cpoint(void );
    ~Cpoint(void );
    void init(void);




};
}}
#endif
