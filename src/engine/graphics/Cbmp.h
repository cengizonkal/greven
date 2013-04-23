#ifndef _CBMP_H
#define _CBMP_H
#include <stdio.h>
#include <stdlib.h>
#include "../../tools.h"

//#include "tools.h"
namespace engine { namespace graphics{
class Cbmp {
  public:

    int h;/**< Yükseklik */
    int w;/**< Genişlik */
    char bit; /**< Bit */
    char *pixel;/**< Data pixel */
    char fileName[255];
    void Dump(); /**< Döküm */
    bool LoadBmp(char fileName[255]);
    void Free();

};
}}
#endif
