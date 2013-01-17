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
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(this->pack[i][j]==0)
            {
                this->pack[i][j]=item;
                break;
            }
        }
    }

}

