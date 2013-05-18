#ifndef _CANIMATION_H
#define _CANIMATION_H
#include <stdio.h>
#include <stdlib.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "../physics/Ccore.h"

namespace engine { namespace graphics{
class Canimation : public engine::physics::Ccore {
  public:
    bool debug;/**< Çizgileri göster */
    int textId; /**<texture bağlamak için gereken id  */
    double fps; /**< animasyon hızı, frame per second */
    float w;/**< .ekran üzerindeki boyutu */
    float h;/**< .ekran üzerindeki boyutu */

    float fh;/**< texture üzerindeki frame boyutu */
    float fw;/**< texture üzerindeki frame boyutu */

    double fc;/**< şuan hangi frame de */

    bool isPlaying; /**< aktif mi  */
    int loop; /**<Kaç defa donecek -1 sonsuz,  */

    char invert; /**<0,1 dikey,2 yatay  */

    /**<  Hangi Frameler Arasında*/
    int fromFrame;
    int toFrame;

    Canimation(void );
    ~Canimation(void );
    void setFrameSize(float w, float h);
    void setSize(float w, float h);
    void setTextureMap(int textureId);
    void setActive();
    void setPassive();
    void setFPS(int fps);
    void limitFrames(int from,int to);
    engine::geometrics::Cvector getPosition();
    void playAndStop(int from, int to);
    void playAndLoop(int from, int to);
    void playAndStop(void);
    void playAndLoop(void);
    void setActiveFrame(int frame); /**< Aktif frame i set eder */
    void setFrames(int from, int to);

    void init();

};
}}
#endif
