#ifndef _CBMP_H
#define _CBMP_H
#include <stdio.h>
#include <stdlib.h>
 
//#include "tools.h"
class Cbmp {
  public:
    //y�kseklik
    int h;

    //geni�lik
    int w;

    //pixel renk ka� bit
    char bit;

    // y�kseklik ve gemi�lik belirlenince haf�zada yer ayr�lacak
    char * pixel;

    void Dump();

    bool LoadBmp(char fileName[255]);

    void Free();

};
#endif
