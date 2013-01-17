#ifndef _CTIME_H
#define _CTIME_H
#include <windows.h>

class Ctime {
  private:
    LARGE_INTEGER currTime;
    LARGE_INTEGER frequency;
  public:
     Ctime();
     double getCurrTime(); 
}; 

#endif
