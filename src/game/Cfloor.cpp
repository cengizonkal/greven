#include "Cfloor.h"

Cfloor::Cfloor()
{
    this->movable = false;
    this->addLine(-1024, 0, 1024, 0);
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
