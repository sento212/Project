#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

void init(void);
void display(void);

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Ornament bola natal");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLineWidth(3.0);
	glLoadIdentity();
	glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
}

void star(int n, float cx, float cy, float radius, float rotAngle){
    double angle, angleInc;
    int k;

    if(n<3) return;
    angle=rotAngle*3.14159265/180;
    angleInc=2*3.14159265/n;
    glColor3f(255/255.f, 255/255.f, 0/255.f);
    for(k=1;k<n;k++){
           for(k=1;k<=n;k++){
             angle+=angleInc;
            if(k%2==0)
            {
                glVertex2f(radius*2*cos(angle)+cy, (radius*2)*sin(angle)+cy);

            }
if(k%2==1){
             glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
        }
    }
    }
}

void snow(int n, float cx, float cy, float radius, float rotAngle){
    double angle, angleInc;
    int k;

    if(n<3) return;
    angle=rotAngle*3.14159265/180;
    angleInc=2*3.14159265/n;
    for(k=1;k<=n;k++){
             angle+=angleInc;
            if(k%2==0)
            {
                glColor3f(212/255.f, 240/255.f, 255/255.f);
                glVertex2f(radius*2*cos(angle)+cy, (radius*2)*sin(angle)+cy);

            }

        if(k%2==1){
                	glColor3f(204/255.f, 236/255.f, 255/255.f);
             glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
        }
    }
}

void ngon(int n, float cx, float cy, float radius, float rotAngle){
    double angle, angleInc;
    int k;
    if(n<3) return;
    angle=rotAngle*3.14159265/180;
    angleInc=2*3.14159265/n;
    glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
    for(k=0;k<n;k++){
        angle+=angleInc;
        glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
    }
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	    glBegin(GL_POLYGON);
        snow(12,0,0,30,180);
    glEnd();

	   int line[6][2]={{0,80},{0,-80},{60,40},{-60,-40},{-60,40},{60,-40}};
	        glBegin(GL_LINES);
        glColor3f(191/255.f, 231/255.f, 255/255.f);
        for(int k=0;k<6;k++)
        {
               glVertex2i(line[k][0],line[k][1]);
        }
    glEnd();


      glBegin(GL_LINE_STRIP);
       glVertex2i(-15,70);
       glVertex2i(0,60);
       glVertex2i(15,70);
    glEnd();

          glBegin(GL_LINE_STRIP);
       glVertex2i(-20,50);
       glVertex2i(0,40);
       glVertex2i(20,50);
    glEnd();

     glBegin(GL_LINE_STRIP);
       glVertex2i(-18,60);
       glVertex2i(0,50);
       glVertex2i(18,60);
    glEnd();

    glPushMatrix();
    glRotatef(180.0f,0.0f,0.0f,1.0f);
    glBegin(GL_LINE_STRIP);
       glVertex2i(-15,70);
       glVertex2i(0,60);
       glVertex2i(15,70);
    glEnd();

          glBegin(GL_LINE_STRIP);
       glVertex2i(-20,50);
       glVertex2i(0,40);
       glVertex2i(20,50);
    glEnd();

     glBegin(GL_LINE_STRIP);
       glVertex2i(-18,60);
       glVertex2i(0,50);
       glVertex2i(18,60);
    glEnd();
    glPopMatrix();
glFlush();


	   glBegin(GL_POLYGON);
     star(10,0,0,5,90);
    glEnd();

     glBegin(GL_LINE_LOOP);
     glColor3f(191/255.f, 231/255.f, 255/255.f);
        ngon(6,0,0,80,30);
    glEnd();
	glutSwapBuffers();

}
