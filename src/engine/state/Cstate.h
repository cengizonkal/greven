#ifndef CSTATE_H
#define CSTATE_H

namespace engine { namespace state {
class Cstate {
public:
	Cstate();
	~Cstate();
	static int currentID;
	static int stateOfProgram;
	static int getId(void);

};
}
}
#endif // CSTATE_H
