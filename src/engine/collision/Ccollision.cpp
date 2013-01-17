#include "Ccollision.h"

Ccollision::Ccollision()
{
    init();
}


Ccollision::~Ccollision()
{
    //dtor
}

void Ccollision::init()
{
    this->level=NULL;
    this->player=NULL;
    lastTime=0;
    stepTime=0.0001; //1 second
}

void Ccollision::registerLevel(Clevel *level)
{
    this->level=level;
}
void Ccollision::registerPlayer(Cplayer *player)
{
    this->player=player;
}
void Ccollision::linkTime(Ctime *time)
{
    this->iTime=time;
}
void Ccollision::step(void)
{
    double deltaTime=0;
    deltaTime=iTime->getCurrTime()-lastTime;
    if(deltaTime>stepTime)
    {
        //check if player collides with grounds and walls
        for(int i=0;i<this->level->NoG;i++)
        {
            if(circleGround(player->core,level->grounds[i]))
            {
                //trace("\n%s","collide");
                player->core.force.y=0;
                player->core.velocity.y=0;
                player->playerOnGround();

                break;

            }
            else
            {

                player->core.force.y=(GRAVITY);
                player->playerInAir();


            }

        }
        lastTime=iTime->getCurrTime();
    }

}

bool Ccollision::circleGround(Ccore c,Cground g)
{
    float x1;
    float x2;
    float y;


    if(g.pointA.x>g.pointB.x)
    {
        x1=g.pointA.x;
        x2=g.pointB.x;

    }
    else
    {
        x1=g.pointB.x;
        x2=g.pointA.x;

    }
    //y all the same
    y=g.pointA.y;

    if(((c.position.x+c.radius)>x2) && ((c.position.x-c.radius)<x1) && ((c.position.y-c.radius)<=y &&(c.position.y+c.radius)>y))
    {
        return true;
    }
    else
        return false;




}


