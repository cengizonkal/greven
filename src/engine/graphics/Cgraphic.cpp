#include "Cgraphic.h"

Cgraphic::Cgraphic(void )
{
 init();
};
void Cgraphic::init(void )
{
    NoA=0; /**< Animasyon sayısı */
    animations=NULL;
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
    textures=NULL;
    iTime=NULL;
    models=NULL;

    free(animations);
    free(textures);
    free(iTime);
    free(models);

};



void Cgraphic::registerAnimation(Canimation *a)
{
    this->NoA++;
    this->animations=(Canimation**)realloc(animations, NoA*(sizeof(Canimation*)));
    animations[NoA-1] = a;

    if(a->toFrame == 0) {
        a->toFrame=(int)((textures[a->textId].w*textures[a->textId].h)/(a->fw*a->fh));
    }


};




void Cgraphic::drawAnimations(void )
{
    Cvector pos;
    float angle;

    for(int i=0;i<NoA;i++)
    {
        int frameCount=0;
        frameCount=(int)animations[i]->fc;
        float x1,y1,x2,y2;
        x1=frameCount*animations[i]->fw;
        x1=(int)x1 % (int)textures[animations[i]->textId].w;
        x2=x1+animations[i]->fw;
        y1=(int)((frameCount*animations[i]->fw)/textures[animations[i]->textId].w);
        y1*=animations[i]->fh;
        y2=y1+animations[i]->fh;
        x1/=textures[animations[i]->textId].w;
        x2/=textures[animations[i]->textId].w;
        y1/=textures[animations[i]->textId].h;
        y2/=textures[animations[i]->textId].h;

        pos=animations[i]->getPosition();

        //pos*=10;

        if(debug)
        {

            glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
            glColor3f(1,1,1);
            glPushMatrix();
            glTranslatef( pos.x, pos.y, 0 );
            if(animations[i]->invert==1)
            {
                glRotatef( 180, 0, 1, 0 );
            }
            //glRotatef( angle * RADTODEG, 0, 0, 1 );//OpenGL uses degrees here

            glBegin (GL_QUADS);
                glVertex3f (-(animations[i]->w/2),-(animations[i]->h/2),0);
                glVertex3f (-(animations[i]->w/2),(animations[i]->h/2),0);
                glVertex3f ((animations[i]->w/2),(animations[i]->h/2),0);
                glVertex3f ((animations[i]->w/2),-(animations[i]->h/2),0);
            glEnd ();
            glPopMatrix();



        }
        else
        {
            glBindTexture(GL_TEXTURE_2D,textures[animations[i]->textId].id);
            glEnable(GL_TEXTURE_2D);
            glPushMatrix();
            glTranslatef( pos.x, pos.y, 0 );
            if(animations[i]->invert==1)
            {
                glRotatef( 180, 0, 1, 0 );
            }
            //glRotatef( angle * RADTODEG, 0, 0, 1 );//OpenGL uses degrees here

            glBegin (GL_QUADS);
                glTexCoord2f(x1,y1);
                glVertex3f (-(animations[i]->w/2),-(animations[i]->h/2),0);
                glTexCoord2f(x1,y2);
                glVertex3f (-(animations[i]->w/2),(animations[i]->h/2),0);
                glTexCoord2f(x2,y2);
                glVertex3f ((animations[i]->w/2),(animations[i]->h/2),0);
                glTexCoord2f(x2,y1);
                glVertex3f ((animations[i]->w/2),-(animations[i]->h/2),0);
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

void Cgraphic::dump(void) {
  trace("Grafik sınıfı dökümü alınıyor...");
  trace("Animasyon sayısı %d",this->NoA);
  trace("Texture sayısı %d",this->NoT);
  trace("Texture sayısı %d",this->NoT);



};


