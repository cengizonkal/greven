#ifndef CWALL_H
#define CWALL_H
#include "../geometrics/Cpoint.h"

class Cwall
{
    public:
        Cwall();
        virtual ~Cwall();
    Cpoint pointA;
    Cpoint pointB;
    void init(void);
    void setWall(Cpoint a,Cpoint b);
    void setWall(float ax,float ay,float bx,float by);
    protected:
    private:
};

#endif // CWALL_H
