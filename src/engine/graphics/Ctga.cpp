#include "Ctga.h"
namespace engine { namespace graphics{
Ctga::Ctga()
{

    h=0;
    w=0;
    bit=0;
    pixel=NULL;
 };
Ctga::~Ctga()
{
    pixel=NULL;
    free(pixel);
};


void Ctga::Dump()
{
    FILE *fp;
    fp=fopen("dumpTga.txt","w");
    fprintf(fp,"\nh=%d",h);
    fprintf(fp,"\nw=%d",w);
    fprintf(fp,"\nbit=%d",bit);
    fclose(fp);
};

bool Ctga::LoadTga(char fName[255])
{
    FILE *fp;
    memcpy(fileName,fName,255);
    fp=fopen(fName,"rb");
    if(fp==NULL)
    {
     writeError(fName);
     writeError("%s","TGA Dosyası Açılamyıor");
     return false;
    }
    else
    {
     fseek(fp,12,SEEK_SET);
     fread(&w,2,1,fp);
     fread(&h,2,1,fp);
     fread(&bit,1,1,fp);

     fseek(fp,18,SEEK_SET);
     //R,G,B alpha yok
     if(bit==24)
      {
       pixel=(char*)malloc(3*w*h);
       fread(pixel,(3*w*h),1,fp);

      }
      if(bit==32)
      {
       pixel=(char*)malloc(4*w*h);
       fread(pixel,(4*w*h),1,fp);

      }
      return true;
    }

};

void Ctga::Free()
{
    free(pixel);
};
}}

