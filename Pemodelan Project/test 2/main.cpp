#include <windows.h>
#include <gl/glut.h>
#include <stdlib.h>
#include <math.h>


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int,int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);

float xrot =0.0f;
float yrot =0.0f;
float xdiff =0.0f;
float ydiff =0.0f;
bool mouseDown = false;
int is_depth;
float gg=3.0;

int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("Pius Aldi Septio - 672019046");
    init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
	glutReshapeFunc(ukuran);
	glutMotionFunc(mouseMotion);
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void)
{

glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void luar(void)
{

    //jendela 3
      glBegin(GL_QUADS);
    glColor4f(98/255.f, 97/255.f, 255/255.f, 0.5);
    glVertex3f(-13.0, -15.0, 10.0);
    glVertex3f(-3.0, -15.0, 10.0);
    glVertex3f(-3.0, 8.0, 10.0);
    glVertex3f(-13.0, 8.0, 10.0);
    glEnd();

    //depan
      glBegin(GL_POLYGON);
    glColor3f(223/255.f, 215/255.f, 207/255.f);
    glVertex3f(-50.0, -20.0, 10.0);
    glVertex3f(-50.0, 30.0, 10.0);
    glVertex3f(50.0, 30.0, 10.0);
    glVertex3f(50.0, -20.0, 10.0);
    glEnd();

    //kiri
          glBegin(GL_QUADS);
    glColor3f(223/255.f, 215/255.f, 207/255.f);
    glVertex3f(-50.0, -20.0, 10.0);
    glVertex3f(-50.0, 30.0, 10.0);
    glVertex3f(-50.0, 30.0, -200.0);
    glVertex3f(-50.0, -20.0, -200.0);
    glEnd();

        //kanan
          glBegin(GL_QUADS);
    glColor3f(223/255.f, 215/255.f, 207/255.f);
    glVertex3f(50.0, 30.0, 10.0);
    glVertex3f(50.0, -20.0, 10.0);
    glVertex3f(50.0, -20.0, -200.0);
    glVertex3f(50.0, 30.0, -200.0);
    glEnd();

        //belakang
      glBegin(GL_QUADS);
    glColor3f(223/255.f, 215/255.f, 207/255.f);
    glVertex3f(-50.0, -20.0, -200.0);
    glVertex3f(-50.0, 30.0, -200.0);
    glVertex3f(50.0, 30.0, -200.0);
    glVertex3f(50.0, -20.0, -200.0);
    glEnd();

            //atap
      glBegin(GL_QUADS);
    glColor3f(184/255.f, 0/255.f, 0/255.f);
    glVertex3f(-50.0, 30.0, 10.0);
    glVertex3f(50.0, 30.0, 10.0);
    glVertex3f(50.0, 60.0, -105.0);
    glVertex3f(-50.0, 60.0, -105.0);
    glEnd();

                //atap
      glBegin(GL_QUADS);
    glColor3f(184/255.f, 0/255.f, 0/255.f);
    glVertex3f(50.0, 60.0, -105.0);
    glVertex3f(-50.0, 60.0, -105.0);
    glVertex3f(-50.0, 30.0, -200.0);
    glVertex3f(50.0, 30.0, -200.0);
    glEnd();

//jendela atap kiri
      glBegin(GL_QUADS);
    glColor4f(98/255.f, 97/255.f, 255/255.f, 0.5);
    glVertex3f(-50.0, 40.0, -100.0);
    glVertex3f(-50.0, 55.0, -100.0);
    glVertex3f(-50.0, 55.0, -110.0);
    glVertex3f(-50.0, 40.0, -110.0);
    glEnd();

    //sisi atap kiri
    glBegin(GL_POLYGON);
   	glColor3f(235/255.f, 233/255.f, 229/255.f);
	glVertex3f(-50.0, 30.0, 10.0);
	glVertex3f(-50.0, 60.0,-105.0);
	glVertex3f(-50.0, 30.0,-200.0);
	glEnd();

	    //sisi atap kanan
    glBegin(GL_POLYGON);
   	glColor3f(235/255.f, 233/255.f, 229/255.f);
	glVertex3f(50.0, 30.0, 10.0);
	glVertex3f(50.0, 60.0,-105.0);
	glVertex3f(50.0, 30.0,-200.0);
	glEnd();

    //dinding garasi depan
    glBegin(GL_POLYGON);
   	glColor3f(220/255.f, 119/255.f, 7/255.f);
	glVertex3f(-90.0, -20.0,90.0);
	glVertex3f(-90.0, 30.0,90.0);
	glVertex3f(-90.0, 30.0,10.0);
    glVertex3f(-90.0, -20.0,10.0);
	glEnd();

    //dinding garasi depan
    glBegin(GL_POLYGON);
   	glColor3f(117/255.f, 0/255.f, 0/255.f);
	glVertex3f(-90.1, -20.0,90.0);
	glVertex3f(-90.1, 30.0,90.0);
	glVertex3f(-90.1, 30.0,10.0);
    glVertex3f(-90.1, -20.0,10.0);
	glEnd();

	    //dinding garasi depan
    glBegin(GL_POLYGON);
   	glColor3f(197/255.f, 198/255.f, 202/255.f);
	glVertex3f(-89.9, -20.0,90.0);
	glVertex3f(-89.9, 0.0,90.0);
	glVertex3f(-89.9, 0.0,10.0);
    glVertex3f(-89.0, -20.0,10.0);
	glEnd();

    //dinding garasi belakang
    glBegin(GL_POLYGON);
   	glColor3f(220/255.f, 119/255.f, 7/255.f);
	glVertex3f(-90.0, 30.0,10.0);
    glVertex3f(-90.0, -20.0,10.0);
    glVertex3f(-80.0, -20.0,-160.0);
	glVertex3f(-80.0, 30.0,-160.0);
	glEnd();

    //dinding garasi belakang
    glBegin(GL_POLYGON);
   	glColor3f(117/255.f, 0/255.f, 0/255.f);
	glVertex3f(-90.1, 30.0,10.0);
    glVertex3f(-90.1, -20.0,10.0);
    glVertex3f(-80.1, -20.0,-160.0);
	glVertex3f(-80.1, 30.0,-160.0);
	glEnd();

	    //garasi atap
    glBegin(GL_POLYGON);
   	glColor3f(117/255.f, 0/255.f, 0/255.f);
	glVertex3f(-100.0, 30.0,90.0);
    glVertex3f(-50.0, 30.0,90.0);
    glVertex3f(-50.0, 30.0,-160.0);
	glVertex3f(-90.0, 30.0,-160.0);
	glEnd();

	    //lantai teras
    glBegin(GL_POLYGON);
   	glColor3f(231/255.f, 229/255.f, 226/255.f);
	glVertex3f(-90.0, -20.0,90.0);
	glVertex3f(50.0,-20.0,90.0);
	glVertex3f(50.0,-20.0,10.0);
    glVertex3f(-90.0, -20.0,10.0);
	glEnd();

	    //lantai rumah
    glBegin(GL_POLYGON);
   	glColor3f(82/255.f, 75/255.f, 73/255.f);
	glVertex3f(-90.0, -20.0,10.0);
	glVertex3f(50.0,-20.0,10.0);
	glVertex3f(50.0,-20.0,-200.0);
    glVertex3f(-80.0, -20.0,-200.0);
	glEnd();

	    //dinding depan garasi
    glBegin(GL_POLYGON);
   	glColor3f(220/255.f, 119/255.f, 7/255.f);
	glVertex3f(-90.0, -20.0,30.0);
	glVertex3f(-50.0,-20.0,30.0);
	glVertex3f(-50.0,30.0,30.0);
    glVertex3f(-90.0, 30.0,30.0);
	glEnd();

		    //dinding depan garasi
    glBegin(GL_POLYGON);
   	glColor3f(197/255.f, 198/255.f, 202/255.f);
	glVertex3f(-90.0, -20.0,30.1);
	glVertex3f(-50.0,-20.0,30.1);
	glVertex3f(-50.0,0.0,30.1);
    glVertex3f(-90.0, 0.0,30.1);
	glEnd();

	    //atap teras atas
    glBegin(GL_POLYGON);
   	glColor3f(0/255.f, 0/255.f, 255/255.f);
	glVertex3f(-50.0, 30.0,30.0);
	glVertex3f(50.0,30.0,30.0);
	glVertex3f(50.0,30.0,10.0);
    glVertex3f(-50.0, 30.0,10.0);
	glEnd();

		    //atap teras depan
    glBegin(GL_POLYGON);
   	glColor3f(0/255.f, 0/255.f, 255/255.f);
	glVertex3f(-50.0, 30.0,30.0);
	glVertex3f(50.0,30.0,30.0);
	glVertex3f(50.0,20.0,30.0);
    glVertex3f(-50.0, 20.0,30.0);
	glEnd();

	    //atap teras bawah
    glBegin(GL_POLYGON);
   	glColor3f(0/255.f, 0/255.f, 255/255.f);
	glVertex3f(-50.0, 20.0,30.0);
	glVertex3f(50.0,20.0,30.0);
	glVertex3f(50.0,20.0,10.0);
    glVertex3f(-50.0, 20.0,10.0);
	glEnd();

		    //atap teras kiri
    glBegin(GL_POLYGON);
   	glColor3f(0/255.f, 0/255.f, 255/255.f);
	glVertex3f(-50.0, 30.0,30.0);
	glVertex3f(-50.0,20.0,30.0);
	glVertex3f(-50.0,20.0,10.0);
    glVertex3f(-50.0, 30.0,10.0);
	glEnd();

		    //atap teras kanan
    glBegin(GL_POLYGON);
   	glColor3f(0/255.f, 0/255.f, 255/255.f);
	glVertex3f(50.0, 30.0,30.0);
	glVertex3f(50.0,20.0,30.0);
	glVertex3f(50.0,20.0,10.0);
    glVertex3f(50.0, 30.0,10.0);
	glEnd();

		    //tiang depan garasi
		    glLineWidth(10.0f);
    glBegin(GL_LINES);
   	glColor3f(82/255.f, 75/255.f, 73/255.f);
	glVertex3f(-50.0, -20.0,90.0);
    glVertex3f(-50.0, 30.0,90.0);
	glEnd();

	    //dinding luar kanan
    glBegin(GL_POLYGON);
   	glColor3f(243/255.f, 247/255.f, 238/255.f);
	glVertex3f(50.0, -20.0,90.0);
	glVertex3f(50.0, 2.0,90.0);
	glVertex3f(50.0, 2.0,10.0);
    glVertex3f(50.0, -20.0,10.0);
	glEnd();

			    //tiang depan garasi
		    glLineWidth(10.0f);
    glBegin(GL_LINES);
   	glColor3f(82/255.f, 75/255.f, 73/255.f);
	glVertex3f(50.0, -20.0,90.0);
    glVertex3f(50.0, 34.0,90.0);
	glEnd();

    //kiri rumah belakang
          glBegin(GL_QUADS);
    glColor3f(82/255.f, 75/255.f, 73/255.f);
    glVertex3f(-50.0, -20.0, -200.0);
    glVertex3f(-50.0, 90.0, -200.0);
    glVertex3f(-50.0, 90.0, -300.0);
    glVertex3f(-50.0, -20.0, -300.0);
    glEnd();

        //kanan rumah belakang
          glBegin(GL_QUADS);
    glColor3f(82/255.f, 75/255.f, 73/255.f);
    glVertex3f(50.0, 90.0, -200.0);
    glVertex3f(50.0, -20.0, -200.0);
    glVertex3f(50.0, -20.0, -300.0);
    glVertex3f(50.0, 90.0, -300.0);
    glEnd();

        //depan rumah belakang
      glBegin(GL_QUADS);
    glColor3f(82/255.f, 75/255.f, 73/255.f);
    glVertex3f(-50.0, -20.0, -200.0);
    glVertex3f(-50.0, 90.0, -200.0);
    glVertex3f(50.0, 90.0, -200.0);
    glVertex3f(50.0, -20.0, -200.0);
    glEnd();

            //belakang rumah belakang
      glBegin(GL_QUADS);
    glColor3f(82/255.f, 75/255.f, 73/255.f);
    glVertex3f(-50.0, -20.0, -300.0);
    glVertex3f(-50.0, 90.0, -300.0);
    glVertex3f(50.0, 90.0, -300.0);
    glVertex3f(50.0, -20.0, -300.0);
    glEnd();

                //atap belakang rumah
      glBegin(GL_QUADS);
    glColor3f(184/255.f, 0/255.f, 0/255.f);
    glVertex3f(-50.0, 90.0, -200.0);
    glVertex3f(50.0, 90.0, -200.0);
    glVertex3f(50.0, 120.0, -250.0);
    glVertex3f(-50.0, 120.0, -250.0);
    glEnd();

                //atap belakang rumah
      glBegin(GL_QUADS);
    glColor3f(184/255.f, 0/255.f, 0/255.f);
    glVertex3f(50.0, 120.0, -250.0);
    glVertex3f(-50.0, 120.0, -250.0);
    glVertex3f(-50.0, 90.0, -300.0);
    glVertex3f(50.0, 90.0, -300.0);
    glEnd();
}

void jenpin(void)
{

                //gagang
    glLineWidth(5.0f);
       glBegin(GL_LINES);
    glColor4f(0/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-27.0, -5.0, 10.0);
    glVertex3f(-25.0, -5.0, 10.0);
    glEnd();

    //pintu depan 1
      glBegin(GL_QUADS);
    glColor3f(98/255.f, 97/255.f, 95/255.f);
    glVertex3f(-28.0, -20.0, 10.0);
    glVertex3f(-15.0, -20.0, 10.0);
    glVertex3f(-15.0, 10.0, 10.0);
    glVertex3f(-28.0, 10.0, 10.0);
    glEnd();

            //kerangka jendela
    glLineWidth(5.0f);
       glBegin(GL_LINES);
    glColor4f(0/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-39.0, -8.0, 10.0);
    glVertex3f(-29.0, -8.0, 10.0);
    glVertex3f(-39.0, 1.0, 10.0);
    glVertex3f(-29.0, 1.0, 10.0);
    glVertex3f(-34.0, -15.0, 10.0);
    glVertex3f(-34.0, 8.0, 10.0);
    glEnd();

                        //jendela 4

      glBegin(GL_QUADS);
    glColor4f(98/255.f, 97/255.f, 255/255.f, 0.5);
    glVertex3f(-39.0, -15.0, 10.0);
    glVertex3f(-29.0, -15.0, 10.0);
    glVertex3f(-29.0, 8.0, 10.0);
    glVertex3f(-39.0, 8.0, 10.0);
    glEnd();

        //kerangka jendela
    glLineWidth(5.0f);
       glBegin(GL_LINES);
    glColor4f(0/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-40.0, -8.0, 10.0);
    glVertex3f(-49.0, -8.0, 10.0);
    glVertex3f(-49.0, 1.0, 10.0);
    glVertex3f(-40.0, 1.0, 10.0);
    glVertex3f(-44.5, -15.0, 10.0);
    glVertex3f(-44.5, 8.0, 10.0);
    glEnd();

                            //jendela 5

      glBegin(GL_QUADS);
    glColor4f(98/255.f, 97/255.f, 255/255.f, 0.5);
    glVertex3f(-40.0, -15.0, 10.0);
    glVertex3f(-49.0, -15.0, 10.0);
    glVertex3f(-49.0, 8.0, 10.0);
    glVertex3f(-40.0, 8.0, 10.0);
    glEnd();



        //pintu depan garis
        glLineWidth(2.0f);
      glBegin(GL_LINES);
    glColor3f(0/255.f, 0/255.f, 0/255.f);
    glVertex3f(30.0, -20.0, 10.0);
    glVertex3f(30.0, 10.0, 10.0);
    glEnd();

                //gagang
    glLineWidth(5.0f);
       glBegin(GL_LINES);
    glColor4f(0/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-27.0, -5.0, 10.0);
    glVertex3f(-25.0, -5.0, 10.0);
    glEnd();

                //gagang
    glLineWidth(5.0f);
       glBegin(GL_LINES);
    glColor4f(0/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(28.0, -8.0, 10.0);
    glVertex3f(28.0, -3.0, 10.0);
    glVertex3f(32.0, -8.0, 10.0);
    glVertex3f(32.0, -3.0, 10.0);
    glEnd();
        //pintu depan 2
      glBegin(GL_QUADS);
    glColor3f(98/255.f, 97/255.f, 95/255.f);
    glVertex3f(20.0, -20.0, 10.0);
    glVertex3f(40.0, -20.0, 10.0);
    glVertex3f(40.0, 10.0, 10.0);
    glVertex3f(20.0, 10.0, 10.0);
    glEnd();

            //kerangka jendela
    glLineWidth(5.0f);
       glBegin(GL_LINES);
    glColor4f(0/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(9.0, -8.0, 10.0);
    glVertex3f(19.0, -8.0, 10.0);
    glVertex3f(9.0, 1.0, 10.0);
    glVertex3f(19.0, 1.0, 10.0);
    glVertex3f(14.0, -15.0, 10.0);
    glVertex3f(14.0, 8.0, 10.0);
    glEnd();

            //jendela
      glBegin(GL_QUADS);
    glColor4f(98/255.f, 97/255.f, 255/255.f, 0.5);
    glVertex3f(9.0, -15.0, 10.0);
    glVertex3f(19.0, -15.0, 10.0);
    glVertex3f(19.0, 8.0, 10.0);
    glVertex3f(9.0, 8.0, 10.0);
    glEnd();


            //kerangka jendela
    glLineWidth(5.0f);
       glBegin(GL_LINES);
    glColor4f(0/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-2.0, -8.0, 10.0);
    glVertex3f(8.0, -8.0, 10.0);
    glVertex3f(-2.0, 1.0, 10.0);
    glVertex3f(8.0, 1.0, 10.0);
    glVertex3f(3.0, -15.0, 10.0);
    glVertex3f(3.0, 8.0, 10.0);
    glEnd();
                //jendela 2
          glBegin(GL_QUADS);
    glColor4f(98/255.f, 97/255.f, 255/255.f, 0.5);
    glVertex3f(-2.0, -15.0, 10.0);
    glVertex3f(8.0, -15.0, 10.0);
    glVertex3f(8.0, 8.0, 10.0);
    glVertex3f(-2.0, 8.0, 10.0);
    glEnd();

            //kerangka jendela
    glLineWidth(5.0f);
       glBegin(GL_LINES);
    glColor4f(0/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-13.0, -8.0, 10.0);
    glVertex3f(-3.0, -8.0, 10.0);
    glVertex3f(-13.0, 1.0, 10.0);
    glVertex3f(-3.0, 1.0, 10.0);
    glVertex3f(-8.0, -15.0, 10.0);
    glVertex3f(-8.0, 8.0, 10.0);
    glEnd();



}

void lemari(void)
{
  //lemari belakang
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-45.0, -20.0,5.0);
    glVertex3f(-45.0, 20.0, 5.0);
    glVertex3f(-45.0, 20.0, -15.0);
    glVertex3f(-45.0, -20.0, -15.0);
    glEnd();

     //lemari samping
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-45.0, -20.0,5.0);
    glVertex3f(-45.0, 20.0, 5.0);
    glVertex3f(-35.0, 20.0, 5.0);
    glVertex3f(-35.0, -20.0,5.0);
    glEnd();

         //lemari samping belakang
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-45.0, -20.0,-15.0);
    glVertex3f(-45.0, 20.0, -15.0);
    glVertex3f(-35.0, 20.0, -15.0);
    glVertex3f(-35.0, -20.0,-15.0);
    glEnd();

 //lemari atas
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-45.0, 20.0,5.0);
    glVertex3f(-35.0, 20.0, 5.0);
    glVertex3f(-35.0, 20.0, -15.0);
    glVertex3f(-45.0, 20.0, -15.0);
    glEnd();

     //lemari depan
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-35.0, -20.0,5.0);
    glVertex3f(-35.0, 20.0, 5.0);
    glVertex3f(-35.0, 20.0, -15.0);
    glVertex3f(-35.0, -20.0, -15.0);
    glEnd();

        //lemari garis
        glLineWidth(2.0f);
      glBegin(GL_LINES);
    glColor3f(0/255.f, 0/255.f, 0/255.f);
    glVertex3f(-35.0, -20.0, -5.0);
    glVertex3f(-35.0, 20.0, -5.0);
    glEnd();

    //gagang lemari
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glColor3f(0/255.f, 0/255.f, 0/255.f);
    glVertex3f(-35.0, 0.0, -3.0);
    glVertex3f(-35.0, 0.0, -8.0);
    glEnd();
}

