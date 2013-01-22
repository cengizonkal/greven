#include "Cstate.h"

int Cstate::currentID = 0;
int Cstate::stateOfProgram = 0;

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
