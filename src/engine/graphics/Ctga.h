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
    //y�kseklik
    int h;

    //geni�lik
    int w;

    //pixel renk ka� bit
    char bit;

    // y�kseklik ve gemi�lik belirlenince haf�zada yer ayr�lacak
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
