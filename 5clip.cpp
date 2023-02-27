#include <GL/glut.h>
GLfloat Xmin=-0.5,Xmax=0.5,Ymin=-0.5,Ymax=0.5;
GLfloat X1=-0.4,Y1=0.65,X2=0.6,Y2=-0.6;
int Left=1,Right=2,Bottom=4,Top=8;
int C1,C2;
int Flag = 0;
int Get_Code(GLfloat x,GLfloat y)
{
int C=0;
if(x < Xmin)
C = C | Left;
if(x > Xmax)
C = C | Right;
if(y < Ymin)
C = C | Bottom;
if(y > Ymax)
C = C | Top;
return C;
}
void Clip()
{
GLfloat X,Y;
int C;
if(C1)
C = C1;
else
C = C2;
if(C & Left)
{
X = Xmin;
Y = Y1 + (Y2 - Y1) * ((Xmin - X1) / (X2 - X1));
}
if(C & Right)
{
X = Xmax;
Y = Y1 + (Y2 - Y1) * ((Xmax - X1) / (X2 - X1));
}
if(C & Bottom)
{
Y = Ymin;
X = X1 + (X2 - X1) * ((Ymin - Y1) / (Y2 - Y1));
}
if(C & Top)
{
Y = Ymax;
X = X1 + (X2 - X1) * ((Ymax - Y1) / (Y2 - Y1));
}
if(C == C1)
{
X1 = X;
Y1 = Y;
}
else
{
X2 = X;
Y2 = Y;
}
}
void Display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
glRectf(Xmin,Ymin,Xmax,Ymax);
glColor3f(0,0,1);
glBegin(GL_LINES);
glVertex2f(X1,Y1);
glVertex2f(X2,Y2);
glEnd();
while(1 && Flag)
{
C1=Get_Code(X1,Y1);
C2=Get_Code(X2,Y2);
if((C1|C2) == 0)
break;
else if((C1&C2) != 0)
break;
else
Clip();
}
glFlush();
}
void Key(unsigned char ch, int x, int y)
{
Flag = 1;
glutPostRedisplay();
}
int main(int argC, char *argV[])
{
glutInit(&argC,argV);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Lab5: Cohen-Sutherland Line Clipping");
glClearColor(1,1,1,1);
glutDisplayFunc(Display);
glutKeyboardFunc(Key);
glutMainLoop();
return 0;
}
