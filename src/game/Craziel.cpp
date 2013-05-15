#include "Craziel.h"

Craziel::Craziel()
{
    this->inAir = false;
    this->jumpForce = 0.01;
    this->setTextureMap(0); /**< Bu kısmın level dosyasından alınması gerekiyor */
    this->setFrameSize(64,64);
    this->setFPS(15);
    this->setSize(128,128);
    this->addCircle(0, 0, 128);
    this->addCollideGroup(FLOOR);
    this->setGroup(PLAYER);
    this->fc = 0;

    this->force.SetZero();
    this->velocity.SetZero();
    this->hasGravity = true;

}

Craziel::~Craziel()
{
    //dtor
}
void  Craziel::collide(int id, int type) {


    if(type == FLOOR) {
        trace("on the floor\n");
        this->velocity.y = 0 ;
        this->hasGravity = false;
    }
}
void Craziel::cycle(void) {
 if(keys[VK_SPACE]){
    this->jump();
    trace("in the air\n");
 }
}
void Craziel::jump()
{
    engine::geometrics::Cvector gravity;
    engine::geometrics::Cvector velocity;
    velocity.Set(0, 1);
    this->velocity=velocity;
    this->hasGravity = true;
    this->toFrame = 32;
    this->fromFrame = 16;

}
