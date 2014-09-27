#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "SOIL.h"
using namespace std;

int sw = 1370;
int sh = 768;

GLuint texID1,texID2,texID3,texID4;
GLuint texID5,texID6,texID7,texID8,texID9;

GLuint texIDg;
GLuint texIDc;
GLuint texIDhc;
GLuint texIDp;

GLint xRaster=25,yRaster=150;
GLubyte label[30]={ '1' ,'2' ,'3' ,'4', '5', '6' ,'7' ,'8', '9' ,'10' ,'11', '12','13', '14' ,'15' ,'16' ,'17', '18' ,'19' ,'20' ,'21','22' ,'23', '24' ,'25' ,'26' ,'27' ,'28' ,'29' ,'30' };

int p[3],target,o,score,w1,w2,w3,out,e,lb=31;
int stat[60]={0},bc=0,i,m=0,n=0;

int ran(){
	int a;
	do{
        a=rand();
        a=a*rand()%1000+rand()%100;
        a=a/rand()%1000+rand()%100;
        a=a*rand()%1000+rand()%100;
        a%=6;
        a++;
	}while(a==0||a<0);
	return a;
}

GLuint LoadTexturehc(char* file)   //hc
{
	GLuint texIdhc = SOIL_load_OGL_texture(file, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_2D, texIdhc);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return texIdhc;
}

GLuint LoadTexturep(char* file)   //pes
{
	GLuint texIdp = SOIL_load_OGL_texture(file, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_2D, texIdp);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return texIdp;
}

GLuint LoadTexturec(char* file)   //bgcr
{
	GLuint texIdc = SOIL_load_OGL_texture(file, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_2D, texIdc);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return texIdc;
}

GLuint LoadTextureg(char* file)   //bg
{
	GLuint texIdg = SOIL_load_OGL_texture(file, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_2D, texIdg);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return texIdg;
}


GLuint LoadTexture1(char* file)   //cpu
{
	GLuint texId1 = SOIL_load_OGL_texture(file, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_2D, texId1);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return texId1;
}

GLuint LoadTexture2(char* file)   //human
{
	GLuint texId2 = SOIL_load_OGL_texture(file, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_2D, texId2);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return texId2;
}

GLuint LoadTexture3(char* file)   //lefthand
{
	GLuint texId3 = SOIL_load_OGL_texture(file, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_2D, texId3);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return texId3;
}

GLuint LoadTexture4(char* file)   //right hand
{
	GLuint texId4 = SOIL_load_OGL_texture(file, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_2D, texId4);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return texId4;
}

GLuint LoadTexture5(char* file)   //win
{
	GLuint texId5 = SOIL_load_OGL_texture(file, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_2D, texId5);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return texId5;
}

GLuint LoadTexture6(char* file)   //lose
{
	GLuint texId6 = SOIL_load_OGL_texture(file, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_2D, texId6);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return texId6;
}

GLuint LoadTexture7(char* file)   //out
{
	GLuint texId7 = SOIL_load_OGL_texture(file, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_2D, texId7);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return texId7;
}

GLuint LoadTexture8(char* file)   //draw
{
	GLuint texId8 = SOIL_load_OGL_texture(file, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_2D, texId8);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return texId8;
}

GLuint LoadTexture9(char* file)   //draw
{
	GLuint texId9 = SOIL_load_OGL_texture(file, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_2D, texId9);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	return texId9;
}

void LoadMainGLTextures() {

    char *a="img/grnd.png";

    texIDg = LoadTextureg((char*)(a));

}

void LoadcrGLTextures() {

    char *a="img/cr.png";

    texIDc = LoadTexturec((char*)(a));

}

void LoadspGLTextures() {

    char *a="img/hc.png",*b="img/pes.png";
    texIDhc = LoadTexturehc((char*)(a));
    texIDp = LoadTexturep((char*)(b));

}

