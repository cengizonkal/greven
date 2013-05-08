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
#include "../xml/Csimplexml.h"
#include "../../def.h"
#include "../../tools.h"


namespace engine { namespace graphics{
class Cgraphic {
public:

	int NoA;
	engine::graphics::Canimation **animations;
	bool debug;

	int No3D;
	engine::graphics::C3Dmodel * models;
	engine::graphics::Ctexture * textures;
	int NoT;
	//geometrik iþlemler için
	engine::geometrics::Cgeo geo;
	engine::graphics::C3DmodelLoader modelLoader;
	//kamera
	engine::camera::Ccamera *camera;

	//level register
	engine::level::Clevel *level;


	Cgraphic(void );
	~Cgraphic(void );
	void init(void );


	//draw functions
	void drawAnimations(void );
	void draw3DModels();
	void drawLevel();


	void linkTime(engine::time::Ctime * t);
	void animate(void );
	void animateSprites(void );
	//void load3DModels(void );
	//void loadTextures(void );
	void setCamera(engine::camera::Ccamera *c);
	void registerAnimation(Canimation *a);
	void loadResources(char *fileName);
	void dump(void);
	void test(void);
	void testLoadTexture(void);


private:
	engine::time::Ctime * iTime;
	double lastTime;
	void loadTexture(char * fileName);
	void loadBMP(char *fileName);
	void loadTGA(char *fileName);

};
}}
#endif

