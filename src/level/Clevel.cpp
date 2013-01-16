#include "Clevel.h"
#include "../tools.h"
#include "../xml/simplexml.h"

Clevel::Clevel(void)
{
    init();
}
Clevel::~Clevel(void)
{

}
void Clevel::addGround(Cground ground)
{

    NoG++;
    this->grounds=(Cground*)realloc(grounds,NoG*(sizeof(Cground)));
    grounds[NoG-1]=ground;
}

void Clevel::addWall(Cwall wall)
{

    NoW++;
    this->walls=(Cwall*)realloc(walls,NoW*(sizeof(Cwall)));
    walls[NoW-1]=wall;
}

void Clevel::init(void)
{
    this->NoG=0;
    this->NoW=0;
    grounds=(Cground*)malloc(1*(sizeof(Cground)));
    walls=(Cwall*)malloc(1*(sizeof(Cwall)));
    this->currentLevel=1;

}
void Clevel::loadLevel()
{
    FILE *fp;
    char fileName[255];
    char xmlFile[4096];
    simplexml *root;
	simplexml *ptr;
	int ground=0;

    sprintf(fileName,"%s%d.gr","levels/level",currentLevel);
    fp=fopen(fileName,"r");
    if(!fp)
    {
        writeError("%s %d","Level dosyası yok!",currentLevel);
    }
    else
    {
        //load grounds
        fread(xmlFile,1,4000,fp);
        //writeError("%s",xmlFile);
        root = new simplexml(xmlFile);
        ground=root->child("grounds")->number_of_children();
        for(int i=0;i<ground;i++)
        {
            ptr = root->child("grounds")->child("ground",i);

            /*writeError("\n%d",atoi(ptr->child("pointA")->child("x")->value()));
            writeError("\n%d",atoi(ptr->child("pointA")->child("y")->value()));
            writeError("\n%d",atoi(ptr->child("pointB")->child("x")->value()));
            writeError("\n%d",atoi(ptr->child("pointB")->child("y")->value()));
            */

            float ax;
            float ay;
            float bx;
            float by;
            ax=atof(ptr->child("pointA")->child("x")->value());
            ay=atof(ptr->child("pointA")->child("y")->value());
            bx=atof(ptr->child("pointB")->child("x")->value());
            by=atof(ptr->child("pointB")->child("y")->value());



            Cground g;
            g.setGround(ax,ay,bx,by);
            this->addGround(g);


        }

    }


}



