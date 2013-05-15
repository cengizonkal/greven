#ifndef _ENGINE_COLLISION_CCIRCLE_H
#define _ENGINE_COLLISION_CCIRCLE_H
#include "../geometrics/Cvector.h"

namespace engine { namespace collision{
class Ccircle {
  public:
    engine::geometrics::Cvector position;
    engine::geometrics::Cvector relativePosition;
    double r; /**< Yarı çap */

    Ccircle(void );
    ~Ccircle(void );
    void init(void );

};
}
}
#endif
