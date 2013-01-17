#include "Cplayer.h"

Cplayer::Cplayer()
{
    this->setState(P1_STOP);
    this->inAir=false;
    iTime=NULL;
    lastTime=0;
    maxSpeed=5;
    acc=1;/**< bir saniye içinde max hıza ulaş */
    jumpForce=7;
    isPlaying=false;
    doubleJump=1;


}

Cplayer::~Cplayer()
{
    //dtor
}

void Cplayer::setState(short state)
{


}

void Cplayer::moveLeft()
{
    float deltaTime;
    startAccTime();
    deltaTime=iTime->getCurrTime()-lastTime;
    this->core.velocity.x=maxSpeed*(deltaTime/acc)*-1;
    if(abs(this->core.velocity.x)>abs(this->maxSpeed))
    {
        this->core.velocity.x=(this->maxSpeed)*-1;
    }
    this->isPlaying=true;
    this->invert=0;

}
void Cplayer::moveRight()
{
    float deltaTime;
    startAccTime();
    deltaTime=iTime->getCurrTime()-lastTime;
    this->core.velocity.x=maxSpeed*(deltaTime/acc);
    if(abs(this->core.velocity.x)>abs(this->maxSpeed))
    {
        this->core.velocity.x=this->maxSpeed;
    }
    this->isPlaying=true;
    this->invert=1;
}

void Cplayer::jump()
{

    if(this->doubleJump>0)
    {

        Cvector gravity;
        Cvector velocity;
        velocity.Set(0,jumpForce);
        gravity.Set(0,GRAVITY);

        this->core.velocity+=velocity;
        this->core.addForce(gravity);
        this->inAir=true;
        this->setFPS(2);
        this->doubleJump--;
    }
}
void Cplayer::linkTime(Ctime *time)
{
    this->iTime=time;
}
void Cplayer::startAccTime()
{
    if(!this->timerStarted)
    {
        this->timerStarted=true;
        lastTime=iTime->getCurrTime();
    }
}
void Cplayer::resetAccTime()
{
    if(this->timerStarted)
    {
        this->timerStarted=false;
        lastTime=iTime->getCurrTime();
    }
}
void Cplayer::playerInAir()
{
    this->inAir=true;
    this->setFPS(2);
}
void Cplayer::playerOnGround()
{
    this->doubleJump=1;
    this->inAir=false;
    this->setFPS(15);
}