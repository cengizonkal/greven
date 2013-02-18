#ifndef _CGREVEN_H
#define _CGREVEN_H

#include <windows.h>
#include <gl/gl.h>
#include <stdio.h>

#include "../../def.h"
#include "../graphics/Ctexture.h"
#include "../graphics/Cbmp.h"
#include "../graphics/Ctga.h"
#include "../time/Ctime.h"
#include "../geometrics/Cvector.h"
#include "../camera/Ccamera.h"
#include "../globals/globals.h"

inline LRESULT CALLBACK   WndProc (HWND hWnd, UINT message,WPARAM wParam, LPARAM lParam)
    {
       switch (message)
        {
        case WM_CREATE:
            return 0;
        case WM_CLOSE:
            PostQuitMessage (0);
            return 0;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
            switch (wParam)
            {
            case VK_ESCAPE:
                PostQuitMessage(0);

                return 0;
            }
            return 0;

       default:
            return DefWindowProc (hWnd, message, wParam, lParam);
        }
    }
class Cgreven {
  public:
// TODO (Cengiz#1#): Burdaki değişkenler globals.cpp ye aktarılacak

    //bool keys[500]; /**< Tuşlar */


    bool end; /**< Oyun bitti */

    int status; /**< Durum */

    WNDCLASS wc; /**< Pencere Sınıfı */

    HWND hWnd; /**< Pencere Handler */

    HDC hDC; /**< Device Handler */

    HGLRC hRC; /**< OpenGl Handler */


    int height;/**< Pencere Yüksekliği */
    int width;/**< Pencere Genişliği */
    bool fullScreen; /**< Tam Ekran  */
    int NoO; /**< GameObject sayısı */
    CgameObject **gameObjects; /**< GameObjelerini Tutan Pointer dizisi*/

    DWORD dwExStyle;
    DWORD dwStyle;

    Ctime iTime;/**< Zaman Senkronizasyonu */


    Ccamera *camera;/**< Aktif Kamera */

     Cgreven();
     ~Cgreven();
     void createWindow();
     void EnableOpenGL();
     void DisableOpenGL();
     //opengl kapat
     void destroy(void );
     void drawCanvas();
     void clearCanvas();
     void peekMessage();
     void showMessage(char * message);
     void setCamera(Ccamera *camera);
     void registerGameObject(CgameObject *gameObject);
     void step(void);
     void dumpKeys(void);

     private:
     void releaseKeys(void);
     double lastTime;
};
#endif
