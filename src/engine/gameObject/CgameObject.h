#ifndef CGAMEOBJECT_H
#define CGAMEOBJECT_H
#include "../collision/Cline.h"
#include "../collision/Ccircle.h"
#include "../state/Cstate.h"
#include "../graphics/Canimation.h"
#include "../../def.h"

/** \brief Oyun objesi
 * Oyunda kullanılacak olan tüm sınıflar bu sınıftan türemelidir.
 *
 *
 */
namespace engine { namespace gameobject {
class CgameObject : public engine::graphics::Canimation {
public:
	CgameObject();
	~CgameObject();
	int id;/**< Çarpışma sonrasında bu bilgi diğer objeye gönderilecek */
	int type; /**< Bu obje çizgi mi, Daire mi : 1, 0 */
	int collisionType; /**<Çarpışma testinde çizgi 1, daire 2  */
	int groupId; /**< Bu obje hangi gruba ait, böylece birbirinden farklı gruplar arasında çarpışma tesi yapılabilir */
    bool hasCollision;
	engine::collision::Cline *lines;/**<Çizgi Çarpıştırıcı */
	engine::collision::Ccircle *circles;/**< ´Daire Çarpıştırıcı */
	int *collideWith;/**< Hangi grouplar ile çarpışma testi yapılması gerektiğini belirler */
    int NoG; /**< Kaç grup ile çarpışma testi yapılacak  */
    int NoC; /**< Daire Sayısı */
    int NoL; /**< Çizgi Sayısı */
    int lastCollidedWith; /**< en son hangi obje ile çarpıştığını saklayan değişken.
    Bu değişken sayesinde çarpışma işlemi sadece bir sefer gerçekleştirilebilir
    -1 ise hiçbişey ile çarpışmadığı anlamına gelir */


    bool isInScreen; /**< Ekranda olup olmadığını gösterecek böylece performas artışı sağlanabilir */

    /** \brief çarpışma sonrasında child sınıfına collide methodunu çağırmasını söyleyecek
     *
     * \param void
     * \param id, type
     * \return void
     *
     */
    virtual void collide(int id, int type) = 0;

    /** \brief Sürekli olarak çalışmasını istediğin kodu buraya yaz
     *Bu fonksiyon greven tarafından her döngü sonrasında çağrılacak.
     *tüm kayıtlı objeler için elbette
     * \param void
     * \return void
     *
     */
    virtual void cycle(void) = 0;

	void addCollideGroup(int groupId);
	void removeCollideGroup(int groupId);
	void setGroup(int groupId);
	void setID(int ID);
	int getID(void);
	void addLineCollider(float x1, float y1, float x2, float y2);
	void addLineCollider(engine::collision::Cline line);
	void addCircleCollider(float x, float y, float r);
	void addCircleCollider(engine::collision::Ccircle circle);
	void init(void);
	void moveColliders(void);
	void setPosition(float x, float y);

protected:
private:
};
}
}
#endif
