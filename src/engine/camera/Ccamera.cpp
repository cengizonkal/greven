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
	this->speedA=20;
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
            speed.y=speedA*-1;
        }
        if(keys['A']) {
            speed.x=speedA;
        }
        if(keys['S']) {
            speed.y=speedA;
        }
        if(keys['D']) {
            speed.x=speedA*-1;
        }
        if(keys['D'] || keys['S'] ||keys['W']||keys['A']) {
            speed.Normalize();
            speed*=speedA;
            this->position.x+= speed.x*METERTOPIXEL*deltaTime;
            this->position.y+= speed.y*METERTOPIXEL*deltaTime;
        }

    }
    else if(this->mode == CAM_MOUSE) {
        this->position.x = mouseX*-1;
        this->position.y = mouseY*-1;

    }
    return this->position;
}
