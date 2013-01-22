#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "src/engine/engine.h"
#include "src/game/Craziel.h"

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{


    /*Cgreven greven;
    Cgraphic gr;
    gr.debug=false;
    Cphysics ph;
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

   //zamanları bağla ki tüm işlemlerdeki zamanlama doğru olsun
    gr.linkTime(&greven.iTime);
    ph.linkTime(&greven.iTime);

    ///! gerekli kaynakları çağır
    gr.loadTextures();
    gr.load3DModels();

    //collision
    collision.linkTime(&greven.iTime);









    gr.registerAnimation(&player);
    ph.registerCore(&player);
    collision.registerGameObject(&player);



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
*/


}



