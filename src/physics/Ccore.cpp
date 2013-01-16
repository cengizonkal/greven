
#include "Ccore.h"


Ccore::Ccore(void )
{
    init();

}
void Ccore::init(void )
{

    this->position.SetZero();
    this->velocity.SetZero();
    this->force.SetZero();
    this->mass=1;
    this->id=-1;
    this->movable=true;
    this->hasGravity=true;
    this->radius=64; //pixel


}
void Ccore::addForce(Cvector force)
{
    this->force+=force;
}
void Ccore::setRadius(float r)
{
    this->radius=r;
}


