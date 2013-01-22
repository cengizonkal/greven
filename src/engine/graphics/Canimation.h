#ifndef _CANIMATION_H
#define _CANIMATION_H
#include <stdio.h>
#include <stdlib.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "../physics/Ccore.h"


class Canimation : public Ccore {
  public:
    bool debug;/**< Çizgileri göster */
    int textId; /**<texture bağlamak için gereken id  */
    double fps; /**< animasyon hızı, frame per second */
    float w;
    float h;
    float fh;/**< texture üzerindeki frame boyutu */
    float fw;/**< texture üzerindeki frame boyutu */

    double fc;/**< şuan hangi frame de */

    bool isPlaying; /**< aktif mi  */

    char invert; /**<0,1 dikey,2 yatay  */

    /**<  Hangi Frameler Arasında*/
    int fromFrame;
    int toFrame;

    Canimation(void );
    ~Canimation(void );
    void setFrameSize(float w, float h);
    void setTextureMap(int textureId);
    void setActive();
    void setPassive();
    void setFPS(int fps);
    void limitFrames(int from,int to);
    Cvector getPosition();
    void init();

};
#endif
