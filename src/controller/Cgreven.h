#ifndef _CGREVEN_H
#define _CGREVEN_H

#include <windows.h>
#include <gl/gl.h>
#include <stdio.h>

#include "../def.h"
#include "../graphics/Ctexture.h"
#include "../graphics/Cbmp.h"
#include "../graphics/Ctga.h"
#include "../time/Ctime.h"
#include "../geometrics/Cvector.h"
#include "Ccamera.h"

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
    //keys
    bool keys[500];
    float mouseX;
    float mouseY;
    ///til end
    bool end;
    ///status report 1-loading texures,2-loading sounds,3-making some stuff
    int status;
    ///window class
    WNDCLASS wc;
    ///window handler
    HWND hWnd;
    ///handler device
    HDC hDC;
    ///opengl handler
    HGLRC hRC;

    ///Pencere Özellikleri
    int height;
    int width;
    bool fullScreen;

    DWORD dwExStyle;
    DWORD dwStyle;
    ///Senkronize olmak için Zaman
    Ctime iTime;

    ///Aktif Kamera
    Ccamera *camera;

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

     private:
     void releaseKeys(void);
     double lastTime;
};
#endif
