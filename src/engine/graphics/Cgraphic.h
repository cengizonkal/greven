#ifndef _CGRAPHIC_H
#define _CGRAPHIC_H

#include "Canimation.h"
#include "../time/Ctime.h"
#include "C3Dmodel.h"
#include "C3DmodelLoader.h"
#include "Ctexture.h"
#include "Cbmp.h"
#include "Ctga.h"
#include "../geometrics/Cgeo.h"
#include "../geometrics/Cpoint.h"
#include "../camera/Ccamera.h"
#include "../level/Clevel.h"
#include "../gameObject/CgameObject.h"
#include "../../def.h"



class Cgraphic {
    public:

        int NoA;
        Canimation * * animations;
        bool debug;

        int No3D;
        C3Dmodel * models;
        Ctexture * textures;
        int NoT;
        //geometrik iþlemler için
        Cgeo geo;
        C3DmodelLoader modelLoader;
        //kamera
        Ccamera *camera;

        //level register
        Clevel *level;


        Cgraphic(void );
        ~Cgraphic(void );
        void init(void );


        //draw functions
        void drawAnimations(void );
        void draw3DModels();
        void drawLevel();


        void linkTime(Ctime * t);
        void animate(void );
        void animateSprites(void );
        void load3DModels(void );
        void loadTextures(void );
        void setCamera(Ccamera *c);
        void setLevel(Clevel *level);
        void registerAnimation(Canimation *a);

    private:
        Ctime * iTime;
        double lastTime;
        void loadTexture(char * fileName);

};
#endif