void LoadGameGLTextures() {

    char *a="img/0l.png",*b="img/0r.png",*c="img/cpu.png",*d="img/human.png";

    texID1 = LoadTexture1((char*)(a));
    texID2 = LoadTexture2((char*)(b));
    texID3 = LoadTexture3((char*)(c));
    texID4 = LoadTexture4((char*)(d));

    texID5 = LoadTexture5((char*)("img/win.png"));
    texID6 = LoadTexture6((char*)("img/lose.png"));
    texID7 = LoadTexture7((char*)("img/out.png"));
    texID8 = LoadTexture8((char*)("img/draw.png"));
    texID9 = LoadTexture9((char*)("img/gameover.png"));

};

void drawNumber(int n,float x,float y,float z,float a){
    char *c,string[50];
    glPushMatrix();
    glTranslatef(x-19.5,y-10,z);
    glScalef(.5*a,.5*a,z);
    int b=sprintf (string, " %d ",n);
    for (c=string; *c != '\0'; c++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
    glPopMatrix();
}

void drawText(char*string,int x,int y,int z,float a){
    char *c;
    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(.5*a,.5*a,z);
    for (c=string; *c != '\0'; c++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
    glPopMatrix();
}

void spdisp11(){

    glColor4f(1,1,1,1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texIDp);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBegin(GL_POLYGON);
    glTexCoord2i(1,1); glVertex2i(400,600);
    glTexCoord2i(1,0); glVertex2i(400,200);
    glTexCoord2i(0,0); glVertex2i(100,200);
    glTexCoord2i(0,1); glVertex2i(100,600);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor4f(1,1,1,1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texIDhc);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBegin(GL_POLYGON);
    glTexCoord2i(1,1); glVertex2i(1200,400);
    glTexCoord2i(1,0); glVertex2i(1200,300);
    glTexCoord2i(0,0); glVertex2i(600,300);
    glTexCoord2i(0,1); glVertex2i(600,400);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(0,0,0);
    glLineWidth(4);
    drawText("PRESENTS",700,500,0,1);

}

void spdisp1(){

    glColor3f(1,1,1);
    spdisp11();
}

void hdisp1(){

    glColor4f(1,1,1,1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texIDg);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBegin(GL_POLYGON);
    glTexCoord2i(1,1); glVertex2i(sw,sh);
    glTexCoord2i(1,0); glVertex2i(sw,0);
    glTexCoord2i(0,0); glVertex2i(0,0);
    glTexCoord2i(0,1); glVertex2i(0,sh);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1,1,0);
    glLineWidth(2);
    drawText("By default the user bats first for 30 balls.",50,500,0,.5);
    drawText("You can select 1 of 6 numbers present on the right side.",50,400,0,.5);
    drawText("After the game your statistics is displayed",50,300,0,.5);
    drawText("You can exit the game anytime by using ESC key",50,200,0,.5);

}

void crdisp11(){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texIDc);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBegin(GL_POLYGON);
    glTexCoord2i(1,1); glVertex2i(sw,sh);
    glTexCoord2i(1,0); glVertex2i(sw,0);
    glTexCoord2i(0,0); glVertex2i(0,0);
    glTexCoord2i(0,1); glVertex2i(0,sh);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1,1,0);
    glLineWidth(3);
    drawText("CREDITS",550,650,0,1);
    drawText("handcricket",500,550,0,1);
    drawText("Written by",550,450,0,.75);
    drawText("Nagabharan N   ( 1PE10CS054 )",450,400,0,.5);
    drawText("Naveen Kumar M ( 1PE10CS056 )",450,350,0,.5);
    drawText("Special Thanks",500,250,0,.75);
    drawText("Prof. Sarasvathi V",550,200,0,.5);
    drawText("Friends",550,150,0,.5);

}

void crdisp1(){

    glColor3f(1,1,1);
    crdisp11();
}

