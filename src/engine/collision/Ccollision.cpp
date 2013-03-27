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
	this->NoO = 0;/**< Obje sayısı */
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

bool Ccollision::circleLine(Ccircle *circle, Cline *line) {
    double vx = line->w - line->x;
    double vy = line->h - line->y;
    double xdiff = line->x - circle->x;
    double ydiff = line->y - circle->y;
    double a = pow(vx, 2) + pow(vy, 2);
    double b = 2 * ((vx * xdiff) + (vy * ydiff));
    double c = pow(xdiff, 2) + pow(ydiff, 2) - pow(circle->r, 2);
    double quad = pow(b, 2) - (4 * a * c);
    if (quad >= 0)
    {
       return true;
    }
    return false;

}

void Ccollision::testSignal(void) {
    for(int i = 0; i < this->NoO; i++) {
        gameObjects[i]->collide(1, 2);
    }
}
bool Ccollision::circleCircle(Ccircle *c1, Ccircle *c2) {
    double distX = c1->x - c2->x;
    double distY = c1->y - c2->y;
    double dist = sqrt((distX*distX ) + (distY*distY));

    if(dist <= (c1->r + c2->r))
        return true;
    else
        return false;
}

bool Ccollision::lineLine(Cline *l1, Cline *l2) {
    return false;
}

bool Ccollision::objectObject(CgameObject *g1, CgameObject *g2) {
    for(int i = 0; i<(g1->NoC + g1->NoL); i++) {
        for(int j = 0; j<(g2->NoC + g2->NoL);j++) {
            //circle
            if(i<g1->NoC) {
                //circle
                if(j<g2->NoC) {
                   if(circleCircle(&g1->circles[i], &g2->circles[j])){
                        return true;
                   }
                }
                //line
                if(j>=g2->NoC) {
                    if(circleLine(&g1->circles[i], &g2->lines[j])) {
                        return true;
                    }
                }
            }
            //line
            if(i>=g1->NoC) {
                //circle
                if(j<g2->NoC) {
                   if(circleLine(&g2->circles[j], &g1->lines[i])){
                        return true;
                   }
                }
                //line
                if(j>=g2->NoC) {
                    if(lineLine(&g1->lines[i], &g2->lines[j])) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


