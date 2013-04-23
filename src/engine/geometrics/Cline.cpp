#include "Cline.h"
namespace engine { namespace geometrics{
Cline::Cline(void) {
	this->init();
}
void Cline::init(void) {
	this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;
}

Cline::~Cline(void) {
}
}
}

