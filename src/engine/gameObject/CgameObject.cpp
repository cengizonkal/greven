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
	this->collideWith = NULL;
	this->type = 0;
	this->groupId = 0;
	this->id = engine::state::Cstate::getId(); /**< Her objenin eşsiz bir id olacak  */
	this->isInScreen = true;
	this->collisionType = CIRCLE;
	this->lines = NULL;
	this->circles = NULL;
}
void CgameObject::addCollideGroup(int groupId) {
	NoG++;
	collideWith = (int*) realloc(collideWith, sizeof(int) * NoG);
	collideWith[NoG - 1] = groupId;
}
void CgameObject::addCircle(engine::geometrics::Ccircle circle) {
	this->NoC++;
	this->circles = (engine::geometrics::Ccircle*) realloc(circles, sizeof(engine::geometrics::Ccircle) * this->NoC);
	this->circles[this->NoC - 1] = circle;
}
void CgameObject::addLine(engine::geometrics::Cline line) {
	this->NoL++;
	this->lines = (engine::geometrics::Cline*) realloc(lines, sizeof(engine::geometrics::Cline) * this->NoL);
	this->lines[this->NoL - 1] = line;
}

// TODO (Cengiz#1#): game objesi için yardımcı fonksiyonlar yazılacak ...
//setter getter
void CgameObject::addCircle(float x, float y, float r) {

}
void CgameObject::addLine(float x, float y, float w, float h) {

}
void CgameObject::setID(int ID) {
	this->id = ID;
}
int CgameObject::getID(void) {
	return this->id;
}


}
}
