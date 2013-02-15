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
    this->NoC = 0;
    this->collideWith = NULL;
    this->type = 0;
    this->groupId = 0;
    this->id = Cstate::getId(); /**< Her objenin eşsiz bir id olacak  */
    this->isInScreen = true;
}
void CgameObject::addCollideGroup(int groupId) {
    NoC++;
    collideWith = (int*) malloc(sizeof(int)*NoC);
    collideWith[NoC-1] = groupId;
}
void CgameObject::setCircle(Ccircle circle) {
    this->circle = circle;
}
void CgameObject::setLine(Cline line) {
    this->line = line;
}
void CgameObject::setCircle(float x, float y, float r) {
    this->circle.x = x;
    this->circle.y = y;
    this->circle.r = r;
}
void CgameObject::setLine(float x, float y, float w, float h) {
    this->line.x = x;
    this->line.y = y;
    this->line.h = h;
    this->line.w = w;
}
void CgameObject::setID(int ID) {
    this->id = ID;
}
int CgameObject::getID(void) {
    return this->id;
}