void kursi(void)
{
        //atas kursi
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-3.0, -12.0,-18.0);
    glVertex3f(8.0, -12.0,-18.0);
    glVertex3f(8.0, -12.0, -25.0);
    glVertex3f(-3.0, -12.0, -25.0);
    glEnd();

            //sandaran kursi
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(8.0, -12.0, -25.0);
    glVertex3f(-3.0, -12.0, -25.0);
    glVertex3f(-3.0, 5.0,-25.0);
    glVertex3f(8.0, 5.0,-25.0);
    glEnd();

            //sandaran kursi
      glBegin(GL_QUADS);
    glColor4f(135/255.f, 122/255.f, 137/255.f, 1.0);
    glVertex3f(6.0, -10.0, -24.9);
    glVertex3f(-1.0, -10.0, -24.9);
    glVertex3f(-1.0, 3.0,-24.9);
    glVertex3f(6.0, 3.0,-24.9);
    glEnd();

            //kaki kursi
      glBegin(GL_LINES);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-2.0, -12.0,-19.0);
    glVertex3f(-2.0, -20.0,-19.0);
    glVertex3f(-2.0, -12.0,-24.0);
    glVertex3f(-2.0, -20.0,-24.0);
    glVertex3f(7.0, -12.0,-19.0);
    glVertex3f(7.0, -20.0,-19.0);
    glVertex3f(7.0, -12.0,-24.0);
    glVertex3f(7.0, -20.0,-24.0);
    glEnd();
}

