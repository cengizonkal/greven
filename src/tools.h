//debug araçlarý
#ifndef _TOOLS_H
#define _TOOLS_H

#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>


inline void writeError(const char *fmt,...)
{
    FILE *fp;
    time_t lt;
    char *t;

    struct tm *ptr;
    lt=time(NULL);
    ptr=localtime(&lt);
    fp=fopen("logs/errorlog.txt","a+");
    fprintf(fp,"\n%s",asctime(ptr));

    va_list vl;
    va_start (vl, fmt);
    vfprintf (fp, fmt, vl);
    va_end (vl);

    fclose(fp);
}

inline void trace(const char *fmt,...)
{
    FILE *fp;
    time_t lt;
    char *t;

    struct tm *ptr;
    lt=time(NULL);
    ptr=localtime(&lt);
    fp=fopen("logs/trace.txt","a+");
    fprintf(fp,"\n%s",asctime(ptr));

    va_list vl;
    va_start (vl, fmt);
    vfprintf (fp, fmt, vl);
    va_end (vl);

    fclose(fp);
}


inline void memrev(char  *buf, size_t count)
{
      char *r;

      for (r = buf + count - 1; buf < r; buf++, r--)
      {


            *buf ^= *r;
            *r   ^= *buf;
            *buf ^= *r;
      }
}

inline void memswap(char  *buf,char *buf2, int count)
{
      while(count--)
      {


            *buf ^= *buf2;
            *buf2 ^= *buf;
            *buf ^= *buf2;

            buf++;
            buf2++;


      }

}


inline void extractFileExtension(char fileName[255],char ext[10])
{
    char *token;
    char fname[255];
    strcpy(fname,fileName);
    token=strtok(fname,".");
    while(token!=NULL)
    {
        strcpy(ext,token);
        token=strtok(NULL,".");
    }

}

#endif
