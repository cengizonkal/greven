#ifndef _CBACK_PACK_H
#define _CBACK_PACK_H
# include "../def.h"
class CbackPack
{
public:
    CbackPack(void );
    ~CbackPack(void );

    /**
    * for adding item to backpack
    * @param item
    * @return 0 if fail, itemid if success
    */
    short addItem(short item);

private:
    short pack[4][4];


};
#endif
