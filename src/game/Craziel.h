#ifndef Craziel_H
#define Craziel_H

#include "../engine/gameObject/CgameObject.h"
#include "../tools.h"



class Craziel : public engine::gameobject::CgameObject
{
    public:
    Craziel();
    ~Craziel();
    void collide(int id, int type);
    void cycle(void);


};

#endif // Craziel_H
