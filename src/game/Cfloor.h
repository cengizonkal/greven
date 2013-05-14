#ifndef CFLOOR_H
#define CFLOOR_H
#include "../engine/gameObject/CgameObject.h"
#include "../engine/geometrics/Cvector.h"

class Cfloor : public engine::gameobject::CgameObject {
public:
	Cfloor();
	virtual ~Cfloor();
	void collide(int id, int type);
	void cycle(void);
protected:
private:
};

#endif // CfloorS_H
