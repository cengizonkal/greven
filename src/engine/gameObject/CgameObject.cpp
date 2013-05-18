#include "CgameObject.h"
namespace engine {
namespace gameobject {
CgameObject::CgameObject() {
	this->init();    //ctor
}

CgameObject::~CgameObject() {
	//dtor
}
void CgameObject::init(void) {
	this->NoG = 0;
	this->NoC = 0;
	this->NoL = 0;
	this->collideWith = NULL;
	this->type = 0;
	this->groupId = 0;
	this->id = engine::state::Cstate::getId(); /**< Her objenin eşsiz bir id olacak  */
	this->isInScreen = true;
	this->collisionType = CIRCLE;
	this->lines = NULL;
	this->circles = NULL;
	this->hasCollision = true;
}

void CgameObject::addCollideGroup(int groupId) {
	NoG++;
	collideWith = (int*) realloc(collideWith, sizeof(int) * NoG);
	collideWith[NoG - 1] = groupId;
}

//TODO şüpheli
void CgameObject::removeCollideGroup(int groupId) {
	for(int i = 0; i < this->NoG; i++) {
        if(this->collideWith[i] == groupId){
            free(&this->collideWith[i]);
        }
	}
	this->NoG--;
}

void CgameObject::addCircleCollider(engine::collision::Ccircle circle) {
	this->NoC++;
	this->circles = (engine::collision::Ccircle*) realloc(circles, sizeof(engine::collision::Ccircle) * this->NoC);
	this->circles[this->NoC - 1] = circle;
}
void CgameObject::addLineCollider(engine::collision::Cline line) {
	this->NoL++;
	this->lines = (engine::collision::Cline*) realloc(lines, sizeof(engine::collision::Cline) * this->NoL);
	this->lines[this->NoL - 1] = line;
}

// TODO (Cengiz#1#): game objesi için yardımcı fonksiyonlar yazılacak ...
//setter getter
void CgameObject::addCircleCollider(float relativeX, float relativeY, float r) {
    engine::collision::Ccircle circle;
    circle.relativePosition.Set(relativeX, relativeY);
    circle.r = r;
    this->NoC++;
	this->circles = (engine::collision::Ccircle*) realloc(circles, sizeof(engine::collision::Ccircle) * this->NoC);
	this->circles[this->NoC - 1] = circle;

}
void CgameObject::addLineCollider(float x1, float y1, float x2, float y2) {
    engine::collision::Cline line;
    line.relativePoint1.Set(x1, y1);
    line.relativePoint2.Set(x2, y2);
    this->NoL++;
	this->lines = (engine::collision::Cline*) realloc(lines, sizeof(engine::collision::Cline) * this->NoL);
	this->lines[this->NoL - 1] = line;

}
void CgameObject::setID(int ID) {
	this->id = ID;
}

int CgameObject::getID(void) {
	return this->id;
}

void CgameObject::setGroup(int groupId) {
    this->groupId = groupId;
}

void CgameObject::moveColliders(void){

    for(int i=0; i<this->NoL; i++) {
        this->lines[i].point1 = this->lines[i].relativePoint1 + this->position;
        this->lines[i].point2 = this->lines[i].relativePoint2 + this->position;
    }

    for(int i=0; i<this->NoC; i++) {
        this->circles[i].position = this->circles[i].relativePosition + this->position;
    }


}
void CgameObject::setPosition(float x, float y) {
    this->position.Set(x, y);
}


}
}
