#ifndef _CCIRCLE_H
#define _CCIRCLE_H

namespace engine { namespace geometrics{
class Ccircle {
  public:
    double x;

    double y;

    double r; /**< Yarı çap */

    Ccircle(void );
    ~Ccircle(void );
    void init(void );

};
}
}
#endif
