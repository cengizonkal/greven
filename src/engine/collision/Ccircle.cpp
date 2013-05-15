
#include "Ccircle.h"
namespace engine { namespace collision{

Ccircle::Ccircle(void )
{
 init();
}

Ccircle::~Ccircle(void ){

}

void Ccircle::init(void )
{
    this->relativePosition.SetZero();
    this->position.SetZero();
    this->r = 0;
}

}
}
