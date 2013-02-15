#include "Craziel.h"

Craziel::Craziel()
{



}

Craziel::~Craziel()
{
    //dtor
}
void  Craziel::collide(int id, int type) {
    trace("\nplayer recived collide %d %d",id,type);
    trace("\nPlayer id:%d", this->id);
}
void Craziel::cycle(void) {
    //update işlemleri
    //movement
    //check s
}
