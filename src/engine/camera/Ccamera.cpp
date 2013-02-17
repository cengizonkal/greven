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
	this->speed.SetZero();
}
void Ccamera::setLink(CgameObject *gj) {
	this->gameObject = gj; /**< Bir obejeye bağla */
	this->mode = CAM_FOLLOW; /**< Camera modunu değiştir */

}
Cvector  Ccamera::getPosition(double deltaTime) {
    //delta time * speed * target

    speed.SetZero();
    if(this->mode == CAM_FREE) {
        if(keys['W']) {
            speed.y=-10;
        }
        if(keys['A']) {
            speed.x=10;
        }
        if(keys['S']) {
            speed.y=10;
        }
        if(keys['D']) {
            speed.x=-10;
        }
        if(keys['D'] || keys['S'] ||keys['W']||keys['A']) {
            speed.Normalize();
            speed*=10;
            this->position.x+= speed.x*METERTOPIXEL*deltaTime;
            this->position.y+= speed.y*METERTOPIXEL*deltaTime;
        }

    }
    return this->position;
}
