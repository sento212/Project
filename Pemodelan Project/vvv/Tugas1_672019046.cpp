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
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glPointSize(8.0);
	glLineWidth(3.0);
	gluOrtho2D(0.0, 450.0, 0.0, 450.0 );
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
	glColor3f(1/255.f, 255/255.f, 1/255.f);
	glVertex2i(0, 0);
	glVertex2i(450, 0);
	glVertex2i(450, 300);
	glVertex2i(0, 300);
	glEnd();

	    glBegin(GL_POLYGON);
	glColor3f(35/255.f, 255/255.f, 255/255.f);
	glVertex2i(0, 300);
	glVertex2i(450, 300);
	glVertex2i(450, 450);
	glVertex2i(0, 450);
	glEnd();

				glBegin(GL_POLYGON);
	glColor3f(200/255.f, 244/255.f, 7/255.f);
	glVertex2i(20, 350);
	glVertex2i(70, 350);
	glVertex2i(70, 420);
	glVertex2i(20, 420);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(68/255.f, 138/255.f, 174/255.f);
	glVertex2i(0, 300);
	glVertex2i(150, 480);
	glVertex2i(300, 300);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(255/255.f, 255/255.f, 255/255.f);
	glVertex2i(83, 400);
	glVertex2i(150, 480);
	glVertex2i(217, 400);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.789, 0.50, 1.00);
	glVertex2i(200, 100);
	glVertex2i(450, 100);
	glVertex2i(450, 350);
	glVertex2i(200, 350);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1/255.f, 1/255.f, 1/255.f);
	glVertex2i(40, 220);
	glVertex2i(60, 220);
	glVertex2i(60, 240);
	glVertex2i(40, 240);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1/255.f, 1/255.f, 1/255.f);
	glVertex2i(50, 150);
	glVertex2i(50, 220);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1/255.f, 1/255.f, 1/255.f);
	glVertex2i(20, 200);
	glVertex2i(80, 200);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1/255.f, 1/255.f, 1/255.f);
	glVertex2i(50, 150);
	glVertex2i(20, 100);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1/255.f, 1/255.f, 1/255.f);
	glVertex2i(50, 150);
	glVertex2i(80, 100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.50, 1.00);
	glVertex2i(200, 350);
	glVertex2i(450, 350);
	glVertex2i(325, 450);
	glEnd();

		glBegin(GL_POLYGON);
	glColor3f(254/255.f, 75/255.f, 48/255.f);
	glVertex2i(340, 100);
	glVertex2i(400, 100);
	glVertex2i(400, 250);
	glVertex2i(340, 250);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(194/255.f, 186/255.f, 83/255.f);
	glVertex2i(340, 100);
	glVertex2i(400, 100);
	glVertex2i(400, 0);
	glVertex2i(340, 0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(194/255.f, 186/255.f, 205/255.f);
	glVertex2i(339, 100);
	glVertex2i(339, 0);
	glVertex2i(401, 100);
	glVertex2i(401, 0);
	glEnd();

		glBegin(GL_POINTS);
	glColor3f(243/255.f, 164/255.f, 18/255.f);
	glVertex2i(355, 20);
	glEnd();

		glBegin(GL_POINTS);
	glColor3f(243/255.f, 164/255.f, 18/255.f);
	glVertex2i(355, 50);
	glEnd();

		glBegin(GL_POINTS);
	glColor3f(243/255.f, 164/255.f, 18/255.f);
	glVertex2i(355, 80);
	glEnd();

		glBegin(GL_POINTS);
	glColor3f(243/255.f, 164/255.f, 18/255.f);
	glVertex2i(385, 20);
	glEnd();

		glBegin(GL_POINTS);
	glColor3f(243/255.f, 164/255.f, 18/255.f);
	glVertex2i(385, 50);
	glEnd();

		glBegin(GL_POINTS);
	glColor3f(243/255.f, 164/255.f, 18/255.f);
	glVertex2i(385, 80);
	glEnd();

		glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(345, 180);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(218/255.f, 212/255.f, 218/255.f);
	glVertex2i(220, 180);
	glVertex2i(300, 180);
	glVertex2i(300, 240);
	glVertex2i(220, 240);
	glEnd();

    glBegin(GL_LINES);
	glColor3f(1/255.f, 1/255.f, 1/255.f);
	glVertex2i(260, 180);
	glVertex2i(260, 240);
	glVertex2i(220, 210);
	glVertex2i(300, 210);
	glEnd();

    glBegin(GL_LINE_LOOP);
	glColor3f(1/255.f, 1/255.f, 1/255.f);
	glVertex2i(220, 180);
	glVertex2i(300, 180);
	glVertex2i(300, 240);
	glVertex2i(220, 240);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(75/255.f, 40/255.f, 0/255.f);
	glVertex2i(100, 100);
	glVertex2i(150, 100);
	glVertex2i(150, 250);
	glVertex2i(100, 250);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(30/255.f, 123/255.f, 0/255.f);
	glVertex2i(85, 250);
	glVertex2i(165, 250);
	glVertex2i(165, 350);
	glVertex2i(85, 350);
	glEnd();

    glBegin(GL_POINTS);
	glColor3f(254/255.f, 0/255.f, 0/255.f);
	glVertex2i(100, 280);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(254/255.f, 0/255.f, 0/255.f);
	glVertex2i(100, 315);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(254/255.f, 0/255.f, 0/255.f);
	glVertex2i(150, 280);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(254/255.f, 0/255.f, 0/255.f);
	glVertex2i(150, 315);
	glEnd();

		glBegin(GL_POLYGON);
	glColor3f(53/255.f, 0/255.f, 0/255.f);
	glVertex2i(200, 350);
	glVertex2i(250, 350);
	glVertex2i(250, 420);
	glVertex2i(200, 420);
	glEnd();

	    glBegin(GL_LINES);
	glColor3f(1/255.f, 1/255.f, 1/255.f);
	glVertex2i(190, 421);
	glVertex2i(260, 421);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(255/255.f, 255/255.f, 255/255.f);
	glVertex2i(200, 360);
	glVertex2i(250, 360);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(255/255.f, 255/255.f, 255/255.f);
	glVertex2i(200, 380);
	glVertex2i(250, 380);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(255/255.f, 255/255.f, 255/255.f);
	glVertex2i(200, 400);
	glVertex2i(250, 400);
	glEnd();

		glBegin(GL_LINES);
	glColor3f(255/255.f, 255/255.f, 255/255.f);
	glVertex2i(210, 350);
	glVertex2i(210, 420);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(255/255.f, 255/255.f, 255/255.f);
	glVertex2i(225, 350);
	glVertex2i(225, 420);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(255/255.f, 255/255.f, 255/255.f);
	glVertex2i(240, 350);
	glVertex2i(240, 420);
	glEnd();


}

main(int argc, char **argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("RUMAHKU");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
