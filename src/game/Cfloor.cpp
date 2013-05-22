#include "Cfloor.h"

Cfloor::Cfloor()
{
    this->movable = false;

    this->addLineCollider(-100, 0, 100, 0);
    this->setPosition(0, -10);
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
