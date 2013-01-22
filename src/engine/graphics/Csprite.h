#ifndef _CSPRITE_H
#define _CSPRITE_H
#include <stdio.h>
#include <stdlib.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "../geometrics/Ccircle.h"
#include "../geometrics/Cvector.h"
#include "../physics/Ccore.h"

class Csprite {
  public:

    /*b2Body *body; ///< Fiziksel vücut, animasyon konumunu bu nesneden alacak
    b2BodyDef bodyDef;
    b2PolygonShape shape;
    b2FixtureDef fixtureDef;*/
    Ccore core;
    Ccircle circle;
    bool debug;/**< Çizgileri göster */
    int id; /**< Hangi Sprite ? */
    int textId; /**< texture bağlamak için gereken id*/
    double fps; /**< animasyon hızı */


    float w; /**<  Genişlik*/
    float h; /**< Yükseklik */


    float fh;/**< texture üzerindeki frame boyutu */
    float fw;/**< texture üzerindeki frame boyutu */


    double fc;/**< şuan hangi frame de */

    bool isPlaying; /**< aktif mi */


    char invert; /**< 0,1 dikey,2 yatay */


    int fromFrame;/**< Animasyonun hangi frameler arasında olduğunu gösterir */
    int toFrame;/**< Animasyonun hangi frameler arasında olduğunu gösterir */




    Csprite(void );
    ~Csprite(void );
    void setFrameSize(float w, float h);
    void setFPS(int fps);
    void setTextureMap(int textureId);
    void setActive();
    void setPassive();
    void limitFrames(int from,int to);
    Cvector getPosition();
    void init();

};
#endif
