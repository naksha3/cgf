#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
GLfloat d=0;
char a;
void Spin()
{
d = d + 0.01;
if(d > 360)
d = 0;
glutPostRedisplay();
}
void Face(GLfloat A[3],GLfloat B[3],GLfloat C[3],GLfloat D[3])
{
glBegin(GL_QUADS);
glVertex3fv(A);
glVertex3fv(B);
glVertex3fv(C);
glVertex3fv(D);
glEnd();
}
void Cube(GLfloat P1[], GLfloat P2[], GLfloat P3[], GLfloat P4[], GLfloat P5[],
GLfloat P6[], GLfloat P7[], GLfloat P8[])
{
glColor3f(1,0,0);
Face(P1,P2,P3,P4);
glColor3f(0,1,0);
Face(P5,P6,P7,P8);
glColor3f(0,0,1);
Face(P1,P5,P8,P4);
glColor3f(1,1,0);
Face(P2,P6,P7,P3);
glColor3f(1,0,1);
Face(P1,P2,P6,P5);
glColor3f(0,1,1);
Face(P4,P3,P7,P8);
}
void Draw ()
{
GLfloat V[8][3] = {
{-0.5,-0.5,-0.5},
{ 0.5,-0.5,-0.5},
{ 0.5, 0.5,-0.5},
{-0.5, 0.5,-0.5},
{-0.5,-0.5, 0.5},
{ 0.5,-0.5, 0.5},
{ 0.5, 0.5, 0.5},
{-0.5, 0.5, 0.5},
 };
GLfloat nV[8][3],r;
int i;
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
r = d*3.14/180;
if(a=='z')
{
for(i=0;i<8;i++)
{
nV[i][0] = V[i][0]*cos(r)-V[i][1]*sin(r);
nV[i][1] = V[i][0]*sin(r)+V[i][1]*cos(r);
nV[i][2] = V[i][2];
}
}
if(a=='x')
{
for(i=0;i<8;i++)
{
nV[i][0] = V[i][0];
nV[i][1] = V[i][1]*cos(r)-V[i][2]*sin(r);
nV[i][2] = V[i][1]*sin(r)+V[i][2]*cos(r);
}
}
if(a=='y')
{
for(i=0;i<8;i++)
{
nV[i][0] = V[i][0]*cos(r) + V[i][2]*sin(r);
nV[i][1] = V[i][1];
nV[i][2] = -V[i][0]*sin(r) + V[i][2]*cos(r);
}
}
Cube(nV[0],nV[1],nV[2],nV[3],nV[4],nV[5],nV[6],nV[7]);
glutSwapBuffers();
}
int main(int argC,char *argV[])
{
printf("\nEnter the Axis of Rotation : ");
scanf("%c",&a);
glutInit(&argC,argV);
glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
glutInitWindowPosition(0,0);
glutInitWindowSize(500,500);
glutCreateWindow("Lab-3");
glutDisplayFunc(Draw);
glutIdleFunc(Spin);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}
