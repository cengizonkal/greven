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

class Ccollision {
private:
public:
	Ccollision();
	~Ccollision();
	CgameObject **gameObjects; /**< Sadece oyun objelerini kaydet */
	int NoO; /**< Obje sayısı */

    Ctime *iTime; /**< Genel zamana bağla */
	double lastTime;
	float stepTime; /**< Çalışma frekansı */
	void init();

	void registerGameObject(CgameObject *obj);
	void linkTime(Ctime *time);
	void step();
	bool circleLine(Ccircle c, Cline l);
	bool circleCircle(Ccircle c1, Ccircle c2);
	void testSignal(void);

};

#endif // CCOLLISION_H
