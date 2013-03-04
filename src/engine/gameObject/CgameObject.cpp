#include "CgameObject.h"

CgameObject::CgameObject()
{
    this->init();    //ctor
}

CgameObject::~CgameObject()
{
    //dtor
}
void CgameObject::init(void) {
    this->NoG = 0;
    this->collideWith = NULL;
    this->type = 0;
    this->groupId = 0;
    this->id = Cstate::getId(); /**< Her objenin eşsiz bir id olacak  */
    this->isInScreen = true;
    this->collisionType = CIRCLE;
    this->lines = NULL;
    this->circles = NULL;
}
void CgameObject::addCollideGroup(int groupId) {
    NoG++;
    collideWith = (int*) realloc(collideWith, sizeof(int)*NoG);
    collideWith[NoG-1] = groupId;
}
void CgameObject::addCircle(Ccircle circle) {
    this->NoC++;
    this->circles =(Ccircle*) realloc(circles, sizeof(Ccircle)*this->NoC);
    this->circles[this->NoC-1] = circle;
}
void CgameObject::addLine(Cline line) {
    this->NoL++;
    this->lines =(Cline*) realloc(lines, sizeof(Cline)*this->NoL);
    this->lines[this->NoL-1] = line;
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


