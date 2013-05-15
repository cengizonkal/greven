#ifndef _ENGINE_COLLISION_CLINE_H
#define _ENGINE_COLLISION_CLINE_H
#include "../geometrics/Cvector.h"

namespace engine { namespace collision{
class Cline {
public:
	engine::geometrics::Cvector position;
    engine::geometrics::Cvector relativePosition;
    float w, h;

	Cline(void );
	~Cline(void );
	void init(void);




};
}}
#endif
