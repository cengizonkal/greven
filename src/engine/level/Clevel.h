#ifndef _CLEVEL_H
#define _CLEVEL_H


namespace engine { namespace level {
class Clevel {
public:
	Clevel();
	~Clevel();
	int currentLevel;
	void loadLevel();
	void init(void);



};
}
}
#endif
