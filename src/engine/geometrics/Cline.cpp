#include "Cline.h"
namespace engine { namespace geometrics{
Cline::Cline(void) {
	this->init();
}
void Cline::init(void) {
	this->x1 = 0;
	this->y1 = 0;
	this->x2 = 0;
	this->y2 = 0;
}

Cline::~Cline(void) {
}
}
}