void gamedisp11(){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texID1);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBegin(GL_POLYGON);
    glTexCoord2i(1,1); glVertex2i(450,500);
    glTexCoord2i(1,0); glVertex2i(450,200);
    glTexCoord2i(0,0); glVertex2i(50,200);
    glTexCoord2i(0,1); glVertex2i(50,500);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texID2);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBegin(GL_POLYGON);
    glTexCoord2i(1,1); glVertex2i(900,500);
    glTexCoord2i(1,0); glVertex2i(900,200);
    glTexCoord2i(0,0); glVertex2i(500,200);
    glTexCoord2i(0,1); glVertex2i(500,500);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texID3);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBegin(GL_POLYGON);
    glTexCoord2i(1,1); glVertex2i(200,625);
    glTexCoord2i(1,0); glVertex2i(200,525);
    glTexCoord2i(0,0); glVertex2i(300,525);
    glTexCoord2i(0,1); glVertex2i(300,625);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texID4);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBegin(GL_POLYGON);
    glTexCoord2i(1,1); glVertex2i(750,625);
    glTexCoord2i(1,0); glVertex2i(750,525);
    glTexCoord2i(0,0); glVertex2i(650,525);
    glTexCoord2i(0,1); glVertex2i(650,625);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(1,0,0);
    drawText("CPU",150,650,0,1.25);
    drawText("CPU",151,650,0,1.25);
    drawText("CPU",152,650,0,1.25);

    drawText("HUMAN",570,650,0,1.25);
    drawText("HUMAN",571,650,0,1.25);
    drawText("HUMAN",572,650,0,1.25);

    drawText("BALLS LEFT",330,550,0,.75);
    drawText("BALLS LEFT",331,550,0,.75);
    drawText("BALLS LEFT",332,550,0,.75);

    drawNumber(30-bc,400,625,0,1);

    if(out){

        glEnable(GL_TEXTURE_2D);
        glColor4f(1,1,1,1);
        glBindTexture(GL_TEXTURE_2D, texID7);
        glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
        glBegin(GL_POLYGON);
        glTexCoord2i(1,1); glVertex2i(150,180);
        glTexCoord2i(1,0); glVertex2i(150,20);
        glTexCoord2i(0,0); glVertex2i(50,20);
        glTexCoord2i(0,1); glVertex2i(50,180);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glColor3f(1,0,0);
        drawText("OUT",155,75,0,1);
        drawText("OUT",156,75,0,1);
        drawText("OUT",157,75,0,1);

    }

    if(w1){

        glEnable(GL_TEXTURE_2D);
        glColor4f(1,1,1,1);
        glBindTexture(GL_TEXTURE_2D, texID5);
        glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
        glBegin(GL_POLYGON);
        glTexCoord2i(1,1); glVertex2i(900,180);
        glTexCoord2i(1,0); glVertex2i(900,20);
        glTexCoord2i(0,0); glVertex2i(700,20);
        glTexCoord2i(0,1); glVertex2i(700,180);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glColor3f(1,0,0);
        drawText("USER WIN",355,75,0,1);
        drawText("USER WIN",356,75,0,1);
        drawText("USER WIN",357,75,0,1);
        e=1;
    }

    if(w2){

        glEnable(GL_TEXTURE_2D);
        glColor4f(1,1,1,1);
        glBindTexture(GL_TEXTURE_2D, texID6);
        glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
        glBegin(GL_POLYGON);
        glTexCoord2i(1,1); glVertex2i(900,180);
        glTexCoord2i(1,0); glVertex2i(900,20);
        glTexCoord2i(0,0); glVertex2i(700,20);
        glTexCoord2i(0,1); glVertex2i(700,180);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glColor3f(1,0,0);
        drawText("CPU WIN",325,75,0,1);
        drawText("CPU WIN",326,75,0,1);
        drawText("CPU WIN",327,75,0,1);
        e=1;
    }

    if(w3){

        glEnable(GL_TEXTURE_2D);
        glColor4f(1,1,1,1);
        glBindTexture(GL_TEXTURE_2D, texID8);
        glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
        glBegin(GL_POLYGON);
        glTexCoord2i(1,1); glVertex2i(900,180);
        glTexCoord2i(1,0); glVertex2i(900,20);
        glTexCoord2i(0,0); glVertex2i(700,20);
        glTexCoord2i(0,1); glVertex2i(700,180);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glColor3f(1,0,0);
        drawText("DRAW",325,75,0,1);
        drawText("DRAW",326,75,0,1);
        drawText("DRAW",327,75,0,1);
        e=1;
    }
}

