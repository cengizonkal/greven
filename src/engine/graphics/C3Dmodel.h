#ifndef _C3DMODEL_H
#define _C3DMODEL_H
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <gl/gl.h>

class C3Dmodel {
  public:
    int id;

    GLfloat * vertexList;

    GLfloat * normalList;

    GLfloat * textureList;
    
    unsigned short * vindices;

    unsigned short * nindices;

    unsigned short * tindices;
    
        //dosya ismi
    char fileName[15];

    //texture id
    int textId;

    //number of Vertex
    int NoV;

    //number of normals
    int NoN;

    //texture koordinatlarý
    int NoT;

    //number of Vertex indices
    int NoVi;

    //number of Normal indices
    int NoNi;

    //number of Texture indices
    int NoTi;

    C3Dmodel(void );
    ~C3Dmodel(void );
    void setFileName(char * fileName);
    void dump(char * fileName);
    void init(void );

};
#endif
