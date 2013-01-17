#include "Cgraphic.h"

Cgraphic::Cgraphic(void )
{
 init();
};
void Cgraphic::init(void )
{
    NoA=0;
    NoS=0;
    animations=(Canimation**)malloc(1*(sizeof(Canimation*)));
    sprites=(Csprite**)malloc(1*(sizeof(Csprite*)));
    NoT=0;
    textures=NULL;
    iTime=NULL;
    models=NULL;
    No3D=0;
    modelLoader.init();
    geo.init();
    debug=true;
    level=NULL;
    camera=NULL;
}
Cgraphic::~Cgraphic(void )
{

    animations=NULL;
    sprites=NULL;
    textures=NULL;
    iTime=NULL;
    models=NULL;

    free(animations);
    free(textures);
    free(iTime);
    free(models);

};



void Cgraphic::registerSprite(Csprite * s)
{
    NoS++;
    sprites=(Csprite**)realloc(sprites,NoS*(sizeof(Csprite*)));
    sprites[NoS-1]=s;
    s->id=NoS;
    if(s->toFrame==0)
        s->toFrame=(int)((textures[s->textId].w*textures[s->textId].h)/(s->fw*s->fh));

};
void Cgraphic::setLevel(Clevel *level)
{
  this->level=level;
};

void Cgraphic::drawSprites(void )
{
    Cvector pos;
    float angle;



    for(int i=0;i<NoS;i++)
    {
        int frameCount=0;
        frameCount=(int)sprites[i]->fc;
        float x1,y1,x2,y2;
        x1=frameCount*sprites[i]->fw;
        x1=(int)x1 % (int)textures[sprites[i]->textId].w;
        x2=x1+sprites[i]->fw;
        y1=(int)((frameCount*sprites[i]->fw)/textures[sprites[i]->textId].w);
        y1*=sprites[i]->fh;
        y2=y1+sprites[i]->fh;
        x1/=textures[sprites[i]->textId].w;
        x2/=textures[sprites[i]->textId].w;
        y1/=textures[sprites[i]->textId].h;
        y2/=textures[sprites[i]->textId].h;

        pos=sprites[i]->getPosition();

        //pos*=10;

        if(debug)
        {

            glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
            glColor3f(1,1,1);
            glPushMatrix();
            glTranslatef( pos.x, pos.y, 0 );
            if(sprites[i]->invert==1)
            {
                glRotatef( 180, 0, 1, 0 );
            }
            //glRotatef( angle * RADTODEG, 0, 0, 1 );//OpenGL uses degrees here

            glBegin (GL_QUADS);
                glVertex3f (-(sprites[i]->w/2),-(sprites[i]->h/2),0);
                glVertex3f (-(sprites[i]->w/2),(sprites[i]->h/2),0);
                glVertex3f ((sprites[i]->w/2),(sprites[i]->h/2),0);
                glVertex3f ((sprites[i]->w/2),-(sprites[i]->h/2),0);
            glEnd ();
            glPopMatrix();



        }
        else
        {
            glBindTexture(GL_TEXTURE_2D,textures[sprites[i]->textId].id);
            glEnable(GL_TEXTURE_2D);
            glPushMatrix();
            glTranslatef( pos.x, pos.y, 0 );
            if(sprites[i]->invert==1)
            {
                glRotatef( 180, 0, 1, 0 );
            }
            //glRotatef( angle * RADTODEG, 0, 0, 1 );//OpenGL uses degrees here

            glBegin (GL_QUADS);
                glTexCoord2f(x1,y1);
                glVertex3f (-(sprites[i]->w/2),-(sprites[i]->h/2),0);
                glTexCoord2f(x1,y2);
                glVertex3f (-(sprites[i]->w/2),(sprites[i]->h/2),0);
                glTexCoord2f(x2,y2);
                glVertex3f ((sprites[i]->w/2),(sprites[i]->h/2),0);
                glTexCoord2f(x2,y1);
                glVertex3f ((sprites[i]->w/2),-(sprites[i]->h/2),0);
            glEnd ();
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
        }


    }


};



