#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
void init(void);
void display(void);


void init(void)
{

	gluOrtho2D(0.0, 640.0, 0.0, 480.0 );


}

void display(void)
{

   glBegin(GL_POLYGON);
	glColor3f(255/255.f, 0/255.f, 0/255.f);
	glVertex2i(50, 350);
	glVertex2i(150, 350);
	glVertex2i(150, 450);
	glVertex2i(50, 450);
	glEnd();

	   glBegin(GL_POLYGON);
   	glColor3f(0/255.f, 0/255.f, 255/255.f);
	glVertex2i(300, 200);
	glVertex2i(400, 200);
	glVertex2i(350, 300);
	glEnd();

		   glBegin(GL_POLYGON);
	glColor3f(247/255.f, 255/255.f, 0/255.f);
	glVertex2i(350, 350);
	glVertex2i(400, 350);
	glVertex2i(425, 400);
	glVertex2i(400, 450);
	glVertex2i(350, 450);
	glVertex2i(325, 400);
	glEnd();

glPushMatrix();
	glTranslated(20,-150,0);
   glBegin(GL_POLYGON);
	glColor3f(0/255.f, 255/255.f, 0/255.f);
	glVertex2i(50, 350);
	glVertex2i(150, 350);
	glVertex2i(150, 450);
	glVertex2i(50, 450);
	glEnd();
glPopMatrix();
glFlush();

glPushMatrix();
	glTranslated(310,150,0);
	glScalef(0.6f,0.6f,1.0f);
	glRotatef(90.0f,0.0f,0.0f,1.0f);
   glBegin(GL_POLYGON);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
	glVertex2i(50, 350);
    glColor3f(0/255.f, 0/255.f, 0/255.f);
	glVertex2i(150, 350);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
	glVertex2i(150, 450);
    glColor3f(0/255.f, 0/255.f, 0/255.f);
	glVertex2i(50, 450);
	glEnd();
glPopMatrix();
glFlush();

glPushMatrix();
	glTranslated(750,420,0);
	glRotatef(180.0f,0.0f,0.0f,1.0f);
   glBegin(GL_POLYGON);
   	glColor3f(255/255.f, 0/255.f, 0/255.f);
	glVertex2i(300, 200);
   	glColor3f(0/255.f, 255/255.f, 0/255.f);
	glVertex2i(400, 200);
    glColor3f(0/255.f, 0/255.f, 255/255.f);
	glVertex2i(350, 300);
	glEnd();
glPopMatrix();
glFlush();

}

main(int argc, char **argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Transformasi");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