void gamedisp21(){
    //1
    glBegin(GL_POLYGON);
    glVertex2d(1000,650);
    glVertex2d(1125,650);
    glVertex2d(1125,700);
    glVertex2d(1000,700);
    glEnd();
    //2
    glBegin(GL_POLYGON);
    glVertex2d(1175,650);
    glVertex2d(1300,650);
    glVertex2d(1300,700);
    glVertex2d(1175,700);
    glEnd();
    //3
    glBegin(GL_POLYGON);
    glVertex2d(1000,550);
    glVertex2d(1125,550);
    glVertex2d(1125,600);
    glVertex2d(1000,600);
    glEnd();
    //4
    glBegin(GL_POLYGON);
    glVertex2d(1175,550);
    glVertex2d(1300,550);
    glVertex2d(1300,600);
    glVertex2d(1175,600);
    glEnd();
    //5
    glBegin(GL_POLYGON);
    glVertex2d(1000,450);
    glVertex2d(1125,450);
    glVertex2d(1125,500);
    glVertex2d(1000,500);
    glEnd();
    //6
    glBegin(GL_POLYGON);
    glVertex2d(1175,450);
    glVertex2d(1300,450);
    glVertex2d(1300,500);
    glVertex2d(1175,500);
    glEnd();

}

void gamedisp22(){
    drawNumber(1,1050,675,0,.5);
    drawNumber(2,1220,675,0,.5);
    drawNumber(3,1050,575,0,.5);
    drawNumber(4,1220,575,0,.5);
    drawNumber(5,1050,475,0,.5);
    drawNumber(6,1220,475,0,.5);
    drawText("SELECT NUMBER",1015,720,0,.5);
    drawText("SELECT NUMBER",1016,720,0,.5);
    drawText("SELECT NUMBER",1017,720,0,.5);
}

void gamedisp31(int a,int b,int q){
    drawText("SCORE",1000,300,0,1.5);
    drawText("SCORE",1001,300,0,1.5);
    drawText("SCORE",1002,300,0,1.5);
    drawNumber(a,950,150,0,2);
    if(b){
        drawText("TARGET",950,50,0,.75);
        drawText("TARGET",951,50,0,.75);
        drawText("TARGET",952,50,0,.75);
        drawNumber(q,1100,50,0,1.5);
    }
}

