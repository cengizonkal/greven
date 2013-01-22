
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
    this->movable=true;
    this->hasGravity=true;


}
void Ccore::addForce(Cvector force)
{
    this->force+=force;
}



