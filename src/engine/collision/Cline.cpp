#include "Cline.h"
namespace engine { namespace collision{
Cline::Cline(void) {
	this->init();
}
void Cline::init(void) {

    this->relativePoint1.SetZero();
    this->relativePoint2.SetZero();
    this->point1.SetZero();
    this->point2.SetZero();


}

Cline::~Cline(void) {
}
}
}

