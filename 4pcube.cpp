#include <GL/glut.h>
GLfloat CamX=0,CamY=0,CamZ=4;
void Face(GLfloat A[],GLfloat B[],GLfloat C[],GLfloat D[])
{
glBegin(GL_POLYGON);
glVertex3fv(A);
glVertex3fv(B);
glVertex3fv(C);
glVertex3fv(D);
glEnd();
}
void Cube(GLfloat P1[],GLfloat P2[],GLfloat P3[],GLfloat P4[],GLfloat P5[],GLfloat P6[],
GLfloat P7[],GLfloat P8[])
{
glColor3f(1,0,0);
Face(P1,P2,P3,P4);
glColor3f(0,1,0);
Face(P2,P6,P7,P3);
glColor3f(1,1,0);
Face(P4,P3,P7,P8);
glColor3f(1,0,1);
Face(P1,P5,P8,P4);
glColor3f(0,1,1);
Face(P1,P2,P6,P5);
glColor3f(0,0,1);
Face(P5,P6,P7,P8);
}
void Display(void)
{
GLfloat V[8][3] = {
{-0.5,-0.5,-0.5},
{ 0.5,-0.5,-0.5},
{ 0.5, 0.5,-0.5},
{-0.5, 0.5,-0.5},
{-0.5,-0.5, 0.5},
{ 0.5,-0.5, 0.5},
{ 0.5, 0.5, 0.5},
{-0.5, 0.5, 0.5}
 };
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(CamX,CamY,CamZ,0,0,0,0,1,0);

Cube(V[0],V[1],V[2],V[3],V[4],V[5],V[6],V[7]);
glutSwapBuffers();
}
void Key(unsigned char Ch, int x, int y)
{
switch(Ch)
{
case 'x' : CamX = CamX - 0.5; break;
case 'X' : CamX = CamX + 0.5; break;
case 'y' : CamY = CamY - 0.5; break;
case 'Y' : CamY = CamY + 0.5; break;
case 'z' : CamZ = CamZ - 0.5; break;
case 'Z' : CamZ = CamZ + 0.5;
}
glutPostRedisplay();
}
int main(int c, char **v)
{
glutInit(&c,v);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowPosition(100,100);
glutInitWindowSize(500, 500);
glutCreateWindow("Lab-8: Perspective Viewing with Camera");
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-1,1,-1,1,2,20);
glMatrixMode(GL_MODELVIEW);
glutDisplayFunc(Display);
glutKeyboardFunc(Key);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}
