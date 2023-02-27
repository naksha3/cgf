#include <GL/glut.h>
#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
int LE[500],RE[500];
int Fill_Flag = 0,Line_Flag = 0;
void Intersection(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2)
{
GLfloat temp,M,x;
int i;
    if(y1>y2)
    {
    temp = y1;
    y1 = y2;
    y2 = temp;
    temp = x1;
    x1 = x2;
    x2 = temp;
    }
    if(y2 - y1 == 0)
        M = x2 - x1;
    else
    M = ( x2 - x1 ) / (y2 - y1);
    x = x1;
    for(i=y1;i<=y2;i++)
    {
            if(x<LE[i])
            {
                LE[i] = x;
            }
            if(x>RE[i])
            {
                RE[i] = x;
            }
            x = x + M;
     }
}
void Display()
{
    GLfloat x1=250,y1=150;
    GLfloat x2=400,y2=250;
    GLfloat x3=250,y3=350;
    GLfloat x4=100,y4=250;
    int i;
    GLint x,y;
    glClear(GL_COLOR_BUFFER_BIT);
    for(i=0;i<500;i++)
    {
        LE[i] = 500;
        RE[i] = 0;
    }
    if(Line_Flag == 1)
    {
        glColor3f(0,1,0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
        glEnd();
    }
    glColor3f(1,0,0);
    Intersection(x1,y1,x2,y2);
    Intersection(x2,y2,x3,y3);
    Intersection(x3,y3,x4,y4);
    Intersection(x4,y4,x1,y1);
if(Fill_Flag == 1)
{
for(y=0;y<500;y++)
{
if(LE[y]<=RE[y])
{
for(x=LE[y];x<=RE[y];x++)
{
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
        glFlush();
        }
        }
      }
    }
}
void Line_Menu(int Id)
{
    if(Id == 1)
    Line_Flag = 1;
    if(Id == 2)
    Line_Flag = 2;
    glutPostRedisplay();
}
void Main_Menu(int Id)
{
    if(Id == 1)
    Fill_Flag = 1;
    if(Id == 2)
    exit(0);
    glutPostRedisplay();
}
int main(int argC, char *argV[])
{
    int Id;
    glutInit(&argC,argV);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Lab9 : Scan-Line Fill Algorithm");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
    Id = glutCreateMenu(Line_Menu);
    glutAddMenuEntry("Yes",1);
    glutAddMenuEntry("No",2);
    glutCreateMenu(Main_Menu);
    glutAddSubMenu("Out Line",Id);
    glutAddMenuEntry("Start Fill",1);
    glutAddMenuEntry("Exit",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
