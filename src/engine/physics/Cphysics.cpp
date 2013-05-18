#include "Cphysics.h"
#include "../../def.h"
namespace engine { namespace physics{
Cphysics::Cphysics()
{
    init();
};

Cphysics::~Cphysics()
{
    iTime=NULL;
    free(iTime);
};



void Cphysics::registerGameObject(Ccore *c)
{
    NoC++;
    cores=(Ccore**)realloc(cores,NoC*(sizeof(Ccore*)));
    cores[NoC-1]=c;


};

void Cphysics::linkTime(engine::time::Ctime * t)
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
        if(cores[i]->movable) {
            engine::geometrics::Cvector distance;
            engine::geometrics::Cvector deltaVelocity;
            deltaVelocity.SetZero();
            distance.SetZero();

            cores[i]->velocity.x+=(deltaTime*cores[i]->force.x);
            cores[i]->velocity.y+=(deltaTime*cores[i]->force.y);
            if(cores[i]->hasGravity) {
                cores[i]->velocity+=(deltaTime*gravity);
            }


            distance=deltaTime*cores[i]->velocity;
            distance*=METERTOPIXEL;
            cores[i]->position+=distance;
            //yatay hız 0.5 altında ise sıfır olarak kabul et
            if(abs(cores[i]->velocity.x)<0.5)
            {
                cores[i]->velocity.x=0;
            }
            //yatay hız azalır freemove oranında azalır
            cores[i]->velocity.x-=cores[i]->velocity.x*deltaTime/freeMove;
        }


    }
    lastTime=iTime->getCurrTime();

};
void Cphysics::init()
{
    cores=(engine::physics::Ccore**)malloc(1*(sizeof(Ccore*)));
    NoC=0;
    gravity.Set(0,-10);
    freeMove=0.2;
};
}
}


