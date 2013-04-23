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

    trace("\n\nProgram Başı.");
    engine::greven::Cgreven greven;
    engine::graphics::Cgraphic gr;
    engine::collision::Ccollision collision;

    greven.createWindow(); /**< GL burda aktivite ediliyor bu yüzden grafik işlemlerinden önce olmalı */

    gr.linkTime(&greven.iTime);
    gr.loadResources("res/resources.xml");

    engine::graphics::Canimation a;

    a.setTextureMap(2); /**< Bu kısmın level dosyasından alınması gerekiyor */
    a.setFrameSize(156,128);
    a.setFPS(15);
    a.setSize(156,128);
    a.setActive();

    Craziel raziel;
    collision.registerGameObject(&raziel);
    collision.testSignal();




    gr.registerAnimation(&a);
    gr.dump();




    engine::camera::Ccamera camera;
    greven.setCamera(&camera);

    gr.loadResources("res/resources.xml");
    while (!greven.end)
    {

        greven.peekMessage(); /**< Tuşları oku */
        greven.step();
        greven.clearCanvas();/**< Ekranı temizle */
        gr.drawAnimations();
        gr.animate();
        //gr.test();
        greven.drawCanvas();/**<  */
    }
    greven.destroy();

    trace("\nProgram sonu.");
    return 0;
}



