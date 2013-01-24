#ifndef CGAMEOBJECT_H
#define CGAMEOBJECT_H
#include "../geometrics/Cline.h"
#include "../geometrics/Ccircle.h"
#include "../state/Cstate.h"
#include "../graphics/Canimation.h"

/** \brief Oyun objesi
 * Oyunda kullanılacak olan tüm sınıflar bu sınıftan türemelidir.
 *
 *
 */

class CgameObject : public Canimation {
public:
	CgameObject();
	~CgameObject();
	int id;/**< Çarpışma sonrasında bu bilgi diğer objeye gönderilecek */
	int type; /**< Bu obje çizgi mi, Daire mi : 1, 0 */
	int groupId; /**< Bu obje hangi gruba ait, böylece birbirinden farklı gruplar arasında çarpışma tesi yapılabilir */

	Cline line;/**<Çizgi Bilgisi */
	Ccircle circle;/**< ´Daire bilgisi */
	int *collideWith;/**< Hangi grouplar ile çarpışma testi yapılması gerektiğini belirler */
    int NoC; /**< Kaç grup ile çarpışma testi yapılacak  */

    /** \brief çarpışma sonrasında child sınıfına collide methodunu çağırmasını söyleyecek
     *
     * \param void
     * \param id, type
     * \return void
     *
     */

    virtual void collide(int id, int type) = 0;
	void addCollideGroup(int groupId);
	void setID(int ID);
	int getID(void);
	void setLine(float x, float y, float h, float w);
	void setLine(Cline line);
	void setCircle(float x, float y, float r);
	void setCircle(Ccircle circle);
	void init(void);

protected:
private:
};

#endif
