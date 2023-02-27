#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<math.h>
int AnFlag = 0;
int yFlag = 1,xFlag = 1;
float yC=-50,xC=-10;
float x[4],Y1[4],y2[4],y3[4];
void Menu(int Id)
{
switch(Id)
{
    case 1 : AnFlag = 1; break;
    case 2 : AnFlag = 0; break;
    case 3 : exit(0);
}
}
void Idle()
{
if(AnFlag == 1)
{
    if(yC<50 && yFlag == 1)
    yC = yC + 0.2;
    if(yC>=50 && yFlag == 1)
    yFlag = 0;
    if(yC>-50 && yFlag == 0)
    yC = yC - 0.2;
    if(yC<=-50 && yFlag == 0)
    yFlag = 1;
    if(xC<20 && xFlag == 1)
    xC = xC + 0.2;
    if(xC>=20 && xFlag == 1)
        xFlag = 0;
    if(xC>-20 && xFlag == 0)
    xC = xC - 0.2;
    if(xC<=-20 && xFlag == 0)
    xFlag = 1;
}
glutPostRedisplay();
}
void Draw()
{
    int i;
    double t,xt[200],y1t[200],y2t[200],y3t[200],y4t[200];
    glClear(GL_COLOR_BUFFER_BIT);
    x[0] = 300-xC; x[1] = 200; x[2] = 200; x[3] = 100;
    Y1[0] = 450; Y1[1] = 450+yC; Y1[2] = 450-yC; Y1[3] = 450;
    y2[0] = 400; y2[1] = 400+yC; y2[2] = 400-yC; y2[3] = 400;
    y3[0] = 350; y3[1] = 350+yC; y3[2] = 350-yC; y3[3] = 350;
    i=0;
    for (t = 0.0; t < 1.0; t += 0.005)
    {
        xt[i] = pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
        y1t[i] = pow(1-t,3)*Y1[0]+3*t*pow(1-t,2)*Y1[1]+3*pow(t,2)*(1-t)*Y1[2]+pow(t,3)*Y1[3];
        y2t[i] = pow(1-t,3)*y2[0]+3*t*pow(1-t,2)*y2[1]+3*pow(t,2)*(1-t)*y2[2]+pow(t,3)*y2[3];
        y3t[i] = pow(1-t,3)*y3[0]+3*t*pow(1-t,2)*y3[1]+3*pow(t,2)*(1-t)*y3[2]+pow(t,3)*y3[3];
        i++;
    }
    glColor3f(1,1,0);
    glBegin(GL_QUAD_STRIP);
    for (i=0;i<200;i++)
    {
        glVertex2d(xt[i],y1t[i]);
        glVertex2d(xt[i],y2t[i]);
    }
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_QUAD_STRIP);
        for (i=0;i<200;i++)
        {
            glVertex2d(xt[i],y2t[i]);
            glVertex2d(xt[i],y3t[i]);
        }
    glEnd();
    glColor3f(0.5,0.5,0.5);
    glRectf(85,460,100,0);
    glFlush();
}
void MyInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
    glutCreateMenu(Menu);
        glutAddMenuEntry("Play Animation",1);
        glutAddMenuEntry("Stop Animation",2);
        glutAddMenuEntry("Exit",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argC,char *argV[])
{
    glutInit(&argC,argV);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Flag");
    MyInit();
    glutDisplayFunc(Draw);
    glutIdleFunc(Idle);
    glutMainLoop();
    return 0;
}
