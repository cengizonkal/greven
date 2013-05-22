#ifndef CLEVEL_H
#define CLEVEL_H
#include "Cfloor.h"
#include "Craziel.h"
#include "../engine/xml/CsimpleXml.h"

class Clevel
{
    public:
        Cfloor *floors;
        Craziel *raziel;

        Clevel();
        virtual ~Clevel();
        void loadLevel(char fileName[255]);/**< Xml dosyasından verileri oku */
    protected:
    private:
};

#endif // ClevelS_H
