#ifndef Craziel_H
#define Craziel_H

#include "../engine/gameObject/CgameObject.h"
#include "../tools.h"
#include "../engine/geometrics/Cvector.h"
#include "../engine/globals/globals.h"
#include <windows.h>



class Craziel : public engine::gameobject::CgameObject
{
    public:
    Craziel();
    ~Craziel();
    float jumpForce;
    bool inAir;
    void collide(int id, int type);
    void cycle(void);
    void jump();


};

#endif // Craziel_H
