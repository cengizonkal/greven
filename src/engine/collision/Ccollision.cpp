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
                    if((gameObjects[i]->type == LINE) && (gameObjects[j]->type == CIRCLE)) {
                        if(this->circleLine(gameObjects[j]->circle, gameObjects[i]->line)) {
                            gameObjects[i]->collide(gameObjects[j]->id, gameObjects[j]->groupId);
                            gameObjects[j]->collide(gameObjects[i]->id, gameObjects[i]->groupId);
                        }
                    }else if((gameObjects[j]->type == LINE) && (gameObjects[i]->type == CIRCLE)) {
                        if(this->circleLine(gameObjects[i]->circle, gameObjects[j]->line)) {
                            gameObjects[i]->collide(gameObjects[j]->id, gameObjects[j]->groupId);
                            gameObjects[j]->collide(gameObjects[i]->id, gameObjects[i]->groupId);
                        }
                    }
                }
            }
        }
	}
    lastTime = iTime->getCurrTime();
}

bool Ccollision::circleLine(Ccircle c, Cline l) {
	float x1;
	float x2;
	float y;


	if(l.x > l.w) {
		x1 = l.x;
		x2 = l.w;

	} else {
		x1 = l.w;
		x2 = l.x;

	}

	//y all the same
	y = l.y;

	if(((c.x + c.r) > x2)
        && ((c.x - c.r) < x1)
        && ((c.y - c.r) <= y
        && (c.y + c.r) > y)) {
		return true;
	} else
		return false;


}