void gamedisp1(){

    glColor3f(0,0.5+(float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX/.5);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(930,0);
    glVertex2d(930,sh);
    glVertex2d(0,sh);
    glEnd();
    glColor3f(1,1,1);
    gamedisp11();
}

void gamedisp2(){

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2d(930,400);
    glVertex2d(sw,400);
    glVertex2d(sw,sh);
    glVertex2d(930,sh);
    glEnd();
    glColor3f(0,0,0);
    gamedisp21();
    glColor3f(1,1,1);
    gamedisp22();
}

void gamedisp3(){

    glColor3f(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2d(930,0);
    glVertex2d(sw,0);
    glVertex2d(sw,400);
    glVertex2d(930,400);
    glEnd();
    glColor3f(1,1,1);
    gamedisp31(score,o,target+1);

}

void newdisp(){

    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glColor4f(1,1,1,1);
    glBindTexture(GL_TEXTURE_2D, texID9);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBegin(GL_POLYGON);
    glTexCoord2i(1,1); glVertex2i(sw,sh);
    glTexCoord2i(1,0); glVertex2i(sw,0);
    glTexCoord2i(0,0); glVertex2i(0,0);
    glTexCoord2i(0,1); glVertex2i(0,sh);
    glEnd();
    glDisable(GL_TEXTURE_2D);

}

void splash(){

    glClear(GL_COLOR_BUFFER_BIT);
    spdisp1();
    glutSwapBuffers();

}

void howtoplay(){

    glClear(GL_COLOR_BUFFER_BIT);
        if(!n){
        splash();
        sleep(3);
        n=1;
    }
    hdisp1();
    glutPostRedisplay();
}

void barchart(void)
{
	GLint month,k;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	drawText("STATISTICS",300,550,0,2);
	drawText("Runs scored each ball",400,500,0,.5);
    for(k=0;k<30;k++){
        if(stat[k]==1)
            glColor3f(1.0,0.0,0.0);
        if(stat[k]==2)
            glColor3f(0.0,1.0,0.0);
        if(stat[k]==3)
            glColor3f(0.0,0.0,1.0);
        if(stat[k]==4)
            glColor3f(1.0,1.0,0.0);
        if(stat[k]==5)
            glColor3f(1.0,0.0,1.0);
        if(stat[k]==6)
            glColor3f(0.0,1.0,1.0);
        if(stat[k]==0)
            glColor3f(1.0,1.0,1.0);
        if(stat[k]==-2)
            glColor3f(0.0,0.0,0.0);
		glRecti(270+k*30,180,280+k*30,200+40*stat[k]);
    }
	glColor3f(0.0,0.0,0.0);
	xRaster=270;
	for(month=0;month<30;month++)
	{	glRasterPos2i(xRaster,yRaster);
		for(k=month;k<month+1;k++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,label[k]);
		xRaster+=30;
	}
    glutSwapBuffers();
}

void credits(){

    glClear(GL_COLOR_BUFFER_BIT);
    crdisp1();
    glutSwapBuffers();

}

void game(){

    glClear(GL_COLOR_BUFFER_BIT);
    if(!m){
        howtoplay();
        glutSwapBuffers();
        sleep(13);
        m=1;
    }
    glLineWidth(2);
    gamedisp1();
    gamedisp2();
    gamedisp3();
    glutSwapBuffers();
    if(e){
        sleep(2);
        barchart();
        sleep(5);
        credits();
        sleep(4);
        newdisp();
        glutSwapBuffers();
    }
}

void anim(int n1,int n2){

    char a[30],b[30];

    switch(n1){
    case 1:
            sprintf(a,"img/%dl.png",n1);
            break;
    case 2:
            sprintf(a,"img/%dl.png",n1);
            break;
    case 3:
            sprintf(a,"img/%dl.png",n1);
            break;
    case 4:
            sprintf(a,"img/%dl.png",n1);
            break;
    case 5:
            sprintf(a,"img/%dl.png",n1);
            break;
    case 6:
            sprintf(a,"img/%dl.png",n1);
            break;
    default:
            cout<<"Invalid File\n";
    }
    switch(n2){
    case 1:
            sprintf(b,"img/%dr.png",n2);
            break;
    case 2:
            sprintf(b,"img/%dr.png",n2);
            break;
    case 3:
            sprintf(b,"img/%dr.png",n2);
            break;
    case 4:
            sprintf(b,"img/%dr.png",n2);
            break;
    case 5:
            sprintf(b,"img/%dr.png",n2);
            break;
    case 6:
            sprintf(b,"img/%dr.png",n2);
            break;
    default:
            cout<<"Invalid File\n";
    }

    texID1 = LoadTexture1((char*)(a));
    texID2 = LoadTexture2((char*)(b));

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texID1);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBegin(GL_POLYGON);
    glTexCoord2i(1,1); glVertex2i(450,500);
    glTexCoord2i(1,0); glVertex2i(450,100);
    glTexCoord2i(0,0); glVertex2i(50,100);
    glTexCoord2i(0,1); glVertex2i(50,500);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texID2);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBegin(GL_POLYGON);
    glTexCoord2i(1,1); glVertex2i(900,500);
    glTexCoord2i(1,0); glVertex2i(900,100);
    glTexCoord2i(0,0); glVertex2i(500,100);
    glTexCoord2i(0,1); glVertex2i(500,500);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glutPostRedisplay();

}