void meja(void)
{
        //atas meja
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-10.0, -5.0,5.0);
    glVertex3f(15.0, -5.0, 5.0);
    glVertex3f(15.0, -5.0, -15.0);
    glVertex3f(-10.0, -5.0, -15.0);
    glEnd();

            //kaki 1
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(-5.0, -5.0,5.0);
    glVertex3f(-5.0, -20.0, 5.0);
    glVertex3f(-5.0, -20.0, -15.0);
    glVertex3f(-5.0, -5.0, -15.0);
    glEnd();

            //kaki 2
      glBegin(GL_QUADS);
    glColor4f(50/255.f, 0/255.f, 0/255.f, 1.0);
    glVertex3f(10.0, -5.0,5.0);
    glVertex3f(10.0, -20.0, 5.0);
    glVertex3f(10.0, -20.0, -15.0);
    glVertex3f(10.0, -5.0, -15.0);
    glEnd();
}

void tidur(void)
{

        //selimut
      glBegin(GL_QUADS);
    glColor4f(235/255.f, 159/255.f, 142/255.f, 1.0);
    glVertex3f(-35.0, -14.9,-20.0);
    glVertex3f(-35.0, -14.9, -45.0);
    glVertex3f(-15.0, -14.9, -45.0);
    glVertex3f(-15.0, -14.9, -20.0);
    glEnd();

        //bantal
      glBegin(GL_QUADS);
    glColor4f(235/255.f, 159/255.f, 142/255.f, 1.0);
    glVertex3f(-43.0, -14.9,-28.0);
    glVertex3f(-43.0, -14.9, -38.0);
    glVertex3f(-38.0, -14.9, -38.0);
    glVertex3f(-38.0, -14.9, -28.0);
    glEnd();

        //tempat tidur bawah
      glBegin(GL_QUADS);
    glColor4f(85/255.f, 75/255.f, 255/255.f, 1.0);
    glVertex3f(-45.0, -19.9,-20.0);
    glVertex3f(-45.0, -19.9, -45.0);
    glVertex3f(-15.0, -19.9, -45.0);
    glVertex3f(-15.0, -19.9, -20.0);
    glEnd();

        //tempat tidur atas
      glBegin(GL_QUADS);
    glColor4f(85/255.f, 75/255.f, 255/255.f, 1.0);
    glVertex3f(-45.0, -15.0,-20.0);
    glVertex3f(-45.0, -15.0, -45.0);
    glVertex3f(-15.0, -15.0, -45.0);
    glVertex3f(-15.0, -15.0, -20.0);
    glEnd();

        //tempat tidur depan
      glBegin(GL_QUADS);
    glColor4f(85/255.f, 75/255.f, 255/255.f, 1.0);
    glVertex3f(-45.0, -20.0,-20.0);
    glVertex3f(-45.0, -15.0, -20.0);
    glVertex3f(-15.0, -15.0, -20.0);
    glVertex3f(-15.0, -20.0, -20.0);
    glEnd();

            //tempat tidur belakang
      glBegin(GL_QUADS);
    glColor4f(85/255.f, 75/255.f, 255/255.f, 1.0);
    glVertex3f(-45.0, -20.0,-45.0);
    glVertex3f(-45.0, -15.0, -45.0);
    glVertex3f(-15.0, -15.0, -45.0);
    glVertex3f(-15.0, -20.0, -45.0);
    glEnd();

                //tempat tidur samping
      glBegin(GL_QUADS);
    glColor4f(85/255.f, 75/255.f, 255/255.f, 1.0);
    glVertex3f(-15.0, -20.0,-45.0);
    glVertex3f(-15.0, -15.0, -45.0);
    glVertex3f(-15.0, -15.0, -20.0);
    glVertex3f(-15.0, -20.0, -20.0);
    glEnd();

                //tempat tidur samping
      glBegin(GL_QUADS);
    glColor4f(85/255.f, 75/255.f, 255/255.f, 1.0);
    glVertex3f(-45.0, -20.0,-45.0);
    glVertex3f(-45.0, -15.0, -45.0);
    glVertex3f(-45.0, -15.0, -20.0);
    glVertex3f(-45.0, -20.0, -20.0);
    glEnd();


}

