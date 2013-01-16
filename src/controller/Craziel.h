#ifndef Craziel_H
#define Craziel_H

#include "../graphics/Csprite.h"

#include "../def.h"
#include "../tools.h"
#include "../time/Ctime.h"


class Craziel : public Csprite
{
    public:
        int id;
        Craziel();
        float lastTime;
        virtual ~Craziel();
        bool inAir;
        bool timerStarted;
        short doubleJump;
        float maxSpeed;
        float jumpForce;
        float acc; //time to gain full speed, 1 second
        Ctime *iTime;
        void setState(short state);
        void moveLeft(void);
        void moveRight(void);
        void jump(void);
        void linkTime(Ctime *time);
        void startAccTime();
        void resetAccTime();
        void playerInAir();
        void playerOnGround();


    protected:
    private:



};

#endif // Craziel_H
