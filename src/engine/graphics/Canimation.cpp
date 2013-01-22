
#include "Canimation.h"

Canimation::Canimation(void ) {
	init();
}
Canimation::~Canimation(void ) {

}
void Canimation::setFrameSize(float w, float h) {

	this->fh = h;
	this->fw = w;
	/**< Eğer boyut belirlenmedi ise frame boyutu ile resim boyutu aynı  */
	if(this->h == 0) this->h = h;
	if(this->w == 0) this->w = w;

}
void Canimation::setActive()
{
    this->isPlaying=true;
}
void Canimation::setPassive()
{
    this->isPlaying=false;
}
void Canimation::setFPS(int fps)
{
    this->fps=fps;
}
void Canimation::setTextureMap(int textureId)
{
    this->textId=textureId;
}
void Canimation::limitFrames(int from,int to)
{
    this->fromFrame=from;
    this->toFrame=to;
}
Cvector Canimation::getPosition()
{
    return this->position;
}

void Canimation::init() {
	textId = 0;
	fps = 25;
	w = 0;
	h = 0;
	fh = 0;
	fw = 0;
	fc = 0;
	isPlaying = true;
	invert = 0;
	fromFrame = 0;
	toFrame = 0;
	debug = true;

}

