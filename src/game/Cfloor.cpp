#include "Cfloor.h"

Cfloor::Cfloor()
{
    this->movable = false;

    this->addLineCollider(-1024, 0, 1024, 0);
    this->setPosition(0, -100);
    this->setGroup(FLOOR);
}

Cfloor::~Cfloor()
{
    //dtor
}

void Cfloor::cycle(void) {

}

void Cfloor::collide(int id, int type){

}
