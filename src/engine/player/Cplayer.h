#ifndef Cplayer_H
#define Cplayer_H

#include "../../def.h"
#include "../../tools.h"
#include "../time/Ctime.h"
#include "../gameObject/CgameObject.h"

class Cplayer : public CgameObject
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
        Ctime *iTime;/**< Genel zaman sınıfına bağlamak için gereken pointer */
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