void action(int n){
    int c=ran();
    switch(n){
    case 1:
            anim(c,1);
            cout<<c<<" & 1\n";
            break;
    case 2:
            anim(c,2);
            cout<<c<<" & 2\n";
            break;
    case 3:
            anim(c,3);
            cout<<c<<" & 3\n";
            break;
    case 4:
            anim(c,4);
            cout<<c<<" & 4\n";
            break;
    case 5:
            anim(c,5);
            cout<<c<<" & 5\n";
            break;
    case 6:
            anim(c,6);
            cout<<c<<" & 6\n";
            break;
    default:
            cout<<"Invalid\n";
    }

    if(c!=n){
        out=0;
        if(!o){
            p[o]+=n;
            stat[i]=n;
            i++;
            bc++;
            if(bc==lb){
                out=1;
                bc=0;
                target=p[0];
                stat[i]=-2;
                if(o==0)
                    score=0;
                o++;
            }

        }
        else{
            p[o]+=c;
            bc++;
            if(bc==lb){
                out=1;
                bc=0;
                o++;
            }
        }
        score=p[o];

        if(o && p[1]>p[0]){
            cout<<"Game Over p2 won";
            w2++;
            for(int j=0;j<=i;j++) cout<<stat[j];
        }
    }
    else{
        out=1;
        bc=0;
        target=p[0];
        stat[i]=-2;
        if(o==0)
            score=0;
        o++;
    }
    if(o){
        if(o>1&&p[0]>p[1]){
            cout<<"Game Over p1 won";
            w1++;
            for(int j=0;j<=i;j++) cout<<stat[j];
        }
        if(o>1&&p[0]==p[1]){
            cout<<"Game Over draw";
            w3++;
            for(int j=0;j<=i;j++) cout<<stat[j];
        }
    }

}

void mouse(int btn,int state,int x,int y){
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
            if(!w1&&!w2&&!w3){
            y=(sh-y);
            if((x<=1125)&&(x>=1000)){
                if((y<=700)&&(y>=650))
                    action(1);
                else if((y<=600)&&(y>=550))
                    action(3);
                else if((y<=500)&&(y>=450))
                    action(5);
            }
            if((x<=1300)&&(x>=1175)){
                if((y<=700)&&(y>=650))
                    action(2);
                else if((y<=600)&&(y>=550))
                    action(4);
                else if((y<=500)&&(y>=450))
                    action(6);
            }
        }
    }
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN && e){
        cout<<"Cant quit";
        exit(0);
    }
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
    case 27:
            cout<<"Exiting game\n";
            exit(0);
            break;
    case 32 :
            if(e){
                exit(0);
            }
            else{
                cout<<"Cant quit";
                break;
            }
    default:
                cout<<"Invalid";
    }
}

void winReshape(GLint newWidth,GLint newHeight)
{
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)newWidth,0.0,(GLdouble)newHeight);
}

void reshape(int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

void myinit(){

    LoadMainGLTextures();
    LoadspGLTextures();
    LoadGameGLTextures();
    LoadcrGLTextures();

    glEnable(GL_TEXTURE_2D);
    glClearColor(1.0,1.0,1.0,1.0);
    glPointSize(1.0);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,sw,0.0,sh);
}

int main( int argc,char **argv){
    glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(sw,sh);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Combo");
	myinit();
	glutDisplayFunc(game);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutFullScreen();
    glutMainLoop();
    return 0;
}
