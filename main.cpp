#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include "src/engine/engine.h"
#include "src/game/Craziel.h"
#include "src/game/Cfloor.h"

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{

//    trace("\n\nProgram Başı.");
    engine::greven::Cgreven greven;
    engine::graphics::Cgraphic gr;
    engine::collision::Ccollision collision;
    engine::physics::Cphysics ph;

    greven.createWindow(); /**< GL burda aktivite ediliyor bu yüzden grafik işlemlerinden önce olmalı */
    ph.linkTime(&greven.iTime);
    gr.linkTime(&greven.iTime);
    collision.linkTime(&greven.iTime);
    gr.loadResources("res/resources.xml");





    Craziel raziel;
    Cfloor floor;


    collision.registerGameObject(&raziel);
    collision.registerGameObject(&floor);
    //collision.testSignal();




    //gr.registerGameObject(&a);
    gr.registerGameObject(&raziel);
    gr.registerGameObject(&floor);
    greven.registerGameObject(&raziel);
    ph.registerGameObject(&raziel);





    engine::camera::Ccamera camera;

    camera.mode = CAM_FIXED;
    camera.setPosition(0, 0);
    greven.setCamera(&camera);

    gr.loadResources("res/resources.xml");
    while (!greven.end)
    {

        greven.peekMessage(); /**< Tuşları oku */
        greven.clearCanvas();/**< Ekranı temizle */

        greven.step();
        ph.step();
        collision.step();
        gr.step();

        //gr.test();
        greven.drawCanvas();/**<  */
    }
    greven.destroy();

    //trace("\nProgram sonu.");
    return 0;
}



