#ifndef _CLINE_H
#define _CLINE_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Cpoint.h"
namespace engine { namespace geometrics{
class Cline {
public:
	float x1 , y1;
	float x2 , y2;

	Cline(void );
	~Cline(void );
	void init(void);




};
}}
#endif
