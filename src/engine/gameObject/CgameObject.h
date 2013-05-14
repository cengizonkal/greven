#ifndef CGAMEOBJECT_H
#define CGAMEOBJECT_H
#include "../geometrics/Cline.h"
#include "../geometrics/Ccircle.h"
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

	engine::geometrics::Cline *lines;/**<Çizgi Bilgisi */
	engine::geometrics::Ccircle *circles;/**< ´Daire bilgisi */
	int *collideWith;/**< Hangi grouplar ile çarpışma testi yapılması gerektiğini belirler */
    int NoG; /**< Kaç grup ile çarpışma testi yapılacak  */
    int NoC; /**< Daire Sayısı */
    int NoL; /**< Çizgi Sayısı */

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
	void setGroup(int groupId);
	void setID(int ID);
	int getID(void);
	void addLine(float x, float y, float h, float w);
	void addLine(engine::geometrics::Cline line);
	void addCircle(float x, float y, float r);
	void addCircle(engine::geometrics::Ccircle circle);
	void init(void);

protected:
private:
};
}
}
#endif
