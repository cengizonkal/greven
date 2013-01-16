#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "src/controller/Cgreven.h"
#include "src/graphics/Cgraphic.h"
# include "src/graphics/Canimation.h"
# include "src/graphics/Csprite.h"
# include "src/physics/Cphysics.h"
# include "src/physics/Ccore.h"
# include "src/controller/CgameObject.h"
# include "src/controller/Ccamera.h"
# include "src/controller/Craziel.h"
# include "src/level/Clevel.h"
# include "src/collision/Ccollision.h"


int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{


    Cgreven greven; /// eventleri dinleyen
    Cgraphic gr; ///grafik işlemleri için, sprite çiz vs
    gr.debug=false;
    Cphysics ph; /// fizikçi
    Ccamera camera;
    Clevel level;
    Ccollision collision;

    Cground bottom;
    level.loadLevel();
    gr.setLevel(&level);

    Craziel player;







    greven.createWindow(); ///greven pencere oluşturdu



    player.setTextureMap(0);
    player.setFPS(15);
    player.setFrameSize(156,128);
    player.linkTime(&greven.iTime);

    ///! zamanları bağla ki tüm işlemlerdeki zamanlama doğru olsun
    gr.linkTime(&greven.iTime);
    ph.linkTime(&greven.iTime);

    ///! gerekli kaynakları çağır
    gr.loadTextures();
    gr.load3DModels();

    //collision
    collision.linkTime(&greven.iTime);
    collision.registerLevel(&level);
    collision.registerPlayer(&player);






    /*
        Sprite sadece, bilgi içerir gerekli çizim ve fizik işlemleri
        diğer sınıflar tarafında yapılır.
    */

    gr.registerSprite(&player);



    ph.registerSprite(&player);



    ///Kamera Bağlama işlemi
    camera.setLink(&player);

    greven.setCamera(&camera);

    while (!greven.end)
    {


        greven.peekMessage(); //check for input events

        greven.clearCanvas();
        ph.step();
        collision.step();

        if(greven.keys['A'])
        {

            player.moveLeft();
        }
        if(greven.keys['D'])
        {
            player.moveRight();

        }
        if(greven.keys['W'])
        {
            greven.keys['W']=false;
            player.jump();

        }

        if((!greven.keys['A']) && !(greven.keys['D']))
        {
            player.resetAccTime();
            player.isPlaying=false;
        }

        gr.draw3DModels();
        gr.drawSprites();
        gr.animateSprites();
        gr.drawLevel();
        greven.drawCanvas();


    }
    greven.destroy();



}



