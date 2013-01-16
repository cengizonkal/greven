#ifndef CCOLLISION_H
#define CCOLLISION_H
#include "../level/Clevel.h"
#include "../controller/Craziel.h"
#include "../time/Ctime.h"
#include "../tools.h"

class Ccollision
{
    private:
    public:
        Ccollision();
        ~Ccollision();
        Clevel *level;
        Craziel *player;
        Ctime *iTime;
        double lastTime;
        float stepTime;
        void init();
        void registerLevel(Clevel *level);
        void registerPlayer(Craziel *player);
        void linkTime(Ctime *time);
        void step();
        bool circleGround(Ccore c,Cground g);

};

#endif // CCOLLISION_H
