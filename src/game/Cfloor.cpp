#include "Cfloor.h"

Cfloor::Cfloor()
{
    this->movable = false;


    this->setPosition(0, -3);
    this->addLineCollider(-100, .32, 100, .32);

    this->setGroup(FLOOR);

    this->setTextureMap(0); /**< Bu kısmın level dosyasından alınması gerekiyor */
    this->setFrameSize(1024, 64);
	this->setSize(1024,64);
	this->setFPS(0);

	this->setActiveFrame(0);

}

Cfloor::~Cfloor()
{
    //dtor
}

void Cfloor::cycle(void) {

}

void Cfloor::collide(int id, int type){

}