void furni(void)
{
lemari();
meja();
tidur();
kursi();
}

void ngon(int n, float cx, float cy, float radius, float rotAngle){
    double angle, angleInc;
    int k;
    if(n<3) return;
    angle=rotAngle*3.14159265/180;
    angleInc=2*3.14159265/n;

    for(k=70;k<n;k++){
        angle+=angleInc;
        glColor3f(234/255.f, 35/255.f, 36/255.f);
        glVertex3f(radius*cos(angle)+cx, radius*sin(angle)+cy,-10.0);
        glVertex3f(radius*cos(angle)+cx, radius*sin(angle)+cy,-90.0);
    }
}




void tampil(void)
{
        if(is_depth)
        {glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
    else
        {glClear(GL_COLOR_BUFFER_BIT);}

glDisable(GL_LIGHTING);

    glPushMatrix();
    furni();
jenpin();
luar();

glRotatef(180.0,0.0,0.0,0.0);
glBegin(GL_QUAD_STRIP);
ngon(100,0,6,63,216);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
        glLoadIdentity();
    gluLookAt(0.0f,0.0f, gg, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    }
}

void keyboard(unsigned char key, int x, int y)
{
switch (key)
{
case 'w':
case 'W':
    glTranslatef(0.0,0.0,3.0);
    break;
    //atur kamera zoom
case '+':
case '=':
    gg=gg-3.0;
    glTranslatef(0.0,0.0,3.0);
    break;
    //atur kamera zoom
case '-':
case '_':
    gg=gg+3.0;
    glTranslatef(0.0,0.0,-3.0);
    break;
    case ']':
case '}':
    gg=gg-3.0;
    glTranslatef(0.0,0.0,-3.0);
    break;
    //atur kamera zoom
case '{':
case '[':
    gg=gg+3.0;
    glTranslatef(0.0,0.0,3.0);
    break;
    case 'd':
case 'D':
    glTranslatef(3.0,0.0,0.0);
    break;
    case 's':
case 'S':
    glTranslatef(0.0,0.0,-3.0);
    break;
    case 'a':
case 'A':
    glTranslatef(-3.0,0.0,0.0);
    break;
    case '7':
    glTranslatef(0.0,3.0,0.0);
    break;

    case '9':
    glTranslatef(0.0,-3.0,0.0);
    break;

    case '2':
    glRotatef(2.0,1.0,0.0,0.0);
    break;
    case '8':
    glRotatef(-2.0,1.0,0.0,0.0);
    break;
    case '6':
    glRotatef(2.0,0.0,1.0,0.0);
    break;
    case '4':
    glRotatef(-2.0,0.0,1.0,0.0);
    break;
    case '1':
    glRotatef(2.0,0.0,0.0,1.0);
    break;
    case '3':
    glRotatef(-2.0,0.0,0.0,1.0);
    break;
    case '5':
        if (is_depth)
        {
            is_depth =0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
}
tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, lebar / tinggi, 50.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
