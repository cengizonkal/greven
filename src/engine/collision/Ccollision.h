#ifndef CCOLLISION_H
#define CCOLLISION_H
#include "../time/Ctime.h"
#include "../geometrics/Ccircle.h"
#include "../geometrics/Cline.h"
#include "../../tools.h"
#include "../../def.h"
#include "../gameObject/CgameObject.h"

/** \brief Çarpışma testi sınıfı
 *
 */
namespace engine {
namespace collision {
class Ccollision {
private:
public:
	Ccollision();
	~Ccollision();
	engine::gameobject::CgameObject **gameObjects; /**< Sadece oyun objelerini kaydet */
	int NoO; /**< Obje sayısı */

	engine::time::Ctime *iTime; /**< Genel zamana bağla */
	double lastTime;
	float stepTime; /**< Çalışma frekansı */
	void init();

	void registerGameObject(engine::gameobject::CgameObject *obj);
	void linkTime(engine::time::Ctime *time);
	void step();
	bool circleLine(engine::geometrics::Ccircle *c, engine::geometrics::Cline *l);
	bool circleCircle(engine::geometrics::Ccircle *c1, engine::geometrics::Ccircle *c2);
	// TODO (Cengiz#1#): Line-line çarpışma testi
	bool lineLine(engine::geometrics::Cline *l1, engine::geometrics::Cline *l2);
	void testSignal(void);
	bool objectObject(engine::gameobject::CgameObject *g1, engine::gameobject::CgameObject *g2);

};
}
}
#endif // CCOLLISION_H
