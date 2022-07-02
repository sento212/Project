#include <gl/glut.h>
#define RATIO 1.200

#define WW 100
#define WH (WW/RATIO)
#define HALFX ((int)(WW/2))
#define HALFY ((int)(WH/2))
#define deltat .001

int WindowWidth;
int WindowHeight;

void Display(){
glLineWidth(4.0);
float StartShape[9][2] ={
{-10,-15},{-10,15},{-5,20},{10,20},{15,15},{15,5},{10,0},{-5,0},{-5,-15}
};

float StartShape1[4][2] ={
{-5,5},{-5,15},{10,15},{10,5}
};

float EndShape[9][2] ={
{-10,-15},{-10,19.9},{10,20},{10,15},{-5,15},{-5,5},{10,5},{10,-15},{10,-15}
};

float EndShape1[4][2] ={
{-5,-10},{-5,0},{5,0},{5,-10}
};

float IntermediateShape[9][2];
float IntermediateShape1[4][2];

float VertexColors[9][3]{
{1,0,0},{1,1,0},{1,0,1},{0,1,0},{0,1,1},{0,0,1},{1,0.5,0},{1,0,0.5},{0.5,0,1}
};

float VertexColors1[4][3]{
{0.5,0,1},{1,0,0.5},{0,1,0.5},{0,1,1}
};

static float Tween = 0.0 - deltat;

if (Tween<1)
{
    Tween += deltat;
}

for (int Vtx = 0; Vtx<9; Vtx++)
{
    IntermediateShape[Vtx][0] = (1.0 - Tween)*StartShape[Vtx][0] + Tween*EndShape[Vtx][0];
    IntermediateShape[Vtx][1] = (1.0 - Tween)*StartShape[Vtx][1] + Tween*EndShape[Vtx][1];
}

for (int Vtx1 = 0; Vtx1<4; Vtx1++)
{
    IntermediateShape1[Vtx1][0] = (1.0 - Tween)*StartShape1[Vtx1][0] + Tween*EndShape1[Vtx1][0];
    IntermediateShape1[Vtx1][1] = (1.0 - Tween)*StartShape1[Vtx1][1] + Tween*EndShape1[Vtx1][1];
}

for (int i = 0; i <100000; i++);
    glClear(GL_COLOR_BUFFER_BIT);
    glVertexPointer(2, GL_FLOAT, 0, IntermediateShape);
    glColorPointer(3, GL_FLOAT, 0, VertexColors);
    glDrawArrays(GL_LINE_LOOP,0,9);
    glVertexPointer(2, GL_FLOAT, 0, IntermediateShape1);
    glColorPointer(3, GL_FLOAT, 0, VertexColors1);
    glDrawArrays(GL_LINE_LOOP,0,4);
    glutSwapBuffers();
    glutPostRedisplay();

}

void InitGL(){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-HALFX, HALFX, -HALFY, HALFY);
glMatrixMode(GL_MODELVIEW);
glClearColor(0,0,0,0);

glEnableClientState(GL_VERTEX_ARRAY);

glEnableClientState(GL_COLOR_ARRAY);
glShadeModel(GL_SMOOTH);
glViewport(0,0, WindowWidth, WindowHeight);
}

void Reshape(int w, int h)
{
    glutReshapeWindow(w, (int)(w/RATIO));
    WindowWidth = w;
    WindowHeight= (int)(w/RATIO);
    InitGL;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    WindowWidth = (int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.4);
    WindowHeight = (int)(WindowWidth/ RATIO);

    glutInitWindowSize(WindowWidth,WindowHeight);
    glutInitWindowPosition((int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.1),(glutGet((GLenum)GLUT_SCREEN_HEIGHT)/2)-(WindowHeight));

    glutCreateWindow("Pius Aldi Septio - 672019046");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    InitGL();
    glutMainLoop();
}
