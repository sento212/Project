
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
void myInit(void)
 {
 glClearColor(1.0,1.0,1.0,0.0);
 glColor3f(0.0f, 0.0f, 0.0f);
 glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 800.0, 0.0, 400.0);
}
class GLintPoint
{
public:
GLint x, y;
};
class Point2
{
public:
float x,y;
void set(float dx,float dy)
{
x = dx;
y = dy;
}
void set(Point2 &p)
{
x = p.x;
y = p.y;
}
Point2(float xx,float yy){
x = xx;
y = yy;
}
Point2()
{
x = y = 0;
}
};
GLintPoint CP;
float lerp (float a, float b, float t)
{
return a + (b - a) *t;
}
Point2 Tween(Point2 A, Point2 B ,float t)
{
Point2 P;
P.x = lerp(A.x,B.x,t);
P.y = lerp(A.y,B.y,t);
return P;
}
void moveTo(GLint x ,GLint y)
{
CP.x = x; CP.y = y;
}
void lineTo(GLint x ,GLint y)
{
glBegin (GL_LINES);
glVertex2i(CP.x,CP.y);
glVertex2i(x,y);
glEnd();
glutSwapBuffers();
CP.x = x; CP.y = y;
}
void drawTween (Point2 A[], Point2 B[], int n, float t)
{
 for (int i = 0; i < n; i++)
 {
 Point2 P;
 P = Tween (A[i], B[i], t);
 if (i == 0) moveTo (P.x, P.y);
 else lineTo (P.x, P.y);
 }
}void myDisplay(void)
{
int x;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
Point2 A[6];
A [0].set(100,100);
A [1].set(100,250);
A [2].set(0,250);
A [3].set(100,350);
A [4].set(200,250);
A [5].set(100,250);
Point2 B[6];
B [0].set (500,100);
B [1].set (500,300);
B [2].set (650,400);
B [3].set (800,300);
B [4].set (800,100);
B [5].set (500,100);
glColor3f(0,1,0);
drawTween(A,B,6,0.0);
glColor3f(1,0,0);
for(x=1;x<=9;x+=1)
{
drawTween(A,B,6,0.1*x);
}
glColor3f(0,1,0);
drawTween(A,B,6,0.991);
glFlush();
glutSwapBuffers();
}
main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
glutInitWindowSize(800,400);
glutInitWindowPosition(100,150);
glutCreateWindow("PAYUNG MENJADI RUMAH");
glutDisplayFunc(myDisplay);
myInit();
glutMainLoop();
}
