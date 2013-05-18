#ifndef _ENGINE_COLLISION_CLINE_H
#define _ENGINE_COLLISION_CLINE_H
#include "../geometrics/Cvector.h"

namespace engine { namespace collision{
class Cline {
public:
	engine::geometrics::Cvector point1;
	engine::geometrics::Cvector point2;
    engine::geometrics::Cvector relativePoint1;
    engine::geometrics::Cvector relativePoint2;


	Cline(void );
	~Cline(void );
	void init(void);




};
}}
#endif
