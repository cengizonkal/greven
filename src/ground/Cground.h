#ifndef CGROUND_H
#define CGROUND_H
#include "../geometrics/Cpoint.h"

class Cground
{
    public:
        Cground();
        virtual ~Cground();
    Cpoint pointA;
    Cpoint pointB;
    void init(void);
    void setGround(Cpoint a,Cpoint b);
    void setGround(float ax,float ay,float bx,float by);

    protected:
    private:
};

#endif // CGROUND_H
