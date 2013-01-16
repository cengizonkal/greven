#ifndef _CLEVEL_H
#define _CLEVEL_H
#include "../ground/Cground.h"
#include "../wall/Cwall.h"

class Clevel
{
    public:
    Clevel();
    ~Clevel();
    //level objects
    //like walls grounds, enemies, bonuses ect

    Cwall *walls;
    int NoW;
    int currentLevel;

    Cground *grounds;
    int NoG;

    void loadLevel();
    void addWall(Cwall wall);
    void addGround(Cground ground);
    void init(void);



};
#endif
