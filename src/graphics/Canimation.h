#ifndef _CANIMATION_H
#define _CANIMATION_H
#include <stdio.h>
#include <stdlib.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "../geometrics/Cpoint.h"
#include "../geometrics/Ccircle.h"


class Canimation {
  public:
    /*! Core class referansı, obje haraket edince grafikte haraket edecek*/

    int id;


    int textId; ///< texture bağlamak için gereken id


    double fps; ///< animasyon hızı


    float w;
    float h;


    float fh;///< texture üzerindeki frame boyutu
    float fw;///< texture üzerindeki frame boyutu


    double fc;/// şuan hangi frame de

    bool isPlaying; ///aktif mi


    char invert; /// 0,1 dikey,2 yatay

    /*! Hangi Frameler Arasında*/
    int fromFrame;
    int toFrame;




    Canimation(void );
    ~Canimation(void );
    void setFrameSize(float w, float h);
    void init();

};
#endif
