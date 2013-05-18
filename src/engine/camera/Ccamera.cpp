#include "Ccamera.h"
namespace engine{ namespace camera {
Ccamera::Ccamera(void ) {
	init();

}
Ccamera::~Ccamera(void ) {


}
void Ccamera::init(void) {
	this->position.Set(0, 0);
	this->zoom = 1;
	this->mode = CAM_FREE; /**< Kamera öncelik olarak serbest halde */
	this->seekTime = 0.5; //bir saniye içinde hedefe git
	this->deadZone = 5; //5 pxelden küçükse hareket etme
	this->gameObject = NULL;
	this->speed.SetZero();
	this->speedA=20;
}
void Ccamera::setLink(engine::gameobject::CgameObject *gj) {
	this->gameObject = gj; /**< Bir obejeye bağla */
	this->mode = CAM_FOLLOW; /**< Camera modunu değiştir */

}
engine::geometrics::Cvector  Ccamera::getPosition(double deltaTime) {
    //delta time * speed * target

    speed.SetZero();
    if(this->mode == CAM_FREE) {
        if(keys[38]) {
            speed.y=speedA*-1;
        }
        if(keys[37]) {
            speed.x=speedA;
        }
        if(keys[40]) {
            speed.y=speedA;
        }
        if(keys[39]) {
            speed.x=speedA*-1;
        }
        if(keys[37] || keys[38] ||keys[39]||keys[40]) {
            speed.Normalize();
            speed*=speedA;
            this->position.x+= speed.x*METERTOPIXEL*deltaTime;
            this->position.y+= speed.y*METERTOPIXEL*deltaTime;
        }

    }
    else if(this->mode == CAM_MOUSE) {
        {
            this->position.x = mouseX*-1;
            this->position.y = mouseY*-1;
        }


    }
    else if(this->mode == CAM_FIXED) {
        return this->position;
    }
    return this->position;
}
void Ccamera::setPosition(float x, float y){
    this->position.Set(x, y);
}
}
}
