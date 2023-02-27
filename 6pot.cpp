#include<GL/glut.h>
#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
void Display()
{
GLfloat Pos[] = {-1,1,0,1};
GLfloat S[] = {0.5,0,0.25,1};
GLfloat D1[] = {1,0,0,1};
GLfloat D2[] = {0,0,1,1};
GLfloat D3[] = {0.5,0,0.25,1};
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLightfv(GL_LIGHT0,GL_POSITION,Pos);
glLightfv(GL_LIGHT0,GL_SPECULAR,S);
glLoadIdentity();
gluLookAt(0,0.5,3,0,0,0,0,1,0);
glPushAttrib(GL_ALL_ATTRIB_BITS);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,D1);
glPushMatrix();
glScalef(1,0.05,1);
glutSolidCube(1); //Table Top
glPopMatrix();
glPopAttrib();
glPushAttrib(GL_ALL_ATTRIB_BITS);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,D2);
glPushMatrix();
glTranslatef(-0.5,-0.4,-0.5);
glScalef(0.05, 0.8 ,0.05);
glutSolidCube(1); //Leg-1
glPopMatrix();
glPushMatrix();
glTranslatef( 0.5,-0.4,-0.5);
glScalef(0.05, 0.8 ,0.05);
glutSolidCube(1); //Leg-2
glPopMatrix();
glPushMatrix();
glTranslatef( 0.5,-0.4, 0.5);
glScalef(0.05, 0.8 ,0.05);
glutSolidCube(1); //Leg-3
glPopMatrix();
glPushMatrix();
glTranslatef(-0.5,-0.4, 0.5);
glScalef(0.05, 0.8 ,0.05);
glutSolidCube(1); //Leg-4
glPopMatrix();
glPopAttrib();
glPushAttrib(GL_ALL_ATTRIB_BITS);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,D3);
glPushMatrix();
glTranslatef(0,0.18,0);
glutSolidTeapot(0.2); //TeaPot
glPopMatrix();
glPopAttrib();
glutSwapBuffers();
}
int main(int argC, char *argV[])
{
glutInit(&argC,argV);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Lab-7: Scene Consisting of Tea Pot on Table");
glutDisplayFunc(Display);
glClearColor(1,1,1,1);
glEnable(GL_DEPTH_TEST);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-1,1,-1,1,2,20);
glMatrixMode(GL_MODELVIEW);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glutMainLoop();
return 0;
}
