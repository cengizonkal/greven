#ifndef _C3DMODELLOADER_H
#define _C3DMODELLOADER_H
# include "C3Dmodel.h"
# include "../tools.h"
#include <stdio.h>
#include <stdlib.h>



class C3DmodelLoader {

  public:
    C3DmodelLoader();
    ~C3DmodelLoader();
    void load3DModel(C3Dmodel *model);
    void init(void);



};
#endif
