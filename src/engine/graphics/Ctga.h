#ifndef _CTGA_H
#define _CTGA_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include "../../tools.h"
namespace engine { namespace graphics{
class Ctga
{
  public:
    //yükseklik
    int h;

    //geniþlik
    int w;

    //pixel renk kaç bit
    char bit;

    // yükseklik ve gemiþlik belirlenince hafýzada yer ayrýlacak
    char * pixel;

    char fileName[255];

    Ctga();
    ~Ctga();
    void Dump();
    bool LoadTga(char fName[255]);
    void Free();
};
}}
#endif
