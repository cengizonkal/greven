
#include "C3Dmodel.h"
namespace engine { namespace graphics{
C3Dmodel::C3Dmodel(void )
{

        id=-1;
        textId=-1;

        vertexList=NULL;
        vindices=NULL;
        nindices=NULL;
        tindices=NULL;
        textureList=NULL;
        normalList=NULL;

        NoV=0;
        NoVi=0;
        NoN=0;
        NoNi=0;
        NoTi=0;
        NoT=0;
}
C3Dmodel::~C3Dmodel(void )
{


        vertexList=NULL;
        vindices=NULL;
        nindices=NULL;
        tindices=NULL;
        textureList=NULL;
        normalList=NULL;

        free(vertexList);
        free(vindices);
        free(nindices);
        free(tindices);
        free(textureList);
        free(normalList);


}
void C3Dmodel::setFileName(char * fileName)
{
     strcpy(this->fileName,fileName);
}
void C3Dmodel::dump(char * fileName)
{

        FILE *fp;
        fp=fopen(fileName,"w");
        fprintf(fp,"\nNov=%d NoVi=%d",NoV,NoVi);
        fprintf(fp,"\nNoN=%d NoNi=%d",NoN,NoNi);
        fprintf(fp,"\nNoT=%d NoTi=%d",NoT,NoTi);
        fprintf(fp,"\nvertex List");
        for(int i=0;i<NoV;i++)
        {
            fprintf(fp,"\n %f %f %f",vertexList[i*3],vertexList[i*3+1],vertexList[i*3+2]);
        }

        fprintf(fp,"\nnormal List");
        for(int i=0;i<NoN;i++)
        {
            fprintf(fp,"\n %f %f %f",normalList[i*3],normalList[i*3+1],normalList[i*3+2]);
        }

        fprintf(fp,"\nTexture List");
        for(int i=0;i<NoT;i++)
        {
            fprintf(fp,"\n %f %f",textureList[i*2],textureList[i*2+1]);
        }
        fprintf(fp,"\nVertex indices");
        for(int i=0;i<NoVi;i++)
        {
            fprintf(fp,"\n %d %d %d",vindices[i*3],vindices[i*3+1],vindices[i*3+2]);
        }

        fprintf(fp,"\nNormal indices");
        for(int i=0;i<NoNi;i++)
        {
            fprintf(fp,"\n %d %d %d",nindices[i*3],nindices[i*3+1],nindices[i*3+2]);
        }
        fprintf(fp,"\nTexture indices");
        for(int i=0;i<NoTi;i++)
        {
            fprintf(fp,"\n %d %d %d",tindices[i*3],tindices[i*3+1],tindices[i*3+2]);
        }


        fclose(fp);

}

void C3Dmodel::init(void )
{

        id=-1;
        textId=-1;

        vertexList=NULL;
        vindices=NULL;
        nindices=NULL;
        tindices=NULL;
        textureList=NULL;
        normalList=NULL;

        NoV=0;
        NoVi=0;
        NoN=0;
        NoNi=0;
        NoTi=0;
        NoT=0;
}

}}
