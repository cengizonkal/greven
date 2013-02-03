#include "Ccamera.h"

Ccamera::Ccamera(void ) {
	init();

}
Ccamera::~Ccamera(void ) {


}
void Ccamera::init(void) {
	this->position.Set(0, 0);
	this->zoom = 1;
	this->mode = CAM_FREE; /**< Kamera öncelik olarak serbest halde */
	this->seekTime = 0.5; //bir saniye içinde
	this->deadZone = 5; //5 pxelden küçükse hareket etme
	this->gameObject = NULL;
}
void Ccamera::setLink(CgameObject *gj) {
	this->gameObject = gj; /**< Bir obejeye bağla */
	this->mode = CAM_FOLLOW; /**< Camera modunu değiştir */

}
Cvector  Ccamera::getPosition() {

	return this->position;

}
