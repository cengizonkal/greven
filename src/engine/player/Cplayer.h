#ifndef Cplayer_H
#define Cplayer_H

#include "../graphics/Csprite.h"

#include "../../def.h"
#include "../../tools.h"
#include "../time/Ctime.h"


class Cplayer : public Csprite
{
    public:
        int id;
        Cplayer();
        float lastTime;
        virtual ~Cplayer();
        bool inAir;
        bool timerStarted;
        short doubleJump;
        float maxSpeed;/**< Max hız */
        float jumpForce;/**< Zıplama kuvveti */
        float acc;/**< bu saniye süresince tam hızına ulaş */
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

#endif // Cplayer_H
