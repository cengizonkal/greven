#include "Cground.h"

Cground::Cground()
{
 init();    //ctor
}

Cground::~Cground()
{
    //dtor
}
void Cground::init(void)
{
    this->pointA.x=0;
    this->pointA.y=0;
    this->pointB.x=0;
    this->pointB.y=0;

}
void Cground::setGround(Cpoint a,Cpoint b)
{
    this->pointA=a;
    this->pointB=b;
};

void Cground::setGround(float ax,float ay,float bx,float by)
{
    this->pointA.x=ax;
    this->pointA.y=ay;
    this->pointB.x=bx;
    this->pointB.y=by;

};
