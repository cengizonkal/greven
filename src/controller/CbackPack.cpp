#include "CbackPack.h"

CbackPack::CbackPack(void )
{


}
CbackPack::~CbackPack(void )
{


}
short CbackPack::addItem(short item)
{
    //search empty space and add item to that space
    for(int i=0;i<BACKPACK_SIZE;i++)
    {
        for(int j=0;j<BACKPACK_SIZE;j++)
        {
            if(this->pack[i][j]==0)
            {
                this->pack[i][j]=item;
                break;
            }
        }
    }

}

