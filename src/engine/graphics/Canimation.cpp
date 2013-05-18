
#include "Canimation.h"
namespace engine { namespace graphics{
Canimation::Canimation(void ) {
	init();
}
Canimation::~Canimation(void ) {

}
/** \brief Yüklenen resim üzerindeki boyutu belirler
 *
 * \param int weight
 * \param int height
 * \return void
 */
void Canimation::setFrameSize(float w, float h) {

	this->fh = h;
	this->fw = w;
	/**< Eğer boyut belirlenmedi ise frame boyutu ile resim boyutu aynı  */
	if(this->h == 0) this->h = h;
	if(this->w == 0) this->w = w;

}

/** \brief Ekran üzerindeki Boyutu belirler
 *
 * \param int weight
 * \param int height
 * \return
 *
 */
void Canimation::setSize(float w, float h) {

	this->h = h;
	this->w = w;

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
engine::geometrics::Cvector Canimation::getPosition()
{
    return this->position;
}

void Canimation::init() {
	this->textId = 0;
	this->fps = 25;
	this->w = 0;
	this->h = 0;
	this->fh = 0;
	this->fw = 0;
	this->fc = 0;
	this->isPlaying = true;
	this->invert = 0;
	this->fromFrame = 0;
	this->toFrame = 0;
	this->debug = false;
	this->loop = -1; /**< sonsuza kadar dön */

}

void Canimation::setActiveFrame(int frame) {
    this->fc = frame;
}
void Canimation::playAndStop(void) {
    this->setActiveFrame(this->fromFrame);
    this->loop = 1;
}

void Canimation::playAndStop(int from, int to) {
    this->setActiveFrame(from);
    this->setFrames(from, to);
    this->loop = 1;
}

void Canimation::playAndLoop(void) {
    this->setActiveFrame(this->fromFrame);
    this->loop = -1;
}

void Canimation::playAndLoop(int from, int to) {
    this->setActiveFrame(from);
    this->setFrames(from, to);
    this->loop = -1;
}

void Canimation::setFrames(int from, int to) {
    this->fromFrame = from;
    this->toFrame = to;
}


}}
