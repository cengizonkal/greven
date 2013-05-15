#include "Cline.h"
namespace engine { namespace collision{
Cline::Cline(void) {
	this->init();
}
void Cline::init(void) {

    this->relativePosition.SetZero();
    this->position.SetZero();
    this->w = 0;
    this->h = 0;

}

Cline::~Cline(void) {
}
}
}

