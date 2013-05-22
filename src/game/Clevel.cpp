#include "Clevel.h"

Clevel::Clevel()
{
    //ctor
}

Clevel::~Clevel()
{
    //dtor
}

void Clevel::loadLevel(char fileName[255])
{
    char buffer[255];
    engine::xml::CsimpleXml *root, *ptr;
    root = new engine::xml::CsimpleXml(fileName);
    /*Floors*/
    int childNumber = root->child("floors")->number_of_children();
    for(int i = 0; i < childNumber; i++) {
        ptr = root->child("floors")->child("floor", i);
        strcpy(buffer, ptr->value());
    }
}
