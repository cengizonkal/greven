#ifndef Craziel_H
#define Craziel_H

#include "../engine/gameObject/CgameObject.h"
#include "../tools.h"



class Craziel : public CgameObject
{
    public:
    Craziel();
    ~Craziel();
    void collide(int id, int type);
    void cycle(void);


};

#endif // Craziel_H
