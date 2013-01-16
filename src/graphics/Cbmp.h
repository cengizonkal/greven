#ifndef _CBMP_H
#define _CBMP_H
#include <stdio.h>
#include <stdlib.h>
 
//#include "tools.h"
class Cbmp {
  public:
    //yükseklik
    int h;

    //geniþlik
    int w;

    //pixel renk kaç bit
    char bit;

    // yükseklik ve gemiþlik belirlenince hafýzada yer ayrýlacak
    char * pixel;

    void Dump();

    bool LoadBmp(char fileName[255]);

    void Free();

};
#endif
