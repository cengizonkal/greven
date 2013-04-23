#include "Cgreven.h"



namespace engine { namespace greven {
Cgreven::Cgreven()
{
    height=600;
    width=800;
    end=false;
    fullScreen=false;
    mouseX=0;
    mouseY=0;
    releaseKeys();
    camera=NULL;
    lastTime=0;
    this->NoO = 0;
    this->gameObjects = NULL;
};

void Cgreven::releaseKeys(void)
{
    for(int i=0;i<500;i++)
        keys[i]=false;
}

void Cgreven::createWindow()
{

    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = NULL;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor =  LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "greven";
    RegisterClass (&wc);

    if (fullScreen)
    {
        dwExStyle=WS_EX_APPWINDOW;
        dwStyle=WS_VISIBLE |WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
        //ShowCursor(FALSE);
        DEVMODE dmScreenSettings; // Device Mode
        memset(&dmScreenSettings,0,sizeof(dmScreenSettings)); // Makes Sure Memory's Cleared
        dmScreenSettings.dmSize=sizeof(dmScreenSettings); // Size Of The Devmode Structure
        dmScreenSettings.dmPelsWidth = width; // Selected Screen Width
        dmScreenSettings.dmPelsHeight = height; // Selected Screen Height
        dmScreenSettings.dmBitsPerPel = 32; // Selected Bits Per Pixel
        dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;
        if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
            MessageBox(hWnd,"Fullscreen Error","Fullscreen Error",0);


    }
    else
    {
        dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
        dwStyle=WS_VISIBLE | WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
    }



    hWnd = CreateWindowEx(dwExStyle,
    wc.lpszClassName, "greven",
    dwStyle,
    0, 0, width, height,
    NULL, NULL, NULL, NULL);
    //MessageBox(hWnd,"a","a",0);

    EnableOpenGL ();

};

void Cgreven::EnableOpenGL()
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    /* TODO (#1#): pixel ayarlamalarý */

    pfd.cColorBits = 32;
    pfd.cDepthBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (hDC, &pfd);
    SetPixelFormat (hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    hRC = wglCreateContext( hDC );
    wglMakeCurrent( hDC, hRC );


    /*set scene*/



   glEnable(GL_DEPTH_TEST);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(90.0, (GLfloat) width/(GLfloat) height, 10.0, 1000.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 400.0, 0.0, 0.0, 0.0, 0.0, 1, 0.0);


    /*transparent*/
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /*enable arrays*/
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    /*
    glEnableClientState (GL_COLOR_ARRAY);
    glEnableClientState (GL_VERTEX_ARRAY);
    glColorPointer (3, GL_FLOAT, 0, colors);
    glVertexPointer (2, GL_INT, 0, vertices);
    */


};

void Cgreven::DisableOpenGL()
{
        wglMakeCurrent (NULL, NULL);
        wglDeleteContext (hRC);
        ReleaseDC (hWnd, hDC);
};

 void Cgreven::destroy(void )
 {
            /* shutdown OpenGL */
            DisableOpenGL ();
            DestroyWindow (hWnd);
        };

 void Cgreven::drawCanvas()
    {
        double deltaTime=0;
        deltaTime=iTime.getCurrTime()-lastTime;

        engine::geometrics::Cvector pos = camera->getPosition(deltaTime);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt (camera->position.x, camera->position.y, 400.0, camera->position.x, camera->position.y, 0.0, 0.0, 1, 0.0);
        SwapBuffers (hDC);

        lastTime=iTime.getCurrTime();
    };
void Cgreven::clearCanvas()
{
        glClearColor (0, 0.0f, 0.0f, 1);
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
 void Cgreven::peekMessage() {
      	 MSG msg;
    	 if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
            {
                switch(msg.message)
                {
                    case WM_QUIT:
                        end = TRUE;
                    break;
                    case WM_KEYDOWN:
                        keys[msg.wParam]=true;
                        if(msg.wParam==VK_ESCAPE)
                            end=true;
                    break;
                    case WM_KEYUP:
                        keys[msg.wParam]=false;
                    break;
                    case WM_MOUSEMOVE:
                        mouseX=LOWORD(msg.lParam);
                        mouseY=height - HIWORD(msg.lParam);
                        break;
                    case WM_LBUTTONDOWN:
                        keys[msg.wParam]=true;
                        break;
                    case WM_LBUTTONUP:
                        keys[1]=false;
                        break;
                    case WM_RBUTTONDOWN:
                        keys[msg.wParam]=true;
                        break;
                    case WM_RBUTTONUP:
                        keys[2]=false;
                        break;

                    default:
                        TranslateMessage (&msg);
                        DispatchMessage (&msg);
                }
            }
     	};

void Cgreven::showMessage(char * message)
{
    MessageBox(hWnd,message,"Greven",0);
};
void Cgreven::setCamera(engine::camera::Ccamera *camera)
{
    camera->position.SetZero();
    this->camera=camera;
}
Cgreven::~Cgreven()
{
 Cgreven::DisableOpenGL();
 Cgreven::destroy();
};

void Cgreven::registerGameObject(engine::gameobject::CgameObject *gameObject) {
    this->NoO++;
    this->gameObjects=(engine::gameobject::CgameObject**)realloc(gameObjects, NoO*(sizeof(engine::gameobject::CgameObject*)));
    this->gameObjects[NoO-1] = gameObject;

}

void Cgreven::step(void) {
    for(int i=0;i<this->NoO;i++) {
        this->gameObjects[i]->cycle();
    }

    //this->dumpKeys();


}
void Cgreven::dumpKeys(void)
{
    for(int i=0;i<500;i++) {
        if(keys[i]==true) {
            trace("%i ",i);
        }
    }
}
}
}
