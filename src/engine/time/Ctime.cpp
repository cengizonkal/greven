# include "Ctime.h"
namespace engine { namespace time{
Ctime::Ctime()
{
    QueryPerformanceFrequency( &frequency ) ;
    currTime.QuadPart=0;
};

double Ctime::getCurrTime()
{
    QueryPerformanceCounter(&currTime);
    return ((double)currTime.QuadPart /(double)frequency.QuadPart);
};
}
}
