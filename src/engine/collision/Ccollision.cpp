#include "Ccollision.h"

Ccollision::Ccollision() {
	init();
}

Ccollision::~Ccollision() {
	//dtor
}

void Ccollision::init() {
	this->gameObjects = NULL;
	this->iTime = NULL;
	lastTime = 0;
	stepTime = 0.0001; /**< Birim saniye, Çalışma frekansı  */
	this->NoO = 0;
}


void Ccollision::registerGameObject(CgameObject *gameObject) {
	this->NoO++;
    this->gameObjects=(CgameObject**)realloc(gameObjects, NoO*(sizeof(CgameObject*)));
	this->gameObjects[NoO-1] = gameObject;
}

void Ccollision::linkTime(Ctime *time) {
	this->iTime = time;
}
void Ccollision::step(void) {
	double deltaTime = 0;
	deltaTime = iTime->getCurrTime() - lastTime;
	if(deltaTime > stepTime) {
		for(int i = 0; i < this->NoO-1; i++) {
            for(int j=i; j < this->NoO; j++) {
                if(inArray(gameObjects[i]->collideWith, gameObjects[i]->NoC, gameObjects[i]->groupId)) {

                }
            }
        }
	}
    lastTime = iTime->getCurrTime();
}

bool Ccollision::circleLine(Ccircle circle, Cline line) {
    double vx = line.w - line.x;
    double vy = line.h - line.y;
    double xdiff = line.x - circle.x;
    double ydiff = line.y - circle.y;
    double a = pow(vx, 2) + pow(vy, 2);
    double b = 2 * ((vx * xdiff) + (vy * ydiff));
    double c = pow(xdiff, 2) + pow(ydiff, 2) - pow(circle.r, 2);
    double quad = pow(b, 2) - (4 * a * c);
    if (quad >= 0)
    {
        // An infinite collision is happening, but let's not stop here
       return true;
    }
    return false;

}

void Ccollision::testSignal(void) {
    for(int i = 0; i < this->NoO; i++) {
        gameObjects[i]->collide(1, 2);
    }
}


