#include "Craziel.h"

Craziel::Craziel()
{
    this->inAir = false;
    this->jumpForce = 1;

}

Craziel::~Craziel()
{
    //dtor
}
void  Craziel::collide(int id, int type) {
    trace("\nplayer recived collide %d %d",id,type);
    trace("\nPlayer id:%d", this->id);
}
void Craziel::cycle(void) {
 if(keys[VK_SPACE]){
    this->jump();
 }
}
void Craziel::jump()
{
    engine::geometrics::Cvector gravity;
    engine::geometrics::Cvector velocity;
    velocity.Set(0, jumpForce);
    gravity.Set(0, GRAVITY);
    this->velocity+=velocity;
    this->addForce(gravity);
    this->inAir=true;
    this->setFPS(2);
    //trace("jump");

}
