#include "Craziel.h"

Craziel::Craziel() {
	this->inAir = false;
	this->jumpForce = 0.01;
	this->setTextureMap(0); /**< Bu kısmın level dosyasından alınması gerekiyor */
	this->setFrameSize(64, 64);
	this->setFPS(5);
	this->setSize(128, 128);
	this->addCircleCollider(0, 0, 10);
	this->addCollideGroup(FLOOR);
	this->setGroup(PLAYER);
	this->fc = 0;

	this->force.SetZero();
	this->velocity.SetZero();
	this->hasGravity = true;
	this->setPosition(0, 0);
	this->playAndLoop(0, 16);
	this->speed = 5;
	this->inAirSpeed = 2;

}

Craziel::~Craziel() {
	//dtor
}
void  Craziel::collide(int id, int type) {


	if(type == FLOOR) {

		this->velocity.y = 0 ;
		this->hasGravity = false;

		//if object was in air,
		if(this->inAir) {
			this->playAndLoop(0, 16);
		}

		this->inAir = false;
	}

	//this->lastCollidedWith = id;
}
void Craziel::cycle(void) {
	if(keys[VK_SPACE]) {
		if(!this->inAir)
			this->jump();

	}

	if(keys[VK_RIGHT] || keys[VK_LEFT]) {
		this->run();
	}
}
void Craziel::jump() {
	engine::geometrics::Cvector gravity;
	this->velocity.y = 10;
	this->hasGravity = true;
	this->playAndStop(16, 32);
	this->setFPS(3);
	this->inAir = true;

}
void Craziel::run() {
	if(keys[VK_RIGHT]) {

		this->velocity.x = (this->speed);

	}

	if(keys[VK_LEFT]) {

		this->velocity.x = -(this->speed);

	}

}
