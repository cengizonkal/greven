#include "Cgraphic.h"
namespace engine { namespace graphics{
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
    debug=false;
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
    engine::geometrics::Cvector pos;
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
        if(animations[i]->debug)
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


            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,textures[animations[i]->textId].id);
            glPushMatrix();
            glTranslatef( pos.x, pos.y, 0 );
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
                glBindTexture(GL_TEXTURE_2D,textures[0].id);
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

};
void Cgraphic::linkTime(engine::time::Ctime * t)
{
    iTime=t;
    lastTime=iTime-> getCurrTime();
};

void Cgraphic::animate(void ){
    double deltaTime=0;
    for(int i=0;i<NoA;i++)
    {
        deltaTime=iTime->getCurrTime()-lastTime;
        ///eğer animasyon aktif ise
        if(animations[i]->isPlaying)
        {
            animations[i]->fc+=deltaTime*animations[i]->fps;
            if(animations[i]->fc>animations[i]->toFrame)
             animations[i]->fc=animations[i]->fromFrame;
        }

    }
    lastTime=iTime->getCurrTime();

};








/** \brief Kaynakları yükle
 *  Tüm kaynaklar tek bir xml dosyası içinde olacak, ve tüm sınıflara gönderilebilecek
 *  Dosya ismini gönderip gerekli öğeleri çağıaracak
 * \param char *fileName
 * \return void
 *
 */
void Cgraphic::loadResources(char *fileName) {
    FILE *fp;
	char xmlFile[4096];
	engine::xml::CsimpleXml *root;
	engine::xml::CsimpleXml *ptr;
	char fName[255];
	fp = fopen(fileName, "r"); /**< Dosyayı okumak için aç */

	if(!fp) {
		writeError("Dosya bulunamadı: %s", fileName);
	} else {
		fread(xmlFile, 1, 4000, fp);
		root = new engine::xml::CsimpleXml(xmlFile);
		/*Textures*/
		int childNumber = root->child("textures")->number_of_children();
		for(int i = 0; i < childNumber; i++) {
			ptr = root->child("textures")->child("texture", i);
			strcpy(fName, ptr->value());
			this->loadTexture(fName);
		}
		/*3d Models*/
	}

};

void Cgraphic::loadTexture(char * fileName)
{
    char ext[10];
    extractFileExtension(fileName,ext);
    if(strcmp(ext,"bmp")==0){
        this->NoT++;
        this->loadBMP(fileName);
    }

    if(strcmp(ext,"tga")==0){
        this->NoT++;
        this->loadTGA(fileName);
    }


};

void Cgraphic::loadBMP(char *fileName) {
    Cbmp bmp;
    if(bmp.LoadBmp(fileName))
    {
        bmp.Dump();
        this->textures = (Ctexture*) realloc (textures, NoT * sizeof(Ctexture));
        this->textures[this->NoT-1].w=bmp.w;
        this->textures[this->NoT-1].h=bmp.h;
        glGenTextures(1,&this->textures[NoT-1].id);
        glBindTexture(GL_TEXTURE_2D,textures[NoT-1].id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

        if(bmp.bit==24)
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,bmp.w,bmp.h,0,GL_BGR,GL_UNSIGNED_BYTE,bmp.pixel);
        if(bmp.bit==32)
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,bmp.w,bmp.h,0,GL_BGRA,GL_UNSIGNED_BYTE,bmp.pixel);
        bmp.Free();
    }
}

void Cgraphic::loadTGA(char *fileName) {
    Ctga tga;
    if(tga.LoadTga(fileName))
    {

        textures = (Ctexture*) realloc (textures, NoT * sizeof(Ctexture));
        textures[NoT-1].w=tga.w;
        textures[NoT-1].h=tga.h;
        glGenTextures(1,&textures[NoT-1].id);
        glBindTexture(GL_TEXTURE_2D,textures[NoT-1].id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

        if(tga.bit==24)
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,tga.w,tga.h,0,GL_BGR,GL_UNSIGNED_BYTE,tga.pixel);
        if(tga.bit==32)
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,tga.w,tga.h,0,GL_BGRA,GL_UNSIGNED_BYTE,tga.pixel);
        tga.Free();
    }
}

void Cgraphic::setCamera(engine::camera::Ccamera *c)
{
     this->camera=c;
};

void Cgraphic::dump(void) {
  trace("\nGrafik sınıfı dökümü alınıyor...");
  trace("\nAnimasyon sayısı %d",this->NoA);
  trace("\nTexture sayısı %d",this->NoT);

};

void Cgraphic::testLoadTexture(void) {
    Cbmp bmp;
    bmp.LoadBmp("res/red.bmp");
    NoT++;
    textures = (Ctexture*) realloc (textures, NoT * sizeof(Ctexture));
    textures[NoT-1].w=bmp.w;
    textures[NoT-1].h=bmp.h;
    glGenTextures(1,&textures[NoT-1].id);
    glBindTexture(GL_TEXTURE_2D,textures[NoT-1].id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    if(bmp.bit==24)
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,bmp.w,bmp.h,0,GL_BGR,GL_UNSIGNED_BYTE,bmp.pixel);
    if(bmp.bit==32)
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,bmp.w,bmp.h,0,GL_BGRA,GL_UNSIGNED_BYTE,bmp.pixel);
    bmp.Free();
}

void Cgraphic::test(void) {

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,textures[2].id);
    glBegin (GL_QUADS);
        glTexCoord2f(0,0);
        glVertex3f (0,0,0);
        glTexCoord2f(0,1);
        glVertex3f (0,50,0);
        glTexCoord2f(1,1);
        glVertex3f (50,50,0);
        glTexCoord2f(1,0);
        glVertex3f (50,0,0);
    glEnd ();

}
}}
