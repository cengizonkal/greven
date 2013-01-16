
#include "Cbmp.h"

void Cbmp::Dump() {

      FILE *fp;
      fp=fopen("dumpBMP.txt","w");
      fprintf(fp,"\nh=%d",h);
      fprintf(fp,"\nw=%d",w);
      fprintf(fp,"\nbit=%d",bit);
      fclose(fp);
}

bool Cbmp::LoadBmp(char fileName[255]) {

        FILE *fp;
        fp=fopen(fileName,"rb");
        if(fp==NULL)
        {
         return false;
        }
        else
        {
         fseek(fp,18,SEEK_SET);
         fread(&w,4,1,fp);
         fread(&h,4,1,fp);

         fseek(fp,28,SEEK_SET);
         fread(&bit,2,1,fp); //önce düþük byte ý o yüzden sorun yok (FF=255)

         fseek(fp,54,SEEK_SET);
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




}

void Cbmp::Free() {

         free(pixel);
}