void Cgraphic::draw3DModels()
{


     for(int j=0;j<No3D;j++)
     {
            if(debug || models[j].NoT<=0)
            {
                for(int i=0;i<models[j].NoVi;i++)
                {
                    glPushMatrix();
                    glScalef(METERTOPIXEL,METERTOPIXEL,METERTOPIXEL);
                    glBegin(GL_TRIANGLES);


                    glVertex3f(models[j].vertexList[(models[j].vindices[i*3]-1)*3],
                    models[j].vertexList[(models[j].vindices[i*3]-1)*3+1],
                    models[j].vertexList[(models[j].vindices[i*3]-1)*3+2]);


                    glVertex3f(models[j].vertexList[(models[j].vindices[i*3+1]-1)*3],
                    models[j].vertexList[(models[j].vindices[i*3+1]-1)*3+1],
                    models[j].vertexList[(models[j].vindices[i*3+1]-1)*3+2]);


                    glVertex3f(models[j].vertexList[(models[j].vindices[i*3+2]-1)*3],
                    models[j].vertexList[(models[j].vindices[i*3+2]-1)*3+1],
                    models[j].vertexList[(models[j].vindices[i*3+2]-1)*3+2]);

                    glEnd();
                    glPopMatrix();

                }


            }
            else
            {
                glBindTexture(GL_TEXTURE_2D,textures[2].id);
                glEnable(GL_TEXTURE_2D);
                for(int i=0;i<models[j].NoVi;i++)
                {
                    glPushMatrix();
                    glScalef(METERTOPIXEL,METERTOPIXEL,METERTOPIXEL);
                    glBegin(GL_TRIANGLES);

                    glTexCoord2f(models[j].textureList[(models[j].tindices[i*2]-1)*2],models[j].textureList[(models[j].tindices[i*2]-1)*2+1]);
                    glVertex3f(models[j].vertexList[(models[j].vindices[i*3]-1)*3],
                    models[j].vertexList[(models[j].vindices[i*3]-1)*3+1],
                    models[j].vertexList[(models[j].vindices[i*3]-1)*3+2]);

                    glTexCoord2f(models[j].textureList[(models[j].tindices[i*2+1]-1)*2],models[j].textureList[(models[j].tindices[i*2+1]-1)*2+1]);
                    glVertex3f(models[j].vertexList[(models[j].vindices[i*3+1]-1)*3],
                    models[j].vertexList[(models[j].vindices[i*3+1]-1)*3+1],
                    models[j].vertexList[(models[j].vindices[i*3+1]-1)*3+2]);

                    glTexCoord2f(models[j].textureList[(models[j].tindices[i*2+2]-1)*2],models[j].textureList[(models[j].tindices[i*2+2]-1)*2+1]);
                    glVertex3f(models[j].vertexList[(models[j].vindices[i*3+2]-1)*3],
                    models[j].vertexList[(models[j].vindices[i*3+2]-1)*3+1],
                    models[j].vertexList[(models[j].vindices[i*3+2]-1)*3+2]);

                    glEnd();
                    glPopMatrix();

                }


            }


     }
};

void Cgraphic::drawLevel()
{
    //if(debug)
    {

        //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        glColor3f(1,1,1);
        for(int i=0;i<(this->level->NoG);i++)
        {
            glBegin(GL_LINES);
            glVertex3f(level->grounds[i].pointA.x,level->grounds[i].pointA.y,0);
            glVertex3f(level->grounds[i].pointB.x,level->grounds[i].pointB.y,0);
            glEnd();
            //writeError("%f,%f",level->grounds[i].pointA.x,level->grounds[i].pointA.y);
            //writeError("%f,%f",level->grounds[i].pointB.x,level->grounds[i].pointB.y);
        }
        //exit(0);
    }
};
void Cgraphic::linkTime(Ctime * t)
{
    iTime=t;
    lastTime=iTime-> getCurrTime();
};

void Cgraphic::animate(void )
{
//    double deltaTime=0;
//
//    for(int i=0;i<NoA;i++)
//    {
//        deltaTime=iTime->getCurrTime()-lastTime;
//        //eðer animasyon aktif ise
//        if(animations[i]->isPlaying)
//        {
//            animations[i]->fc+=deltaTime*animations[i]->fps;
//            //eðer sona ulaþtýysa baþa dön loop
//            //if((animations[i]->fc+1)*animations[i]->fw*animations[i]->fh>textures[animations[i]->textId].w*textures[animations[i]->textId].h)
//                //animations[i]->fc=0;
//            if(animations[i]->fc>animations[i]->toFrame)
//             animations[i]->fc=animations[i]->fromFrame;
//        }
//
//    }
//    lastTime=iTime->getCurrTime();
};

