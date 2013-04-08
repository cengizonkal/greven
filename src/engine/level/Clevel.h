#ifndef _CLEVEL_H
#define _CLEVEL_H
#include "../ground/Cground.h"


class Clevel
{
    public:
    Clevel();
    ~Clevel();
    //level objects
    //like walls grounds, enemies, bonuses ect


    int NoW;
    int currentLevel;

    Cground *grounds;
    int NoG;

    void loadLevel();

    void addGround(Cground ground);
    void init(void);



};
#endif
