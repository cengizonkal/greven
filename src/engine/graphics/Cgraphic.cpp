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
    No3D = 0;
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



void Cgraphic::registerGameObject(Canimation *a)
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
                glVertex3f (-(animations[i]->w * UNITTOPIXEL / 2),-(animations[i]->h * UNITTOPIXEL/2),0);
                glVertex3f (-(animations[i]->w * UNITTOPIXEL / 2),(animations[i]->h * UNITTOPIXEL/2),0);
                glVertex3f ((animations[i]->w * UNITTOPIXEL / 2),(animations[i]->h * UNITTOPIXEL/2),0);
                glVertex3f ((animations[i]->w* UNITTOPIXEL / 2),-(animations[i]->h * UNITTOPIXEL/2),0);
            glEnd ();
            glPopMatrix();



        }
        else
        {


            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,textures[animations[i]->textId].id);
            glPushMatrix();
            glTranslatef( pos.x*UNITTOPIXEL, pos.y*UNITTOPIXEL, 0 );
            glBegin (GL_QUADS);
                glTexCoord2f(x1,y1);
                glVertex3f (-(animations[i]->w * UNITTOPIXEL/2), -(animations[i]->h * UNITTOPIXEL/2), 0);
                glTexCoord2f(x1,y2);
                glVertex3f (-(animations[i]->w * UNITTOPIXEL/2), (animations[i]->h * UNITTOPIXEL/2), 0);
                glTexCoord2f(x2,y2);
                glVertex3f ((animations[i]->w * UNITTOPIXEL/2), (animations[i]->h * UNITTOPIXEL/2), 0);
                glTexCoord2f(x2,y1);
                glVertex3f ((animations[i]->w * UNITTOPIXEL /2), -(animations[i]->h * UNITTOPIXEL/2), 0);
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
                    glScalef(UNITTOPIXEL,UNITTOPIXEL,UNITTOPIXEL);
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
                    glScalef(UNITTOPIXEL,UNITTOPIXEL,UNITTOPIXEL);
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
        if((animations[i]->loop == -1) || ((animations[i]->isPlaying) && (animations[i]->loop>0)))
        {
            animations[i]->fc+= deltaTime*animations[i]->fps;
            if(animations[i]->fc > animations[i]->toFrame) {
                animations[i]->fc = animations[i]->fromFrame;
                /**< Bir tur bitti */
                if(animations[i]->loop > 0) {
                    animations[i]->loop--;
                }
            }

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
		childNumber = root->child("models")->number_of_children();
		for(int i = 0; i < childNumber; i++) {
			ptr = root->child("models")->child("model", i);
			strcpy(fName, ptr->value());
			this->loadModel(fName);
		}
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
        //bmp.Dump();
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

void Cgraphic::loadModel(char *fileName) {
    char ext[10];
    extractFileExtension(fileName,ext);
    if(strcmp(ext,"obj")==0){
        try{
            this->No3D++;
            this->loadObj(fileName);
        }
        catch(int e) {
            writeError("Exception occurred while loading %s", fileName);
            this->No3D--;
        }

    }


}

void Cgraphic::loadObj(char *fileName) {


    this->models = (engine::graphics::C3Dmodel*) realloc (this->models, No3D * sizeof(engine::graphics::C3Dmodel));
    engine::graphics::C3Dmodel *model;
    model = &this->models[No3D-1];
    model->init();
    char buf[255];
    FILE *fp;
    unsigned short intNormal=0;
    unsigned short intVertex=0;
    unsigned short intTexture=0;
    unsigned short intTest=0;

    //buf=(char*)malloc(255);
    fp=fopen(fileName,"rb");
    if(fp==NULL)
    {
     writeError("%s","Obj Dosyası Açılamıyor ");
     exit(0);
    }




    while(fscanf(fp, "%s", buf) != EOF)
    {
        switch(buf[0])
        {
            case '#':
                fgets(buf, 255, fp);
            break;


            case 'v':
                if (buf[1]== '\0')
                {
                    model->NoV++;
                    model->vertexList=(float*)realloc(
                                                model->vertexList
                                                ,model->NoV*sizeof(float)*3);
                    fscanf(fp, "%f", &model->vertexList[(model->NoV-1)*3]);
                    fscanf(fp, "%f", &model->vertexList[(model->NoV-1)*3+1]);
                    fscanf(fp, "%f", &model->vertexList[(model->NoV-1)*3+2]);
                }

                if(buf[1]=='n')
                {
                    model->NoN++;
                    model->normalList=(float*)realloc(
                        model->normalList
                        ,model->NoN*sizeof(float)*3);

                    fscanf(fp, "%f", &model->normalList[(model->NoN-1)*3]);
                    fscanf(fp, "%f", &model->normalList[(model->NoN-1)*3]+1);
                    fscanf(fp, "%f", &model->normalList[(model->NoN-1)*3+2]);
                }

                if(buf[1]=='t')
                {
                    model->NoT++;
                    model->textureList=(float*)realloc(
                    model->textureList
                    ,model->NoT*sizeof(float)*2);
                    fscanf(fp, "%f",&model->textureList[(model->NoT-1)*2]);
                    fscanf(fp, "%f",&model->textureList[(model->NoT-1)*2+1]);
                }
            break;
            case 't':
            //
            break;
            case 'f':



                fscanf(fp, "%s", buf);
                if (strstr(buf, "//"))
                {
                    model->NoVi++;
                    model->NoNi++;

                    model->vindices=(unsigned short*)realloc(
                        model->vindices
                        ,model->NoVi*sizeof(unsigned short)*3);

                    model->nindices=(unsigned short*)realloc(
                        model->nindices
                        ,model->NoNi*sizeof(unsigned short)*3);

                    sscanf(buf, "%hu//%hu", &intVertex,&intNormal);
                    model->vindices[(model->NoVi-1)*3] = intVertex;
                    model->nindices[(model->NoNi-1)*3] = intNormal;

                    fscanf(fp, "%hu//%hu", &intVertex, &intNormal);
                    model->vindices[(model->NoVi-1)*3+1] = intVertex;
                    model->nindices[(model->NoNi-1)*3+1] = intNormal;

                    fscanf(fp, "%hu//%hu", &intVertex, &intNormal);
                    model->vindices[(model->NoVi-1)*3+2] = intVertex;
                    model->nindices[(model->NoNi-1)*3+2] = intNormal;

                }
                else if (sscanf(buf, "%hu/%hu/%hu", &intVertex, &intTexture, &intNormal) == 3)
                {
                    model->NoVi++;
                    model->NoNi++;
                    model->NoTi++;

                    model->vindices=(unsigned short*)realloc(
                        model->vindices
                        ,model->NoVi*sizeof(unsigned short)*3);

                    model->nindices=(unsigned short*)realloc(
                        model->nindices
                        ,model->NoNi*sizeof(unsigned short)*3);

                    model->tindices=(unsigned short*)realloc(
                        model->tindices
                        ,model->NoTi*sizeof(unsigned short)*3);

                    model->vindices[(model->NoVi-1)*3] = intVertex;
                    model->tindices[(model->NoTi-1)*3]= intTexture;
                    model->nindices[(model->NoNi-1)*3] = intNormal;
                    fscanf(fp, "%hu/%hu/%hu", &intVertex, &intTexture, &intNormal);
                    model->vindices[(model->NoVi-1)*3+1] = intVertex;
                    model->tindices[(model->NoTi-1)*3+1]= intTexture;
                    model->nindices[(model->NoNi-1)*3+1] = intNormal;
                    fscanf(fp, "%hu/%hu/%hu", &intVertex, &intTexture, &intNormal);
                    model->vindices[(model->NoVi-1)*3+2] = intVertex;
                    model->tindices[(model->NoTi-1)*3+2]= intTexture;
                    model->nindices[(model->NoNi-1)*3+2] = intNormal;
                }
                else if (sscanf(buf, "%hu/%hu", &intVertex, &intTexture) == 2)
                {
                    model->NoVi++;
                    model->NoTi++;

                    model->vindices=(unsigned short*)realloc(
                        model->vindices
                        ,model->NoVi*sizeof(unsigned short)*3);


                    model->tindices=(unsigned short*)realloc(
                        model->tindices
                        ,model->NoTi*sizeof(unsigned short)*3);

                    sscanf(buf, "%hu/%hu"
                                ,&model->vindices[(model->NoVi-1)*3]
                                ,&model->tindices[(model->NoTi-1)*3]);
                    fscanf(fp, "%hu/%hu"
                               ,&model->vindices[(model->NoVi-1)*3+1]
                               ,&model->tindices[(model->NoTi-1)*3+1]);

                    fscanf(fp, "%hu/%hu"
                               ,&model->vindices[(model->NoVi-1)*3+2]
                               ,&model->tindices[(model->NoTi-1)*3+2]);

                }
                else
                {
                    model->NoVi++;


                    model->vindices=(unsigned short*)realloc(
                        model->vindices
                        ,model->NoVi*sizeof(unsigned short)*3);

                    sscanf(buf, "%hu", &intVertex);
                    model->vindices[(model->NoVi-1)*3] = intVertex;
                    fscanf(fp, "%hu", &intVertex);
                    model->vindices[(model->NoVi-1)*3+1] = intVertex;
                    fscanf(fp, "%hu", &intVertex);
                    model->vindices[(model->NoVi-1)*3+2] = intVertex;
                }

            break;

            default:
            // eat up rest of line
            fgets(buf, sizeof(buf), fp);
            break;
        }

    }

}

void Cgraphic::dump(void) {
  /*trace("\nGrafik sınıfı dökümü alınıyor...");
  trace("\nAnimasyon sayısı %d",this->NoA);
  trace("\nTexture sayısı %d",this->NoT);*/

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

void Cgraphic::step() {
    this->animate();
    this->drawAnimations();


}

}}
