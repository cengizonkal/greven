#include "Clevel.h"
#include "../../tools.h"
#include "../xml/simplexml.h"
namespace engine { namespace level {
Clevel::Clevel(void) {
	init();
}
Clevel::~Clevel(void) {

}

void Clevel::init(void) {
	this->currentLevel = 1;
}

void Clevel::loadLevel() {
	/*FILE *fp;
	char fileName[255];
	char xmlFile[4096];
	simplexml *root;
	simplexml *ptr;
	int ground = 0;

	sprintf(fileName, "%s%d.gr", "levels/level", currentLevel);
	fp = fopen(fileName, "r");

	if(!fp) {
		writeError("%s %d", "Level dosyası yok!", currentLevel);
	} else {
		//load grounds
		fread(xmlFile, 1, 4000, fp);
		//writeError("%s",xmlFile);
		root = new simplexml(xmlFile);
		ground = root->child("grounds")->number_of_children();

		for(int i = 0; i < ground; i++) {
			ptr = root->child("grounds")->child("ground", i);

			float ax;
			float ay;
			float bx;
			float by;
			ax = atof(ptr->child("pointA")->child("x")->value());
			ay = atof(ptr->child("pointA")->child("y")->value());
			bx = atof(ptr->child("pointB")->child("x")->value());
			by = atof(ptr->child("pointB")->child("y")->value());



			Cground g;
			g.setGround(ax, ay, bx, by);
			this->addGround(g);


		}

	}*/


}
}
}

