#include "Cphysics.h"
#include "../../def.h"
Cphysics::Cphysics()
{
    init();
};

Cphysics::~Cphysics()
{
    iTime=NULL;
    free(iTime);
};



void Cphysics::registerSprite(Csprite * s)
{
    NoC++;
    cores=(Ccore**)realloc(cores,NoC*(sizeof(Ccore*)));
    cores[NoC-1]=&(s->core);
    s->core.id=NoC;
    if(s->core.hasGravity)
    {
        cores[NoC-1]->addForce(gravity);
    }

};

void Cphysics::linkTime(Ctime * t)
{
    iTime=t;
    lastTime=iTime->getCurrTime();
};

void Cphysics::step()
{
    double deltaTime=0;
    deltaTime=iTime->getCurrTime()-lastTime;
    for(int i=0;i<NoC;i++)
    {

        Cvector distance;
        Cvector deltaVelocity;
        deltaVelocity.SetZero();
        distance.SetZero();

        cores[i]->velocity+=deltaTime*cores[i]->force;
        distance=deltaTime*cores[i]->velocity;
        distance*=METERTOPIXEL;
        cores[i]->position+=distance;
        //velocity faints
        if(abs(cores[i]->velocity.x)<0.5)
        {
            cores[i]->velocity.x=0;
        }
        cores[i]->velocity.x-=cores[i]->velocity.x*deltaTime/freeMove;

    }
    lastTime=iTime->getCurrTime();

};
void Cphysics::init()
{
    cores=(Ccore**)malloc(1*(sizeof(Ccore*)));
    NoC=0;
    gravity.Set(0,-10);
    freeMove=0.2;
};



