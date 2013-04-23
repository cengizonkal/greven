#ifndef _CTIME_H
#define _CTIME_H
#include <windows.h>
namespace engine { namespace time{
class Ctime {
  private:
    LARGE_INTEGER currTime;
    LARGE_INTEGER frequency;
  public:
     Ctime();
     double getCurrTime();
};
}
}
#endif
