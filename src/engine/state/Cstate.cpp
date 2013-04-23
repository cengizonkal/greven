#include "Cstate.h"

int engine::state::Cstate::currentID = 0;
int engine::state::Cstate::stateOfProgram = 0;
namespace engine { namespace state {
Cstate::Cstate() {
    this->stateOfProgram = 0; /**< idle */
    this->currentID = 0; /**< ilk olarak id 0 */
}

Cstate::~Cstate() {
	//dtor
}
int Cstate::getId(void) {
    Cstate::currentID++;
    return Cstate::currentID;
}
}
}