void Cgraphic::animateSprites(void )
{
    double deltaTime=0;

    for(int i=0;i<NoS;i++)
    {
        deltaTime=iTime->getCurrTime()-lastTime;
        ///eğer animasyon aktif ise
        if(sprites[i]->isPlaying)
        {
            sprites[i]->fc+=deltaTime*sprites[i]->fps;
            if(sprites[i]->fc>sprites[i]->toFrame)
             sprites[i]->fc=sprites[i]->fromFrame;
        }

    }
    lastTime=iTime->getCurrTime();
};

//load models3D
void Cgraphic::load3DModels(void )
{
    FILE *fp; //textures.gr
    fp=fopen("3DModels.gr","r");
    char ch;
    char fileName[255];
    if(!fp)
    {
       writeError("%s","3DModels.gr dosyası yok!");
    }
    else
    {
        while(!feof(fp))
        {
            ch=getc(fp);
            if(ch=='<')
            {
                int i=0;
                while(ch!='>' && !feof(fp))
                {
                    ch=getc(fp);
                    fileName[i]=ch;
                    i++;
                }
                fileName[i-1]='\0';
                No3D++;
                models=(C3Dmodel*)realloc(models,No3D*(sizeof(C3Dmodel)));
                models[No3D-1].init();
                strcpy(models[No3D-1].fileName,fileName);
                modelLoader.load3DModel(&(models[No3D-1]));


            }
        }
    }

};



//textures
void Cgraphic::loadTextures(void )
{
    FILE *fp; //textures.gr
    fp=fopen("textures.gr","r");
    char ch;
    char fileName[255];
    if(!fp)
    {
       writeError("%s","textures.gr dosyası yok!");
    }
    else
    {
        while(!feof(fp))
        {
            ch=getc(fp);
            if(ch=='<')
            {
                int i=0;
                while(ch!='>' && !feof(fp))
                {
                    ch=getc(fp);
                    fileName[i]=ch;
                    i++;
                }
                fileName[i-1]='\0';
                loadTexture(fileName);

            }
        }
    }

};

void Cgraphic::loadTexture(char * fileName)
{

    Cbmp bmp;
    Ctga tga;
    char ext[10];
    extractFileExtension(fileName,ext);


    if(strcmp(ext,"bmp")==0)
    if(bmp.LoadBmp(fileName))
    {
        bmp.Dump();
        //MessageBox(hWnd,fileName,fileName,0);
        NoT++;
        textures = (Ctexture*) realloc (textures, NoT * sizeof(Ctexture));
        textures[NoT-1].w=bmp.w;
        textures[NoT-1].h=bmp.h;
        glGenTextures(1,&textures[NoT-1].id);
        glBindTexture(GL_TEXTURE_2D,textures[NoT-1].id);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

        if(bmp.bit==24)
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,bmp.w,bmp.h,0,GL_BGR,GL_UNSIGNED_BYTE,bmp.pixel);
        if(bmp.bit==32)
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,bmp.w,bmp.h,0,GL_BGRA,GL_UNSIGNED_BYTE,bmp.pixel);


        bmp.Free();
    }

    if(strcmp(ext,"tga")==0)
    if(tga.LoadTga(fileName))
    {
        tga.Dump();
        //MessageBox(hWnd,fileName,fileName,0);
        NoT++;
        textures = (Ctexture*) realloc (textures, NoT * sizeof(Ctexture));
        textures[NoT-1].w=tga.w;
        textures[NoT-1].h=tga.h;
        glGenTextures(1,&textures[NoT-1].id);
        glBindTexture(GL_TEXTURE_2D,textures[NoT-1].id);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

        if(tga.bit==24)
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,tga.w,tga.h,0,GL_BGR,GL_UNSIGNED_BYTE,tga.pixel);
        if(tga.bit==32)
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,tga.w,tga.h,0,GL_BGRA,GL_UNSIGNED_BYTE,tga.pixel);


        tga.Free();
    }

};

void Cgraphic::setCamera(Ccamera *c)
{
     this->camera=c;

};


