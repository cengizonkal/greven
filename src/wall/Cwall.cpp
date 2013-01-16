#include "Cwall.h"
#include "../geometrics/Cpoint.h"

Cwall::Cwall()
{
 init();    //ctor
}

Cwall::~Cwall()
{
    //dtor
}
void Cwall::init(void)
{
    this->pointA.x=0;
    this->pointA.y=0;
    this->pointB.x=0;
    this->pointB.y=0;

}
void Cwall::setWall(Cpoint a,Cpoint b)
{
    this->pointA=a;
    this->pointB=b;
};

void Cwall::setWall(float ax,float ay,float bx,float by)
{
    this->pointA.x=ax;
    this->pointA.y=ay;
    this->pointB.x=bx;
    this->pointB.y=by;

};

