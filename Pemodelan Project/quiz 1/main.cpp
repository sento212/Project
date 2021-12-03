#include <windows.h>
#include <gl/glut.h>
#include <stdlib.h>
#include <math.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

int is_depth;
float xrot = 0.0f;
float yrot = 0.0f;
float zrot = 0.0f;
float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
//deklarasi pembuatan lingkaran
const double PI = 3.142857143;
int i, radius, jumlah_titik, x_tengah, y_tengah,n;
float angle = 0;
//deklarasi gerakan otomatis
int gerak = 0;
bool atas = true;

//db : depan-belakang
//kk : kiri-kanan
//ab : atas-bawah

void db(float xkiri, float xkanan, float ybawah, float yatas, float z) {
    glBegin(GL_QUADS);
    glVertex3f(xkiri, ybawah, z);
    glVertex3f(xkiri, yatas, z);
    glVertex3f(xkanan, yatas, z);
    glVertex3f(xkanan, ybawah, z);
    glEnd();
}

void db2(float xkiri, float xkiri2, float xkanan, float xkanan2, float ybawah, float yatas, float z) {
    glBegin(GL_QUADS);
    glVertex3f(xkiri, ybawah, z);
    glVertex3f(xkiri2, yatas, z);
    glVertex3f(xkanan2, yatas, z);
    glVertex3f(xkanan, ybawah, z);
    glEnd();
}

void bingkai(float xkiri, float xkanan, float ybawah, float yatas, float z) {
    glBegin(GL_LINE_LOOP);
    glVertex3f(xkiri, ybawah, z);
    glVertex3f(xkiri, yatas, z);
    glVertex3f(xkanan, yatas, z);
    glVertex3f(xkanan, ybawah, z);
    glEnd();
}

void kk(float xsisi, float ybawah, float yatas, float zdepan, float zbelakang) {
    glBegin(GL_QUADS);
    glVertex3f(xsisi, ybawah, zdepan);
    glVertex3f(xsisi, yatas, zdepan);
    glVertex3f(xsisi, yatas, zbelakang);
    glVertex3f(xsisi, ybawah, zbelakang);
    glEnd();
}

void kk2(float xsisi1, float xsisi2, float ybawah, float yatas, float zdepan, float zbelakang) {
    glBegin(GL_QUADS);
    glVertex3f(xsisi1, ybawah, zdepan);
    glVertex3f(xsisi1, yatas, zdepan);
    glVertex3f(xsisi2, yatas, zbelakang);
    glVertex3f(xsisi2, ybawah, zbelakang);
    glEnd();
}

void ab(float xkiri, float xkanan, float y, float zdepan, float zbelakang) {
    glBegin(GL_QUADS);
    glVertex3f(xkiri, y, zdepan);
    glVertex3f(xkanan, y, zdepan);
    glVertex3f(xkanan, y, zbelakang);
    glVertex3f(xkiri, y, zbelakang);
    glEnd();
}

void lingkaran(int radius, int n_titik, int x_tgh, int y_tgh, float z)
{
    glBegin(GL_POLYGON);
    for (i = 0; i <= 360; i++) {
        float angle = i * (2 * PI / n_titik);
        float x = x_tgh + radius * cos(angle);
        float y = y_tgh + radius * sin(angle);
        glVertex3f(x, y, z);
        glColor3f(0.8, 0.4, 0.4);
    }
    glEnd();
}

//jarum jam
void jarumjam()
{
    glBegin(GL_POLYGON);
    glColor3f(0.54, 0, 0);
    glVertex3f(0, -14, -137.3);
    glVertex3f(0.5, -20, -137.3);
    glVertex3f(-0.5, -20, -137.3);
    glEnd();
}

//jarum menit
void jarummenit()
{
    glBegin(GL_POLYGON);
    glColor3f(0.28, 0.24, 0.55);
    glVertex3f(0, -12, -137.4);
    glVertex3f(0.5, -20, -137.4);
    glVertex3f(-0.5, -20, -137.4);
    glEnd();
}

//jarum detik
void jarumdetik()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0, -11, -137.2);
    glVertex3f(0.3, -20, -137.2);
    glVertex3f(-0.3, -20, -137.2);
    glEnd();
}

void jam() {
    glPushMatrix();

    //kotak
    glColor3f(0.0, 0.0, 0.0);
    db(-9.5, 9.5, -29.5, -9.5, -137.48);        //depan
    db(-9.5, 9.5, -29.5, -9.5, -139.9);        //belakang
    kk(-9.5, -29.5, -9.5, -137.48, -139.9);     //kiri
    kk(9.5, -29.5, -9.5, -137.48, -139.9);     //kanan
    ab(-9.5, 9.5, -9.5, -137.48, -139.9);       //atas
    ab(-9.5, 9.5, -29.5, -137.48, -139.9);       //bawah

    //badan jam
    glColor3f(0.8, 0.8, 0.8);
    lingkaran(9, 50, 0, -20, -137.5);
    glPopMatrix();

    //jarum menit
    glPushMatrix();
    glRotatef(angle / 60, 0, 0.2, 1.4);
    jarummenit();
    glPopMatrix();

    //jarum jam
    glPushMatrix();
    glRotatef(angle / 720, 0, 0.2, 1.4);
    jarumjam();
    glPopMatrix();

    //jarum detik
    glPushMatrix();
    glRotatef(angle, 0, 0.2, 1.4);
    jarumdetik();
    glPopMatrix();

    //pusat tengah
    lingkaran(1.5, 50, 0, -20, -137.51);

    glFlush();
}

void bangunan_kiri_depan() {
    //bangunan kiri atas
    glColor3f(0.85, 0.76, 0.67);
    //depan
    glBegin(GL_QUADS);
    glVertex3f(-165, -10, 0);
    glVertex3f(-170, 2, 5);
    glVertex3f(50, 2, 5);
    glVertex3f(50, -10, 0);
    glEnd();
    //depan2
    glColor3f(0.85, 0.76, 0.67);
    glBegin(GL_QUADS);
    glVertex3f(-157, -10, -8);
    glVertex3f(-157, 2, -8);
    glVertex3f(50, 2, -8);
    glVertex3f(50, -10, -8);
    glEnd();
    //atas
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-157, 2, -8);
    glVertex3f(-170, 2, 5);
    glVertex3f(50, 2, 5);
    glVertex3f(50, 2, -8);
    glEnd();

    //kiri
    glColor3f(0.85, 0.76, 0.67);
    glBegin(GL_QUADS);
    glVertex3f(-165, -10.0, 0.0);
    glVertex3f(-170, 2.0, 5.0);
    glVertex3f(-170, 2.0, -145);
    glVertex3f(-165, -10.0, -140);
    glEnd();
    //kiri2
    glColor3f(0.85, 0.76, 0.67);
    glBegin(GL_QUADS);
    glVertex3f(-157, -10.0, -8.0);
    glVertex3f(-157, 2.0, -8.0);
    glVertex3f(-157, 2.0, -132);
    glVertex3f(-157, -10.0, -132);
    glEnd();
    //atas
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-157, 2.0, 0.0);
    glVertex3f(-170, 2.0, 5.0);
    glVertex3f(-170, 2.0, -145);
    glVertex3f(-157, 2.0, -132);
    glEnd();

    //belakang
    glColor3f(0.85, 0.76, 0.67);
    glBegin(GL_QUADS);
    glVertex3f(-165, -10, -140);
    glVertex3f(-170, 2, -145);
    glVertex3f(50, 2, -145);
    glVertex3f(50, -10, -140);
    glEnd();
    //belakang2
    glColor3f(0.85, 0.76, 0.67);
    glBegin(GL_QUADS);
    glVertex3f(-157, -10, -132);
    glVertex3f(-157, 2, -132);
    glVertex3f(50, 2, -132);
    glVertex3f(50, -10, -132);
    glEnd();
    //atas
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-157, 2, -132);
    glVertex3f(-170, 2, -145);
    glVertex3f(50, 2, -145);
    glVertex3f(50, 2, -132);
    glEnd();

    //ATAP
    glColor3f(0.6, 0.6, 0.7);
    //depan
    glBegin(GL_QUADS);
    glVertex3f(-157, -10, -8);
    glVertex3f(-107, 33, -70);
    glVertex3f(0, 33, -70);
    glVertex3f(50, -10, -8);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glVertex3f(-157, -10, -132);
    glVertex3f(-107, 33, -70);
    glVertex3f(0, 33, -70);
    glVertex3f(50, -10, -132);
    glEnd();
    //kiri
    glColor3f(0.5, 0.5, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-157, -10, -8);
    glVertex3f(-107, 33, -70);
    glVertex3f(-157, -10, -132);
    glEnd();
    //kanan
    glColor3f(0.5, 0.5, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(50, -10, -8);
    glVertex3f(0, 33, -70);
    glVertex3f(50, -10, -132);
    glEnd();

    //bangunan kiri tengah
    glColor3f(0.85, 0.76, 0.67);
    //depan
    db(-165.0, 50.0, -35.0, -10.0, 0.0);
    glColor3f(0.6, 0.5, 0.4);
    db(-165.0, 50.0, -33.0, -35.0, 1.0);


    //bangunan kiri bawah
    glColor3f(0.85, 0.76, 0.67);
    //depan
    db(-165.0, 50.0, -165.0, -10.0, 0.0);
    //belakang
    glColor3f(0.85, 0.76, 0.67);
    //glColor3f(1.0, 0.0, 0.0);
    db(-165.0, 50.0, -165.0, -10.0, -140.0);

    glColor3f(0.85, 0.76, 0.67);
    //kiri
    kk(-165.0, -165.0, -10.0, 0.0, -140.0);
    //kanan
    kk(50.0, -165.0, -10.0, 0.0, -140.0);

    //atas
    //ab(-145.0, 50.0, -5.0, 0.0, -135.0);
    //bawah
    ab(-165.0, 50.0, -165.0, 0.0, -140.0);

    //jendela
    glColor3f(0.2, 0.2, 0.2);
    //1
    db(-147, -113, -150.0, -45.0, 0.1);
    //bingkai utama
    glColor3f(0.85, 0.76, 0.67);
    bingkai(-147, -113, -150.0, -45.0, 0.3);

    //TAMBAHAN
    glColor3f(0.6, 0.5, 0.4);
    db(-140, -132.0, -160.0, -156.0, 0.1);
    db(-129, -121.0, -160.0, -156.0, 0.1);

    //bingkai
    glColor3f(0.85, 0.76, 0.67);
    db(-131, -129, -150.0, -45.0, 0.5);     //vertical
    db(-139.5, -138.5, -150.0, -45.0, 0.5); //kiri
    db(-121.5, -120.5, -150.0, -45.0, 0.5); //kanan

    db(-147, -131, -67, -65, 0.5); //horizontal -1
    db(-147, -131, -88, -86, 0.5); //2
    db(-147, -131, -107, -105, 0.5); //3
    db(-147, -131, -128, -126, 0.5); //4

    db(-129, -113, -67, -65, 0.5); //horizontal -1
    db(-129, -113, -88, -86, 0.5); //2
    db(-129, -113, -107, -105, 0.5); //3
    db(-129, -113, -128, -126, 0.5); //4

    //2
    glColor3f(0.2, 0.2, 0.2);
    db(-97, -63, -150.0, -45.0, 0.1);
    //bingkai utama
    glColor3f(0.85, 0.76, 0.67);
    bingkai(-97, -63, -150.0, -45.0, 0.3);

    //TAMBAHAN
    glColor3f(0.6, 0.5, 0.4);
    db(-90, -82.0, -160.0, -156.0, 0.1);
    db(-79, -71.0, -160.0, -156.0, 0.1);

    //bingkai
    glColor3f(0.85, 0.76, 0.67);
    db(-81, -79, -150.0, -45.0, 0.5);
    db(-89.5, -88.5, -150.0, -45.0, 0.5);
    db(-71.5, -70.5, -150.0, -45.0, 0.5);

    db(-97, -81, -67, -65, 0.5); //horizontal -1
    db(-97, -81, -88, -86, 0.5); //2
    db(-97, -81, -107, -105, 0.5); //3
    db(-97, -81, -128, -126, 0.5); //4

    db(-79, -63, -67, -65, 0.5); //horizontal -1
    db(-79, -63, -88, -86, 0.5); //2
    db(-79, -63, -107, -105, 0.5); //3
    db(-79, -63, -128, -126, 0.5); //4

    //3
    glColor3f(0.2, 0.2, 0.2);
    db(-47, -13, -150.0, -45.0, 0.1);
    //bingkai utama
    //glColor3f(0.85, 0.76, 0.67);
    //bingkai(-47, -13, -150.0, -45.0, 0.3);

    //bingkai
    glColor3f(0.85, 0.76, 0.67);
    db(-31, -29, -150.0, -45.0, 0.5);
    db(-39.5, -38.5, -150.0, -45.0, 0.5);
    db(-21.5, -20.5, -150.0, -45.0, 0.5);

    db(-47, -31, -67, -65, 0.5); //horizontal -1
    db(-47, -31, -88, -86, 0.5); //2
    db(-47, -31, -107, -105, 0.5); //3
    db(-47, -31, -128, -126, 0.5); //4

    db(-29, -13, -67, -65, 0.5); //horizontal -1
    db(-29, -13, -88, -86, 0.5); //2
    db(-29, -13, -107, -105, 0.5); //3
    db(-29, -13, -128, -126, 0.5); //4

    //4
    glColor3f(0.2, 0.2, 0.2);
    db(3, 37, -150.0, -45.0, 0.1);
    //bingkai utama
    glColor3f(0.85, 0.76, 0.67);
    bingkai(3, 37, -150.0, -45.0, 0.3);

    //TAMBAHAN
    glColor3f(0.6, 0.5, 0.4);
    db(10, 18.0, -160.0, -156.0, 0.1);
    db(21, 29.0, -160.0, -156.0, 0.1);

    //bingkai
    glColor3f(0.85, 0.76, 0.67);
    db(19, 21, -150.0, -45.0, 0.5);
    db(11.5, 12.5, -150.0, -45.0, 0.5);
    db(29.5, 30.5, -150.0, -45.0, 0.5);

    db(3, 19, -67, -65, 0.5); //horizontal -1
    db(3, 19, -88, -86, 0.5); //2
    db(3, 19, -107, -105, 0.5); //3
    db(3, 19, -128, -126, 0.5); //4

    db(21, 37, -67, -65, 0.5); //horizontal -1
    db(21, 37, -88, -86, 0.5); //2
    db(21, 37, -107, -105, 0.5); //3
    db(21, 37, -128, -126, 0.5); //4

    //tiang
    glColor3f(0.85, 0.76, 0.67);
    //1
    //depan
    db(-157, -153, -150.0, -45.0, 5.0); //utama
    db2(-157, -163, -153, -147, -45, -35, 5);   //atas
    glColor3f(0.6, 0.5, 0.4);
    db(-157, -153, -152.0, -150.0, 5.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-157, -153, -153.0, -152.0, 5.0); //bawah terang
    glColor3f(0.6, 0.5, 0.4);
    db(-157, -153, -155.0, -153.0, 5.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-157, -153, -165.0, -155.0, 5.0); //bawah terang

    //atas-tiang
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-163, -35, 5.0);
    glVertex3f(-147, -35, 5.0);
    glVertex3f(-145, -35, 0.0);
    glVertex3f(-165, -35, 0.0);
    glEnd();

    //kiri
        //tengah
    glColor3f(0.6, 0.5, 0.4);
    kk2(-157.0, -160.0, -165.0, -45.0, 5.0, 0.0);
    //atas
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-157, -45.0, 5.0);
    glVertex3f(-163, -35.0, 5.0);
    glVertex3f(-165, -35.0, 0.0);
    glVertex3f(-160, -45.0, 0.0);
    glEnd();

    //kanan
    kk2(-151.0, -153.0, -165.0, -45.0, 0.0, 5.0);
    glBegin(GL_QUADS);
    glVertex3f(-147, -35.0, 5.0);
    glVertex3f(-153, -45.0, 5.0);
    glVertex3f(-151, -45.0, 0.0);
    glVertex3f(-145, -35.0, 0.0);
    glEnd();

    //SEGITIGA SIKU
    glColor3f(0.6, 0.5, 0.4);       //depan
    glBegin(GL_QUADS);
    glVertex3f(-157.0, -35.0, 5.0);
    glVertex3f(-157.0, -12.0, 0.0);
    glVertex3f(-153.0, -12.0, 0.0);
    glVertex3f(-153.0, -35.0, 5.0);
    glEnd();

    glColor3f(0.5, 0.4, 0.3);   //kiri
    glBegin(GL_TRIANGLES);
    glVertex3f(-157.0, -12.0, 0.0);
    glVertex3f(-157.0, -35.0, 0.0);
    glVertex3f(-157.0, -35.0, 5.0);
    glEnd();

    glBegin(GL_TRIANGLES);      //kanan
    glVertex3f(-153.0, -12.0, 0.0);
    glVertex3f(-153.0, -35.0, 0.0);
    glVertex3f(-153.0, -35.0, 5.0);
    glEnd();

    glColor3f(0.85, 0.76, 0.67);
    //2
    //depan
    db(-107, -103, -150.0, -45.0, 5.0);
    db2(-107, -113, -103, -97, -45, -35, 5);
    glColor3f(0.6, 0.5, 0.4);
    db(-107, -103, -152.0, -150.0, 5.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-107, -103, -153.0, -152.0, 5.0); //bawah terang
    glColor3f(0.6, 0.5, 0.4);
    db(-107, -103, -155.0, -153.0, 5.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-107, -103, -165.0, -155.0, 5.0); //bawah terang

    //atas-tiang
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-113, -35, 5.0);
    glVertex3f(-97, -35, 5.0);
    glVertex3f(-95, -35, 0.0);
    glVertex3f(-116, -35, 0.0);
    glEnd();

    //kiri
        //tengah
    glColor3f(0.6, 0.5, 0.4);
    kk2(-107.0, -109.0, -165.0, -45.0, 5.0, 0.0);
    //atas
    glBegin(GL_QUADS);
    glVertex3f(-107, -45.0, 5.0);
    glVertex3f(-113, -35.0, 5.0);
    glVertex3f(-115, -35.0, 0.0);
    glVertex3f(-109, -45.0, 0.0);
    glEnd();

    //kanan
    glColor3f(0.6, 0.5, 0.4);
    kk2(-101.0, -103.0, -165.0, -45.0, 0.0, 5.0);
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-97, -35.0, 5.0);
    glVertex3f(-103, -45.0, 5.0);
    glVertex3f(-101, -45.0, 0.0);
    glVertex3f(-95, -35.0, 0.0);
    glEnd();

    //SEGITIGA SIKU
    glColor3f(0.6, 0.5, 0.4);       //depan
    glBegin(GL_QUADS);
    glVertex3f(-107.0, -35.0, 5.0);
    glVertex3f(-107.0, -12.0, 0.0);
    glVertex3f(-103.0, -12.0, 0.0);
    glVertex3f(-103.0, -35.0, 5.0);
    glEnd();

    glColor3f(0.5, 0.4, 0.3);   //kiri
    glBegin(GL_TRIANGLES);
    glVertex3f(-107.0, -12.0, 0.0);
    glVertex3f(-107.0, -35.0, 0.0);
    glVertex3f(-107.0, -35.0, 5.0);
    glEnd();

    glBegin(GL_TRIANGLES);      //kanan
    glVertex3f(-103.0, -12.0, 0.0);
    glVertex3f(-103.0, -35.0, 0.0);
    glVertex3f(-103.0, -35.0, 5.0);
    glEnd();

    glColor3f(0.85, 0.76, 0.67);
    //3
    //depan
    db(-57, -53, -150.0, -45.0, 5.0);
    db2(-57, -63, -53, -47, -45, -35, 5);
    glColor3f(0.6, 0.5, 0.4);
    db(-57, -53, -152.0, -150.0, 5.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-57, -53, -153.0, -152.0, 5.0); //bawah terang
    glColor3f(0.6, 0.5, 0.4);
    db(-57, -53, -155.0, -153.0, 5.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-57, -53, -165.0, -155.0, 5.0); //bawah terang

    //atas-tiang
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-63, -35, 5.0);
    glVertex3f(-47, -35, 5.0);
    glVertex3f(-45, -35, 0.0);
    glVertex3f(-66, -35, 0.0);
    glEnd();

    //kiri
        //tengah
    glColor3f(0.6, 0.5, 0.4);
    kk2(-57.0, -59.0, -165.0, -45.0, 5.0, 0.0);
    //atas
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-57, -45.0, 5.0);
    glVertex3f(-63, -35.0, 5.0);
    glVertex3f(-65, -35.0, 0.0);
    glVertex3f(-59, -45.0, 0.0);
    glEnd();

    //kanan
    kk2(-51.0, -53.0, -165.0, -45.0, 0.0, 5.0);
    glBegin(GL_QUADS);
    glVertex3f(-47, -35.0, 5.0);
    glVertex3f(-53, -45.0, 5.0);
    glVertex3f(-51, -45.0, 0.0);
    glVertex3f(-45, -35.0, 0.0);
    glEnd();

    //SEGITIGA SIKU
    glColor3f(0.6, 0.5, 0.4);       //depan
    glBegin(GL_QUADS);
    glVertex3f(-57.0, -35.0, 5.0);
    glVertex3f(-57.0, -12.0, 0.0);
    glVertex3f(-53.0, -12.0, 0.0);
    glVertex3f(-53.0, -35.0, 5.0);
    glEnd();

    glColor3f(0.5, 0.4, 0.3);   //kiri
    glBegin(GL_TRIANGLES);
    glVertex3f(-57.0, -12.0, 0.0);
    glVertex3f(-57.0, -35.0, 0.0);
    glVertex3f(-57.0, -35.0, 5.0);
    glEnd();

    glBegin(GL_TRIANGLES);      //kanan
    glVertex3f(-53.0, -12.0, 0.0);
    glVertex3f(-53.0, -35.0, 0.0);
    glVertex3f(-53.0, -35.0, 5.0);
    glEnd();

    glColor3f(0.85, 0.76, 0.67);
    //4
    //depan
    db(-7, -3, -150.0, -45.0, 5.0);
    db2(-7, -13, -3, 3, -45, -35, 5);
    glColor3f(0.6, 0.5, 0.4);
    db(-7, -3, -152.0, -150.0, 5.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-7, -3, -153.0, -152.0, 5.0); //bawah terang
    glColor3f(0.6, 0.5, 0.4);
    db(-7, -3, -155.0, -153.0, 5.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-7, -3, -165.0, -155.0, 5.0); //bawah terang

    //atas-tiang
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-13, -35, 5.0);
    glVertex3f(3, -35, 5.0);
    glVertex3f(5, -35, 0.0);
    glVertex3f(-16, -35, 0.0);
    glEnd();

    //kiri
        //tengah
    glColor3f(0.6, 0.5, 0.4);
    kk2(-7.0, -9.0, -165.0, -45.0, 5.0, 0.0);
    //atas
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-7, -45.0, 5.0);
    glVertex3f(-13, -35.0, 5.0);
    glVertex3f(-15, -35.0, 0.0);
    glVertex3f(-9, -45.0, 0.0);
    glEnd();

    //kanan
    kk2(-1.0, -3.0, -165.0, -45.0, 0.0, 5.0);
    glBegin(GL_QUADS);
    glVertex3f(3, -35.0, 5.0);
    glVertex3f(-3, -45.0, 5.0);
    glVertex3f(-1, -45.0, 0.0);
    glVertex3f(5, -35.0, 0.0);
    glEnd();

    //SEGITIGA SIKU
    glColor3f(0.6, 0.5, 0.4);       //depan
    glBegin(GL_QUADS);
    glVertex3f(-7.0, -35.0, 5.0);
    glVertex3f(-7.0, -12.0, 0.0);
    glVertex3f(-3.0, -12.0, 0.0);
    glVertex3f(-3.0, -35.0, 5.0);
    glEnd();

    glColor3f(0.5, 0.4, 0.3);   //kiri
    glBegin(GL_TRIANGLES);
    glVertex3f(-7.0, -12.0, 0.0);
    glVertex3f(-7.0, -35.0, 0.0);
    glVertex3f(-7.0, -35.0, 5.0);
    glEnd();

    glBegin(GL_TRIANGLES);      //kanan
    glVertex3f(-3.0, -12.0, 0.0);
    glVertex3f(-3.0, -35.0, 0.0);
    glVertex3f(-3.0, -35.0, 5.0);
    glEnd();

    //PINTU
    glColor3f(0.6, 0.5, 0.4);
    db(-37.0, -23.0, -165.0, -132.0, 0.6);
    //bingkai
    glColor3f(0.85, 0.76, 0.67);
    //atas
    db(-40.0, -20.0, -132.0, -128.0, 3.0);
    glColor3f(0.6, 0.5, 0.4);
    ab(-40.0, -20.0, -128.0, 3.0, 0.6);
    glColor3f(0.85, 0.76, 0.67);
    ab(-40.0, -20.0, -132.0, 3.0, 0.6);
    //kiri
    db(-40.0, -37.0, -165.0, -132.0, 3.0);
    glColor3f(0.6, 0.5, 0.4);
    kk(-40.0, -165.0, -128.0, 3.0, 0.6);
    kk(-37.0, -165.0, -128.0, 3.0, 0.6);
    //kanan
    glColor3f(0.85, 0.76, 0.67);
    db(-23.0, -20.0, -165.0, -132.0, 3.0);
    glColor3f(0.6, 0.5, 0.4);
    kk(-23.0, -165.0, -128.0, 3.0, 0.6);
    kk(-20.0, -165.0, -128.0, 3.0, 0.6);

    //TANGGA
        //atas1
    glColor3f(0.85, 0.76, 0.67);
    ab(-37.0, -23.0, -161.0, 2.6, 0.6);
    //depan1
    glColor3f(0.6, 0.5, 0.4);
    db(-37.0, -23.0, -162.0, -161.0, 2.6);
    //kiri
    kk(-37.0, -165.0, -161.0, 2.6, 0.6);
    //kanan
    kk(-23.0, -165.0, -161.0, 2.6, 0.6);
    //atas2
    glColor3f(0.85, 0.76, 0.67);
    ab(-37.0, -23.0, -162.0, 4.6, 2.6);
    //depan2
    glColor3f(0.6, 0.5, 0.4);
    db(-37.0, -23.0, -163.0, -162.0, 4.6);
    //kiri
    kk(-37.0, -165.0, -162.0, 4.6, 2.6);
    //kanan
    kk(-23.0, -165.0, -162.0, 4.6, 2.6);
    //atas3
    glColor3f(0.85, 0.76, 0.67);
    ab(-37.0, -23.0, -163.0, 6.6, 4.6);
    //depan3
    glColor3f(0.6, 0.5, 0.4);
    db(-37.0, -23.0, -164.0, -163.0, 6.6);
    //kiri
    kk(-37.0, -165.0, -163.0, 6.6, 4.6);
    //kanan
    kk(-23.0, -165.0, -163.0, 6.6, 4.6);
    //atas4
    glColor3f(0.85, 0.76, 0.67);
    ab(-37.0, -23.0, -164.0, 8.6, 6.6);
    //depan4
    glColor3f(0.6, 0.5, 0.4);
    db(-37.0, -23.0, -165.0, -164.0, 8.6);
    //kiri
    kk(-37.0, -165.0, -164.0, 8.6, 6.6);
    //kanan
    kk(-23.0, -165.0, -164.0, 8.6, 6.6);

}

void bangunan_kiri_belakang() {
    //alas
    glColor3f(0.55, 0.46, 0.37);
    ab(-190.0, 200.0, -165.1, 30.0, -320.0);
    //bangunan kiri tengah
    glColor3f(0.85, 0.76, 0.67);
    //depan
    db(-165.0, 50.0, -35.0, -10.0, -140.0);
    glColor3f(0.6, 0.5, 0.4);
    db(-165.0, 50.0, -33.0, -35.0, -141.0);

    //jendela
    glColor3f(0.2, 0.2, 0.2);
    //1
    db(-147, -113, -150.0, -45.0, -140.1);
    //bingkai utama
    glColor3f(0.85, 0.76, 0.67);
    bingkai(-147, -113, -150.0, -45.0, -140.3);

    //bingkai
    glColor3f(0.85, 0.76, 0.67);
    db(-131, -129, -150.0, -45.0, -140.5);     //vertical
    db(-139.5, -138.5, -150.0, -45.0, -140.5); //kiri
    db(-121.5, -120.5, -150.0, -45.0, -140.5); //kanan

    db(-147, -131, -67, -65, -140.5); //horizontal -1
    db(-147, -131, -88, -86, -140.5); //2
    db(-147, -131, -107, -105, -140.5); //3
    db(-147, -131, -128, -126, -140.5); //4

    db(-129, -113, -67, -65, -140.5); //horizontal -1
    db(-129, -113, -88, -86, -140.5); //2
    db(-129, -113, -107, -105, -140.5); //3
    db(-129, -113, -128, -126, -140.5); //4

    //2
    glColor3f(0.2, 0.2, 0.2);
    db(-97, -63, -150.0, -45.0, -140.1);
    //bingkai utama
    glColor3f(0.85, 0.76, 0.67);
    bingkai(-97, -63, -150.0, -45.0, -140.3);

    //bingkai
    glColor3f(0.85, 0.76, 0.67);
    db(-81, -79, -150.0, -45.0, -140.5);
    db(-89.5, -88.5, -150.0, -45.0, -140.5);
    db(-71.5, -70.5, -150.0, -45.0, -140.5);

    db(-97, -81, -67, -65, -140.5); //horizontal -1
    db(-97, -81, -88, -86, -140.5); //2
    db(-97, -81, -107, -105, -140.5); //3
    db(-97, -81, -128, -126, -140.5); //4

    db(-79, -63, -67, -65, -140.5); //horizontal -1
    db(-79, -63, -88, -86, -140.5); //2
    db(-79, -63, -107, -105, -140.5); //3
    db(-79, -63, -128, -126, -140.5); //4

    //3
    glColor3f(0.2, 0.2, 0.2);
    db(-47, -13, -150.0, -45.0, -140.1);
    //bingkai utama
    //glColor3f(0.85, 0.76, 0.67);
    //bingkai(-47, -13, -150.0, -45.0, 0.3);

    //bingkai
    glColor3f(0.85, 0.76, 0.67);
    db(-31, -29, -150.0, -45.0, -140.5);
    db(-39.5, -38.5, -150.0, -45.0, -140.5);
    db(-21.5, -20.5, -150.0, -45.0, -140.5);

    db(-47, -31, -67, -65, -140.5); //horizontal -1
    db(-47, -31, -88, -86, -140.5); //2
    db(-47, -31, -107, -105, -140.5); //3
    db(-47, -31, -128, -126, -140.5); //4

    db(-29, -13, -67, -65, -140.5); //horizontal -1
    db(-29, -13, -88, -86, -140.5); //2
    db(-29, -13, -107, -105, -140.5); //3
    db(-29, -13, -128, -126, -140.5); //4

    //4
    glColor3f(0.2, 0.2, 0.2);
    db(3, 37, -150.0, -45.0, -140.1);
    //bingkai utama
    glColor3f(0.85, 0.76, 0.67);
    bingkai(3, 37, -150.0, -45.0, -140.3);

    //bingkai
    glColor3f(0.85, 0.76, 0.67);
    db(19, 21, -150.0, -45.0, -140.5);
    db(11.5, 12.5, -150.0, -45.0, -140.5);
    db(29.5, 30.5, -150.0, -45.0, -140.5);

    db(3, 19, -67, -65, -140.5); //horizontal -1
    db(3, 19, -88, -86, -140.5); //2
    db(3, 19, -107, -105, -140.5); //3
    db(3, 19, -128, -126, -140.5); //4

    db(21, 37, -67, -65, -140.5); //horizontal -1
    db(21, 37, -88, -86, -140.5); //2
    db(21, 37, -107, -105, -140.5); //3
    db(21, 37, -128, -126, -140.5); //4

    //tiang
    glColor3f(0.85, 0.76, 0.67);
    //1
    //depan
    db(-157, -153, -150.0, -45.0, -145.0); //utama
    db2(-157, -163, -153, -147, -45, -35, -145);   //atas
    glColor3f(0.6, 0.5, 0.4);
    db(-157, -153, -152.0, -150.0, -145.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-157, -153, -153.0, -152.0, -145.0); //bawah terang
    glColor3f(0.6, 0.5, 0.4);
    db(-157, -153, -155.0, -153.0, -145.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-157, -153, -165.0, -155.0, -145.0); //bawah terang

    //atas-tiang
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-163, -35, -145.0);
    glVertex3f(-147, -35, -145.0);
    glVertex3f(-145, -35, -140.0);
    glVertex3f(-165, -35, -140.0);
    glEnd();

    //kiri
        //tengah
    glColor3f(0.6, 0.5, 0.4);
    kk2(-157.0, -160.0, -165.0, -45.0, -145.0, -140.0);
    //atas
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-157, -45.0, -145.0);
    glVertex3f(-163, -35.0, -145.0);
    glVertex3f(-165, -35.0, -140.0);
    glVertex3f(-160, -45.0, -140.0);
    glEnd();

    //kanan
    kk2(-151.0, -153.0, -165.0, -45.0, -140.0, -145.0);
    glBegin(GL_QUADS);
    glVertex3f(-147, -35.0, -145.0);
    glVertex3f(-153, -45.0, -145.0);
    glVertex3f(-151, -45.0, -140.0);
    glVertex3f(-145, -35.0, -140.0);
    glEnd();

    //SEGITIGA SIKU
    glColor3f(0.6, 0.5, 0.4);       //depan
    glBegin(GL_QUADS);
    glVertex3f(-157.0, -35.0, -145.0);
    glVertex3f(-157.0, -12.0, -140.0);
    glVertex3f(-153.0, -12.0, -140.0);
    glVertex3f(-153.0, -35.0, -145.0);
    glEnd();

    glColor3f(0.5, 0.4, 0.3);   //kiri
    glBegin(GL_TRIANGLES);
    glVertex3f(-157.0, -12.0, -140.0);
    glVertex3f(-157.0, -35.0, -140.0);
    glVertex3f(-157.0, -35.0, -145.0);
    glEnd();

    glBegin(GL_TRIANGLES);      //kanan
    glVertex3f(-153.0, -12.0, -140.0);
    glVertex3f(-153.0, -35.0, -140.0);
    glVertex3f(-153.0, -35.0, -145.0);
    glEnd();

    glColor3f(0.85, 0.76, 0.67);
    //2
    //depan
    db(-107, -103, -150.0, -45.0, -145.0);
    db2(-107, -113, -103, -97, -45, -35, -145);
    glColor3f(0.6, 0.5, 0.4);
    db(-107, -103, -152.0, -150.0, -145.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-107, -103, -153.0, -152.0, -145.0); //bawah terang
    glColor3f(0.6, 0.5, 0.4);
    db(-107, -103, -155.0, -153.0, -145.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-107, -103, -165.0, -155.0, -145.0); //bawah terang

    //atas-tiang
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-113, -35, -145.0);
    glVertex3f(-97, -35, -145.0);
    glVertex3f(-95, -35, -140.0);
    glVertex3f(-116, -35, -140.0);
    glEnd();

    //kiri
        //tengah
    glColor3f(0.6, 0.5, 0.4);
    kk2(-107.0, -109.0, -165.0, -45.0, -145.0, -140.0);
    //atas
    glBegin(GL_QUADS);
    glVertex3f(-107, -45.0, -145.0);
    glVertex3f(-113, -35.0, -145.0);
    glVertex3f(-115, -35.0, -140.0);
    glVertex3f(-109, -45.0, -140.0);
    glEnd();

    //kanan
    glColor3f(0.6, 0.5, 0.4);
    kk2(-101.0, -103.0, -165.0, -45.0, -140.0, -145.0);
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-97, -35.0, -145.0);
    glVertex3f(-103, -45.0, -145.0);
    glVertex3f(-101, -45.0, -140.0);
    glVertex3f(-95, -35.0, -140.0);
    glEnd();

    //SEGITIGA SIKU
    glColor3f(0.6, 0.5, 0.4);       //depan
    glBegin(GL_QUADS);
    glVertex3f(-107.0, -35.0, -145.0);
    glVertex3f(-107.0, -12.0, -140.0);
    glVertex3f(-103.0, -12.0, -140.0);
    glVertex3f(-103.0, -35.0, -145.0);
    glEnd();

    glColor3f(0.5, 0.4, 0.3);   //kiri
    glBegin(GL_TRIANGLES);
    glVertex3f(-107.0, -12.0, -140.0);
    glVertex3f(-107.0, -35.0, -140.0);
    glVertex3f(-107.0, -35.0, -145.0);
    glEnd();

    glBegin(GL_TRIANGLES);      //kanan
    glVertex3f(-103.0, -12.0, -140.0);
    glVertex3f(-103.0, -35.0, -140.0);
    glVertex3f(-103.0, -35.0, -145.0);
    glEnd();

    glColor3f(0.85, 0.76, 0.67);
    //3
    //depan
    db(-57, -53, -150.0, -45.0, -145.0);
    db2(-57, -63, -53, -47, -45, -35, -145);
    glColor3f(0.6, 0.5, 0.4);
    db(-57, -53, -152.0, -150.0, -145.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-57, -53, -153.0, -152.0, -145.0); //bawah terang
    glColor3f(0.6, 0.5, 0.4);
    db(-57, -53, -155.0, -153.0, -145.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-57, -53, -165.0, -155.0, -145.0); //bawah terang

    //atas-tiang
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-63, -35, -145.0);
    glVertex3f(-47, -35, -145.0);
    glVertex3f(-45, -35, -140.0);
    glVertex3f(-66, -35, -140.0);
    glEnd();

    //kiri
        //tengah
    glColor3f(0.6, 0.5, 0.4);
    kk2(-57.0, -59.0, -165.0, -45.0, -145.0, -140.0);
    //atas
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-57, -45.0, -145.0);
    glVertex3f(-63, -35.0, -145.0);
    glVertex3f(-65, -35.0, -140.0);
    glVertex3f(-59, -45.0, -140.0);
    glEnd();

    //kanan
    kk2(-51.0, -53.0, -165.0, -45.0, -140.0, -145.0);
    glBegin(GL_QUADS);
    glVertex3f(-47, -35.0, -145.0);
    glVertex3f(-53, -45.0, -145.0);
    glVertex3f(-51, -45.0, -140.0);
    glVertex3f(-45, -35.0, -140.0);
    glEnd();

    //SEGITIGA SIKU
    glColor3f(0.6, 0.5, 0.4);       //depan
    glBegin(GL_QUADS);
    glVertex3f(-57.0, -35.0, -145.0);
    glVertex3f(-57.0, -12.0, -140.0);
    glVertex3f(-53.0, -12.0, -140.0);
    glVertex3f(-53.0, -35.0, -145.0);
    glEnd();

    glColor3f(0.5, 0.4, 0.3);   //kiri
    glBegin(GL_TRIANGLES);
    glVertex3f(-57.0, -12.0, -140.0);
    glVertex3f(-57.0, -35.0, -140.0);
    glVertex3f(-57.0, -35.0, -145.0);
    glEnd();

    glBegin(GL_TRIANGLES);      //kanan
    glVertex3f(-53.0, -12.0, -140.0);
    glVertex3f(-53.0, -35.0, -140.0);
    glVertex3f(-53.0, -35.0, -145.0);
    glEnd();

    glColor3f(0.85, 0.76, 0.67);
    //4
    //depan
    db(-7, -3, -150.0, -45.0, -145.0);
    db2(-7, -13, -3, 3, -45, -35, -145);
    glColor3f(0.6, 0.5, 0.4);
    db(-7, -3, -152.0, -150.0, -145.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-7, -3, -153.0, -152.0, -145.0); //bawah terang
    glColor3f(0.6, 0.5, 0.4);
    db(-7, -3, -155.0, -153.0, -145.0); //bawah gelap
    glColor3f(0.85, 0.76, 0.67);
    db(-7, -3, -165.0, -155.0, -145.0); //bawah terang

    //atas-tiang
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-13, -35, -145.0);
    glVertex3f(3, -35, -145.0);
    glVertex3f(5, -35, -140.0);
    glVertex3f(-16, -35, -140.0);
    glEnd();

    //kiri
        //tengah
    glColor3f(0.6, 0.5, 0.4);
    kk2(-7.0, -9.0, -165.0, -45.0, -145.0, -140.0);
    //atas
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-7, -45.0, -145.0);
    glVertex3f(-13, -35.0, -145.0);
    glVertex3f(-15, -35.0, -140.0);
    glVertex3f(-9, -45.0, -140.0);
    glEnd();

    //kanan
    kk2(-1.0, -3.0, -165.0, -45.0, -140.0, -145.0);
    glBegin(GL_QUADS);
    glVertex3f(3, -35.0, -145.0);
    glVertex3f(-3, -45.0, -145.0);
    glVertex3f(-1, -45.0, -140.0);
    glVertex3f(5, -35.0, -140.0);
    glEnd();

    //SEGITIGA SIKU
    glColor3f(0.6, 0.5, 0.4);       //depan
    glBegin(GL_QUADS);
    glVertex3f(-7.0, -35.0, -145.0);
    glVertex3f(-7.0, -12.0, -140.0);
    glVertex3f(-3.0, -12.0, -140.0);
    glVertex3f(-3.0, -35.0, -145.0);
    glEnd();

    glColor3f(0.5, 0.4, 0.3);   //kiri
    glBegin(GL_TRIANGLES);
    glVertex3f(-7.0, -12.0, -140.0);
    glVertex3f(-7.0, -35.0, -140.0);
    glVertex3f(-7.0, -35.0, -145.0);
    glEnd();

    glBegin(GL_TRIANGLES);      //kanan
    glVertex3f(-3.0, -12.0, -140.0);
    glVertex3f(-3.0, -35.0, -140.0);
    glVertex3f(-3.0, -35.0, -145.0);
    glEnd();
}

void bangunan_kanan() {
    glColor3f(0.85, 0.76, 0.67);
    //depan
    db(50.0, 160.0, -165.0, 150.0, 0.0);
    //kiri
    kk(50.0, -165.0, 150.0, 0.0, -140.0);
    //kanan
    kk(160.0, -165.0, 150.0, 0.0, -140.0);

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(50, 150.0, 0.0);
    glVertex3f(50, 150.5, -140.0);
    glVertex3f(160, 150.5, -140.0);
    glVertex3f(160, 150.0, 0.0);
    glEnd();

    //bawah
    ab(50.0, 160.0, -165.0, 0, -140.0);

    //tembok kiri menonjol
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(48.5, -157.0, 15.0);
    glVertex3f(48.5, 175.5, 15.0);
    glVertex3f(70.0, 175.5, 15.0);
    glVertex3f(70.0, -157.0, 15.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(48.5, 175.0, 15.0);
    glVertex3f(48.5, 190.5, 15.0);
    glVertex3f(52.0, 190.5, 15.0);
    glVertex3f(52.0, 175.0, 15.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(52.0, 175.0, 15.0);
    glVertex3f(52.0, 181.5, 15.0);
    glVertex3f(57.0, 181.5, 15.0);
    glVertex3f(57.0, 175.0, 15.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(57.0, 175.0, 15.0);
    glVertex3f(57.0, 190.5, 15.0);
    glVertex3f(60.5, 190.5, 15.0);
    glVertex3f(60.5, 175.0, 15.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(60.5, 175.0, 15.0);
    glVertex3f(60.5, 181.5, 15.0);
    glVertex3f(66.5, 181.5, 15.0);
    glVertex3f(66.5, 175.0, 15.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(66.5, 175.0, 15.0);
    glVertex3f(66.5, 190.5, 15.0);
    glVertex3f(70.0, 190.5, 15.0);
    glVertex3f(70.0, 175.0, 15.0);
    glEnd();

    //tembok kiri menonjol sisi kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, 175.0, 0.0);
    glVertex3f(50.0, 175.5, 15.0);
    glVertex3f(50.0, -157.0, 15.0);
    glVertex3f(50.0, -165.0, 0.0);
    glEnd();
    //kiri
 //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, 191.0, 0.0);
    glVertex3f(50.0, 191.5, 3.5);
    glVertex3f(50.0, 175.0, 3.5);
    glVertex3f(50.0, 175.0, 0.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, 181.0, 3.5);
    glVertex3f(50.0, 181.5, 5.5);
    glVertex3f(50.0, 175.0, 5.5);
    glVertex3f(50.0, 175.0, 3.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, 191.0, 5.5);
    glVertex3f(50.0, 191.5, 8.5);
    glVertex3f(50.0, 175.0, 8.5);
    glVertex3f(50.0, 175.0, 6.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, 181.0, 8.5);
    glVertex3f(50.0, 181.5, 11.5);
    glVertex3f(50.0, 175.0, 11.5);
    glVertex3f(50.0, 175.0, 8.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, 191.0, 11.5);
    glVertex3f(50.0, 191.5, 15.0);
    glVertex3f(50.0, 175.0, 15.0);
    glVertex3f(50.0, 175.0, 11.5);
    glEnd();
    //tembok kiri menonjol sisi kanan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, 175.0, 0.0);
    glVertex3f(70.0, 175.5, 15.0);
    glVertex3f(70.0, -157.0, 15.0);
    glVertex3f(70.0, -165.0, 0.0);
    glEnd();
    //kanan
 //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, 191.0, 0.0);
    glVertex3f(70.0, 191.5, 3.5);
    glVertex3f(70.0, 175.0, 3.5);
    glVertex3f(70.0, 175.0, 0.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, 181.0, 3.5);
    glVertex3f(70.0, 181.5, 5.5);
    glVertex3f(70.0, 175.0, 5.5);
    glVertex3f(70.0, 175.0, 3.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, 191.0, 5.5);
    glVertex3f(70.0, 191.5, 8.5);
    glVertex3f(70.0, 175.0, 8.5);
    glVertex3f(70.0, 175.0, 6.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, 181.0, 8.5);
    glVertex3f(70.0, 181.5, 11.5);
    glVertex3f(70.0, 175.0, 11.5);
    glVertex3f(70.0, 175.0, 8.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, 191.0, 11.5);
    glVertex3f(70.0, 191.5, 15.0);
    glVertex3f(70.0, 175.0, 15.0);
    glVertex3f(70.0, 175.0, 11.5);
    glEnd();
    //tembok kiri menonjol bawah
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.2, 0.2);
    glVertex3f(48.5, -157.0, 18.0);
    glVertex3f(48.5, -140.0, 18.0);
    glVertex3f(70.0, -140.0, 18.0);
    glVertex3f(70.0, -157.0, 18.0);
    glEnd();
    //tembok kiri menonjol bawah sisi kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50, -157.0, 18.0);
    glVertex3f(50, -140.0, 18.0);
    glVertex3f(50, -140.0, 15.0);
    glVertex3f(50, -157.0, 15.0);
    glEnd();

    //tembok kiri menonjol bawah sisi kanan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70, -157.0, 18.0);
    glVertex3f(70, -140.0, 18.0);
    glVertex3f(70, -140.0, 15.0);
    glVertex3f(70, -157.0, 15.0);
    glEnd();

    //tembok kiri menonjol bawah sisi atas
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, -140.0, 15.0);
    glVertex3f(70.0, -140.0, 15.0);
    glVertex3f(70.0, -140.0, 18.0);
    glVertex3f(50.0, -140.0, 18.0);
    glEnd();

    //tembok kiri menonjol bawah sisi bawah
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, -157.0, 15.0);
    glVertex3f(70.0, -157.0, 15.0);
    glVertex3f(70.0, -157.0, 18.0);
    glVertex3f(50.0, -157.0, 18.0);
    glEnd();

    //tiang kiri sisi bawah
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, -157.0, 15.0);
    glVertex3f(70.0, -157.0, 15.0);
    glVertex3f(70.0, -165.0, 0.0);
    glVertex3f(50.0, -165.0, 0.0);
    glEnd();

    //tiang kiri sisi bawah
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, -157.0, 15.0);
    glVertex3f(70.0, -157.0, 15.0);
    glVertex3f(70.0, -165.0, 0.0);
    glVertex3f(50.0, -165.0, 0.0);
    glEnd();

    //tembok kanan menonjol
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(140.0, -157.0, 15.0);
    glVertex3f(140.0, 175.5, 15.0);
    glVertex3f(160.0, 175.5, 15.0);
    glVertex3f(160.0, -157.0, 15.0);
    glEnd();
    //depan
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(140.0, 175.0, 15.0);
    glVertex3f(140.0, 190.5, 15.0);
    glVertex3f(143.0, 190.5, 15.0);
    glVertex3f(143.0, 175.0, 15.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(143.0, 175.0, 15.0);
    glVertex3f(143.0, 181.5, 15.0);
    glVertex3f(147.5, 181.5, 15.0);
    glVertex3f(147.5, 175.0, 15.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(147.5, 175.0, 15.0);
    glVertex3f(147.5, 190.5, 15.0);
    glVertex3f(151.5, 190.5, 15.0);
    glVertex3f(151.5, 175.0, 15.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(151.5, 175.0, 15.0);
    glVertex3f(151.5, 181.5, 15.0);
    glVertex3f(157.0, 181.5, 15.0);
    glVertex3f(157.0, 175.0, 15.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(157.0, 175.0, 15.0);
    glVertex3f(157.0, 190.5, 15.0);
    glVertex3f(160.0, 190.5, 15.0);
    glVertex3f(160.0, 175.0, 15.0);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, -157.0, 15.0);
    glVertex3f(160.0, -157.0, 15.0);
    glVertex3f(160.0, -165.0, 0.0);
    glVertex3f(140.0, -165.0, 0.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 150, 0.0);
    glVertex3f(160.0, 150, 0.0);
    glVertex3f(160.0, 145.5, 15.0);
    glVertex3f(140.0, 145.5, 15.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, 175.0, 0.0);
    glVertex3f(160.0, 175.5, 15.0);
    glVertex3f(160.0, -157.0, 15.0);
    glVertex3f(160.0, -165.0, 0.0);
    glEnd();
    //kanan
//tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, 191.0, 0.0);
    glVertex3f(160.0, 191.5, 3.5);
    glVertex3f(160.0, 175.0, 3.5);
    glVertex3f(160.0, 175.0, 0.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, 181.0, 3.5);
    glVertex3f(160.0, 181.5, 5.5);
    glVertex3f(160.0, 175.0, 5.5);
    glVertex3f(160.0, 175.0, 3.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, 191.0, 5.5);
    glVertex3f(160.0, 191.5, 8.5);
    glVertex3f(160.0, 175.0, 8.5);
    glVertex3f(160.0, 175.0, 6.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, 181.0, 8.5);
    glVertex3f(160.0, 181.5, 11.5);
    glVertex3f(160.0, 175.0, 11.5);
    glVertex3f(160.0, 175.0, 8.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, 191.0, 11.5);
    glVertex3f(160.0, 191.5, 15.0);
    glVertex3f(160.0, 175.0, 15.0);
    glVertex3f(160.0, 175.0, 11.5);
    glEnd();


    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 175.0, 0.0);
    glVertex3f(140.0, 175.5, 15.0);
    glVertex3f(140.0, -157.0, 15.0);
    glVertex3f(140.0, -165.0, 0.0);
    glEnd();
    //kiri
//tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 191.0, 0.0);
    glVertex3f(140.0, 191.5, 3.5);
    glVertex3f(140.0, 175.0, 3.5);
    glVertex3f(140.0, 175.0, 0.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 181.0, 3.5);
    glVertex3f(140.0, 181.5, 5.5);
    glVertex3f(140.0, 175.0, 5.5);
    glVertex3f(140.0, 175.0, 3.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 191.0, 5.5);
    glVertex3f(140.0, 191.5, 8.5);
    glVertex3f(140.0, 175.0, 8.5);
    glVertex3f(140.0, 175.0, 6.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 181.0, 8.5);
    glVertex3f(140.0, 181.5, 11.5);
    glVertex3f(140.0, 175.0, 11.5);
    glVertex3f(140.0, 175.0, 8.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 191.0, 11.5);
    glVertex3f(140.0, 191.5, 15.0);
    glVertex3f(140.0, 175.0, 15.0);
    glVertex3f(140.0, 175.0, 11.5);
    glEnd();

    //tembok kanan menonjol bawah
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.2, 0.2);
    glVertex3f(140.0, -157.0, 18.0);
    glVertex3f(140.0, -140.0, 18.0);
    glVertex3f(160.0, -140.0, 18.0);
    glVertex3f(160.0, -157.0, 18.0);
    glEnd();

    //pot
   //belakang
    glBegin(GL_QUADS);
    glColor3f(0.545, 0, 1);
    glVertex3f(120.0, -157.0, 18.2);
    glVertex3f(120.0, -140.0, 18.2);
    glColor3f(0.913, 0.58, 0.47);
    glVertex3f(140.0, -140.0, 18.2);
    glVertex3f(140.0, -157.0, 18.2);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.545, 0, 1);
    glVertex3f(120.0, -157.0, 28.2);
    glVertex3f(120.0, -140.0, 28.2);
    glColor3f(0.913, 0.58, 0.47);
    glVertex3f(140.0, -140.0, 28.2);
    glVertex3f(140.0, -157.0, 28.2);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.545, 0, 1);
    glVertex3f(140.0, -157.0, 28.2);
    glVertex3f(140.0, -140.0, 28.2);
    glColor3f(0.913, 0.58, 0.47);
    glVertex3f(140.0, -140.0, 18.2);
    glVertex3f(140.0, -157.0, 18.2);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.545, 0, 1);
    glVertex3f(120.0, -157.0, 28.2);
    glVertex3f(120.0, -140.0, 28.2);
    glColor3f(0.913, 0.58, 0.47);
    glVertex3f(120.0, -140.0, 18.2);
    glVertex3f(120.0, -157.0, 18.2);
    glEnd();
    //tanaman
    //1
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex3f(125.0, -155.0, 26.2);
    glVertex3f(125.0, -105.0, 26.2);
    glVertex3f(125.5, -105.0, 26.2);
    glVertex3f(135.0, -155.0, 26.2);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex3f(135.0, -155.0, 26.2);
    glVertex3f(139.0, -120.0, 26.2);
    glVertex3f(139.5, -120.0, 26.2);
    glVertex3f(140.0, -155.0, 26.2);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex3f(126.0, -155.0, 26.3);
    glVertex3f(135.1, -135.0, 26.3);
    glVertex3f(135.1, -135.0, 26.3);
    glVertex3f(136.0, -155.0, 26.3);
    glEnd();
    //4
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    glVertex3f(121.0, -155.0, 26.4);
    glVertex3f(121.1, -125.0, 26.4);
    glVertex3f(121.2, -125.0, 26.4);
    glVertex3f(130.0, -155.0, 26.4);
    glEnd();


    //tembok kanan menonjol bawah sisi kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, -157.0, 18.0);
    glVertex3f(140.0, -140.0, 18.0);
    glVertex3f(140.0, -140.0, 15.0);
    glVertex3f(140.0, -157.0, 15.0);
    glEnd();

    //tembok kanan menonjol bawah sisi kanan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, -157.0, 18.0);
    glVertex3f(160.0, -140.0, 18.0);
    glVertex3f(160.0, -140.0, 15.0);
    glVertex3f(160.0, -157.0, 15.0);
    glEnd();

    //tembok kanan menonjol bawah sisi atas
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(138.5, -140.0, 15.0);
    glVertex3f(160.0, -140.0, 15.0);
    glVertex3f(160.0, -140.0, 18.0);
    glVertex3f(138.5, -140.0, 18.0);
    glEnd();

    //tembok kanan menonjol bawah sisi bawah
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(138.5, -157.0, 15.0);
    glVertex3f(160.0, -157.0, 15.0);
    glVertex3f(160.0, -157.0, 18.0);
    glVertex3f(138.5, -157.0, 18.0);
    glEnd();
    //jendela kiri pinggir paling bawah
    //1
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(54.0, -128.0, 18.0);
    glVertex3f(54.0, -108.0, 18.0);
    glVertex3f(63.0, -108.0, 18.0);
    glVertex3f(63.0, -128.0, 18.0);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(54.0, -70.0, 18.0);
    glVertex3f(54.0, -50.0, 18.0);
    glVertex3f(63.0, -50.0, 18.0);
    glVertex3f(63.0, -70.0, 18.0);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(54.0, -12.0, 18.0);
    glVertex3f(54.0, 8.0, 18.0);
    glVertex3f(63.0, 8.0, 18.0);
    glVertex3f(63.0, -12.0, 18.0);
    glEnd();
    //kusen jendela
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(58.5, -128.0, 18.5);
    glVertex3f(58.5, 8.0, 18.5);
    glEnd();
    //depan
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, 150.0, 2.0);
    glVertex3f(70.0, 170.5, 2.0);
    glVertex3f(80.0, 170.5, 2.0);
    glVertex3f(80.0, 150.0, 2.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(80.0, 150.0, 2.0);
    glVertex3f(80.0, 157.5, 2.0);
    glVertex3f(90.5, 157.5, 2.0);
    glVertex3f(90.5, 150.0, 2.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(90.0, 150.0, 2.0);
    glVertex3f(90.0, 170.5, 2.0);
    glVertex3f(100.0, 170.5, 2.0);
    glVertex3f(100.0, 150.0, 2.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(100.0, 150.0, 2.0);
    glVertex3f(100.0, 157.5, 2.0);
    glVertex3f(110.5, 157.5, 2.0);
    glVertex3f(110.5, 150.0, 2.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(110.0, 150.0, 2.0);
    glVertex3f(110.0, 170.5, 2.0);
    glVertex3f(120.0, 170.5, 2.0);
    glVertex3f(120.0, 150.0, 2.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(120.0, 150.0, 2.0);
    glVertex3f(120.0, 157.5, 2.0);
    glVertex3f(130.5, 157.5, 2.0);
    glVertex3f(130.5, 150.0, 2.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(130.0, 150.0, 2.0);
    glVertex3f(130.0, 170.5, 2.0);
    glVertex3f(140.0, 170.5, 2.0);
    glVertex3f(140.0, 150.0, 2.0);
    glEnd();

    //jendela
    glLineWidth(6.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(140.0, -165.0, 1.1);
    glVertex3f(140.0, 150.0, 1.1);
    glVertex3f(119.0, 150.0, 1.1);
    glVertex3f(119.0, -165.0, 1.1);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, 30.0, 1.3);
    glVertex3f(140.0, 30.0, 1.3);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -40.0, 1.3);
    glVertex3f(140.0, -40.0, 1.3);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -110.0, 1.3);
    glVertex3f(91.0, -110.0, 1.3);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(140.0, -110.0, 1.3);
    glVertex3f(119.0, -110.0, 1.3);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(140.0, 120.0, 1.3);
    glVertex3f(70.0, 120.0, 1.3);
    glEnd();

    glLineWidth(9.0);
    glBegin(GL_LINES);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(119.0, -165.0, 3);
    glVertex3f(119.0, 150.0, 3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(119.0, -165.0, 5);
    glVertex3f(119.0, 150.0, 5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(91.0, -165.0, 5);
    glVertex3f(91.0, 150.0, 5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(91.0, -165.0, 3);
    glVertex3f(91.0, 150.0, 3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -165.0, 5);
    glVertex3f(70.0, 150.0, 5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, -165.0, 3);
    glVertex3f(70.0, 150.0, 3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(140.0, -165.0, 5);
    glVertex3f(140.0, 150.0, 5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, -165.0, 3);
    glVertex3f(140.0, 150.0, 3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(140.0, -165.0, 1.1);
    glVertex3f(140.0, 150.0, 1.1);
    glVertex3f(119.0, 150.0, 1.1);
    glVertex3f(119.0, -165.0, 1.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(140.0, -165.0, 1.1);
    glVertex3f(140.0, 150.0, 1.1);
    glVertex3f(119.0, 150.0, 1.1);
    glVertex3f(119.0, -165.0, 1.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -165.0, 1.1);
    glVertex3f(70.0, 150.0, 1.1);
    glVertex3f(91.0, 150.0, 1.1);
    glVertex3f(91.0, -165.0, 1.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(70.0, -165.0, 1.1);
    glVertex3f(70.0, 150.0, 1.1);
    glVertex3f(91.0, 150.0, 1.1);
    glVertex3f(91.0, -165.0, 1.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(119.0, -90.0, 1.1);
    glVertex3f(119.0, 150.0, 1.1);
    glVertex3f(91.0, 150.0, 1.1);
    glVertex3f(91.0, -90.0, 1.1);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(119.0, -90.0, 1.0);
    glVertex3f(119.0, 150.0, 1.0);
    glVertex3f(91.0, 150.0, 1.0);
    glVertex3f(91.0, -90.0, 1.0);
    glEnd();

    //kusen jendela
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(103.0, -90.0, 1.3);
    glVertex3f(103.0, 150.0, 1.3);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(109.0, -90.0, 1.3);
    glVertex3f(109.0, 150.0, 1.3);
    glEnd();

    //kusen jendela
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(128.0, -165.0, 1.3);
    glVertex3f(128.0, 150.0, 1.3);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(132.0, -165.0, 1.3);
    glVertex3f(132.0, 150.0, 1.3);
    glEnd();

    //kusen jendela
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(78.0, -165.0, 1.3);
    glVertex3f(78.0, 150.0, 1.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(84.0, -165.0, 1.3);
    glVertex3f(84.0, 150.0, 1.3);
    glEnd();

    //kusen jendela
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, 50.0, 1.3);
    glVertex3f(70.0, 70.0, 1.3);
    glVertex3f(160.0, 70.0, 1.3);
    glVertex3f(160.0, 50.0, 1.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, 150.0, 1.3);
    glVertex3f(70.0, 135.0, 1.3);
    glVertex3f(160.0, 135.0, 1.3);
    glVertex3f(160.0, 150.0, 1.3);
    glEnd();

    //kusen jendela
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -20.0, 1.3);
    glVertex3f(70.0, 0.0, 1.3);
    glVertex3f(160.0, 0.0, 1.3);
    glVertex3f(160.0, -20.0, 1.3);
    glEnd();

    //kusen jendela
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -90.0, 1.3);
    glVertex3f(70.0, -70.0, 1.3);
    glVertex3f(160.0, -70.0, 1.3);
    glVertex3f(160.0, -90.0, 1.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -165.0, 4);
    glVertex3f(70.0, -140.0, 4);
    glVertex3f(91.0, -140.0, 4);
    glVertex3f(91.0, -165.0, 4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, -140.0, 1.3);
    glVertex3f(70.0, -140.0, 4);
    glVertex3f(91.0, -140.0, 4);
    glVertex3f(91.0, -140.0, 1.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(91.0, -165.0, 1.3);
    glVertex3f(91.0, -140.0, 1.3);
    glVertex3f(91.0, -140.0, 4);
    glVertex3f(91.0, -165.0, 4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(119.0, -165.0, 4);
    glVertex3f(119.0, -140.0, 4);
    glVertex3f(140.0, -140.0, 4);
    glVertex3f(140.0, -165.0, 4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(119.0, -140.0, 1.3);
    glVertex3f(119.0, -140.0, 4);
    glVertex3f(140.0, -140.0, 4);
    glVertex3f(140.0, -140.0, 1.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(119.0, -165.0, 1.3);
    glVertex3f(119.0, -140.0, 1.3);
    glVertex3f(119.0, -140.0, 4);
    glVertex3f(119.0, -165.0, 4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(119.0, -165.0, 1.3);
    glVertex3f(119.0, -140.0, 1.3);
    glVertex3f(119.0, -140.0, 4);
    glVertex3f(119.0, -165.0, 4);
    glEnd();

    //bendera
    //--tiang--
    db(-62.0, -60.0, 0.0, 100.0, 0.5);      //depan
    db(-62.0, -60.0, 0.0, 100.0, -2.5);     //belakang
    kk(-62.0, 0.0, 100.0, 0.5, -2.5);       //kiri
    kk(-60.0, 0.0, 100.0, 0.5, -2.5);       //kanan
    ab(-62.0, -60.0, 100.0, 0.5, -2.5);     //atas

    glBegin(GL_QUADS);
    glColor3f(0, 0.05, 1);
    glVertex3f(-60.0, 100.0, -1.0);
    glVertex3f(-20.0, 100.0, -1.0);
    glVertex3f(-20.0, 60.0, -1.0);
    glVertex3f(-60.0, 60.0, -1.0);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0.02);
    glVertex3f(-58.0, 96.0, 0.1);
    glVertex3f(-20.0, 64.0, 0.1);
    glEnd();

    glLineWidth(9.0);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(-58.0, 96.0, 0.0);
    glVertex3f(-20.0, 64.0, 0.0);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0.02);
    glVertex3f(-58.0, 64.0, 0.1);
    glVertex3f(-20.0, 96.0, 0.1);
    glEnd();

    glLineWidth(9.0);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(-58.0, 64.0, 0.0);
    glVertex3f(-20.0, 96.0, 0.0);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0.02);
    glVertex3f(-39.0, 60.0, 0.3);
    glVertex3f(-39.0, 100.0, 0.3);
    glEnd();

    glLineWidth(11.0);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(-39.0, 60.0, 0.2);
    glVertex3f(-39.0, 100.0, 0.2);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0.02);
    glVertex3f(-58.0, 80.0, 0.3);
    glVertex3f(-20.0, 80.0, 0.3);
    glEnd();

    glLineWidth(11.0);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(-58.0, 80.0, 0.2);
    glVertex3f(-20.0, 80.0, 0.2);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0.02);
    glVertex3f(-58.0, 96.0, 0.1);
    glVertex3f(-20.0, 64.0, 0.1);
    glEnd();

    glLineWidth(9.0);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(-58.0, 96.0, 0.0);
    glVertex3f(-20.0, 64.0, 0.0);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0.02);
    glVertex3f(-58.0, 64.0, 0.1);
    glVertex3f(-20.0, 96.0, 0.1);
    glEnd();

    glLineWidth(9.0);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(-58.0, 64.0, 0.0);
    glVertex3f(-20.0, 96.0, 0.0);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0.02);
    glVertex3f(-39.0, 60.0, 0.3);
    glVertex3f(-39.0, 100.0, 0.3);
    glEnd();

    glLineWidth(11.0);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(-39.0, 60.0, 0.2);
    glVertex3f(-39.0, 100.0, 0.2);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0.02);
    glVertex3f(-58.0, 80.0, 0.3);
    glVertex3f(-20.0, 80.0, 0.3);
    glEnd();

    glLineWidth(11.0);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(-58.0, 80.0, 0.2);
    glVertex3f(-20.0, 80.0, 0.2);
    glEnd();

    //BENDERA BELAKANG
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0.02);
    glVertex3f(-58.0, 96.0, -1.2);
    glVertex3f(-20.0, 64.0, -1.2);
    glEnd();

    glLineWidth(9.0);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(-58.0, 96.0, -1.1);
    glVertex3f(-20.0, 64.0, -1.1);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0.02);
    glVertex3f(-58.0, 64.0, -1.2);
    glVertex3f(-20.0, 96.0, -1.2);
    glEnd();

    glLineWidth(9.0);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(-58.0, 64.0, -1.1);
    glVertex3f(-20.0, 96.0, -1.1);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0.02);
    glVertex3f(-39.0, 60.0, -1.4);
    glVertex3f(-39.0, 100.0, -1.4);
    glEnd();

    glLineWidth(11.0);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(-39.0, 60.0, -1.3);
    glVertex3f(-39.0, 100.0, -1.3);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0.02);
    glVertex3f(-58.0, 80.0, -1.4);
    glVertex3f(-20.0, 80.0, -1.4);
    glEnd();

    glLineWidth(11.0);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(-58.0, 80.0, -1.3);
    glVertex3f(-20.0, 80.0, -1.3);
    glEnd();

    //pintu
    //pilar kiri
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(97.0, -165.0, 7);
    glVertex3f(97.0, -90.0, 7);
    glVertex3f(93.0, -90.0, 7);
    glVertex3f(93.0, -165.0, 7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(93.0, -165.0, 1.3);
    glVertex3f(93.0, -90.0, 1.3);
    glVertex3f(93.0, -90.0, 7);
    glVertex3f(93.0, -165.0, 7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(97.0, -165.0, 1.3);
    glVertex3f(97.0, -90.0, 1.3);
    glVertex3f(97.0, -90.0, 7);
    glVertex3f(97.0, -165.0, 7);
    glEnd();

    //pilar kanan
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(117.0, -165.0, 7);
    glVertex3f(117.0, -90.0, 7);
    glVertex3f(113.0, -90.0, 7);
    glVertex3f(113.0, -165.0, 7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(113.0, -165.0, 1.3);
    glVertex3f(113.0, -90.0, 1.3);
    glVertex3f(113.0, -90.0, 7);
    glVertex3f(113.0, -165.0, 7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(117.0, -165.0, 1.3);
    glVertex3f(117.0, -90.0, 1.3);
    glVertex3f(117.0, -90.0, 7);
    glVertex3f(117.0, -165.0, 7);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(99.0, -80.0, 7);
    glVertex3f(97.0, -90.0, 7);
    glVertex3f(93.0, -90.0, 7);
    glVertex3f(91.0, -80.0, 7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(99.0, -80.0, 7);
    glVertex3f(99.0, -80.0, 1.3);
    glVertex3f(97.0, -90.0, 1.3);
    glVertex3f(97.0, -90.0, 7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(91.0, -80.0, 1.3);
    glVertex3f(91.0, -80.0, 7);
    glVertex3f(93.0, -90.0, 7);
    glVertex3f(93.0, -90.0, 1.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(99.0, -80.0, 1.3);
    glVertex3f(99.0, -80.0, 7);
    glVertex3f(91.0, -80.0, 7);
    glVertex3f(91.0, -80.0, 1.3);
    glEnd();

    //TANGGA-KANAN
    glColor3f(0.85, 0.76, 0.67);
    ab(97.0, 113.0, -158.0, 5.3, 1.3);
    glColor3f(0.6, 0.5, 0.4);
    db(97.0, 113.0, -160.0, -158.0, 5.3);
    //kiri
    kk(97.0, -165.0, -158.0, 5.3, 1.3);
    //kanan
    kk(113.0, -165.0, -158.0, 5.3, 1.3);

    glColor3f(0.85, 0.76, 0.67);
    ab(97.0, 113.0, -160.0, 9.3, 5.3);
    glColor3f(0.6, 0.5, 0.4);
    db(97.0, 113.0, -162.0, -160.0, 9.3);
    //kiri
    kk(97.0, -165.0, -160.0, 9.3, 5.3);
    //kanan
    kk(113.0, -165.0, -160.0, 9.3, 5.3);

    glColor3f(0.85, 0.76, 0.67);
    ab(97.0, 113.0, -162.0, 13.3, 9.3);
    glColor3f(0.6, 0.5, 0.4);
    db(97.0, 113.0, -164.0, -162.0, 13.3);
    //kiri
    kk(97.0, -165.0, -162.0, 13.3, 9.3);
    //kanan
    kk(113.0, -165.0, -162.0, 13.3, 9.3);

    glColor3f(0.85, 0.76, 0.67);
    ab(97.0, 113.0, -164.0, 17.3, 13.3);
    glColor3f(0.6, 0.5, 0.4);
    db(97.0, 113.0, -165.0, -164.0, 17.3);
    //kiri
    kk(97.0, -165.0, -164.0, 17.3, 13.3);
    //kanan
    kk(113.0, -165.0, -164.0, 17.3, 13.3);

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(119.0, -80.0, 7);
    glVertex3f(117.0, -90.0, 7);
    glVertex3f(113.0, -90.0, 7);
    glVertex3f(111.0, -80.0, 7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(119.0, -80.0, 7);
    glVertex3f(119.0, -80.0, 1.3);
    glVertex3f(117.0, -90.0, 1.3);
    glVertex3f(117.0, -90.0, 7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(111.0, -80.0, 1.3);
    glVertex3f(111.0, -80.0, 7);
    glVertex3f(113.0, -90.0, 7);
    glVertex3f(113.0, -90.0, 1.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(119.0, -80.0, 1.3);
    glVertex3f(119.0, -80.0, 7);
    glVertex3f(111.0, -80.0, 7);
    glVertex3f(111.0, -80.0, 1.3);
    glEnd();

    //KOTAKAN PINTU
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(93.0, -90.0, 6);
    glVertex3f(93.0, -100.0, 6);
    glVertex3f(117.0, -100.0, 6);
    glVertex3f(117.0, -90.0, 6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(93.0, -90.0, 6);
    glVertex3f(93.0, -90.0, 1.3);
    glVertex3f(117.0, -90.0, 1.3);
    glVertex3f(117.0, -90.0, 6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.75, 0.32, 0.22);
    glVertex3f(93.0, -165.0, 1.3);
    glVertex3f(93.0, -100.0, 1.3);
    glVertex3f(117.0, -100.0, 1.3);
    glVertex3f(117.0, -165.0, 1.3);
    glEnd();

    //LAPANGAN
    glBegin(GL_QUADS);
    glColor3f(0.69, 0.93, 0.45);
    glVertex3f(-150.0, -165.0, -140);
    glVertex3f(-150.0, -165.0, -300);
    glVertex3f(160.0, -165.0, -300);
    glVertex3f(160.0, -165.0, -140);
    glEnd();

    //KOLAM RENANG
    glBegin(GL_QUADS);
    glColor3f(0.46, 0.82, 0.96);
    glVertex3f(-140.0, -164.9, -250);
    glVertex3f(-140.0, -164.9, -290);
    glVertex3f(-50.0, -164.9, -290);
    glVertex3f(-50.0, -164.9, -250);
    glEnd();

    glLineWidth(100.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.66, 0.15, 0.15);
    glVertex3f(-140.0, -164.8, -250);
    glVertex3f(-140.0, -164.8, -290);
    glVertex3f(-50.0, -164.8, -290);
    glVertex3f(-50.0, -164.8, -250);
    glEnd();

    //tv
    glLineWidth(30.0);
    glBegin(GL_LINES);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(160, -20, -70);
    glVertex3f(157, -20, -70);
    glEnd();

    glLineWidth(30.0);
    glBegin(GL_LINES);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(160, -20, -65);
    glVertex3f(157, -20, -65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(156, -5, -40);
    glVertex3f(158, -35, -40);
    glVertex3f(158, -35, -90);
    glVertex3f(156, -5, -90);
    glEnd();

    glLineWidth(7.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.19, 0.19, 0.18);
    glVertex3f(156, -5, -40);
    glVertex3f(158, -35, -40);
    glVertex3f(158, -35, -90);
    glVertex3f(156, -5, -90);
    glEnd();

    //lampu taman
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(0.27, 0.27, 0.26);
    glVertex3f(-5, -165, -220);
    glVertex3f(-5, -20, -220);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.27, 0.27, 0.26);
    glVertex3f(-15, 0, -200);
    glVertex3f(5, 0, -200);
    glVertex3f(-4, -20, -220);
    glVertex3f(-6, -20, -220);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.27, 0.27, 0.26);
    glVertex3f(-15, 0, -240);
    glVertex3f(5, 0, -240);
    glVertex3f(-4, -20, -220);
    glVertex3f(-6, -20, -220);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.27, 0.27, 0.26);
    glVertex3f(-15, 0, -200);
    glVertex3f(-15, 0, -240);
    glVertex3f(-4, -20, -220);
    glVertex3f(-6, -20, -220);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.27, 0.27, 0.26);
    glVertex3f(5, 0, -200);
    glVertex3f(5, 0, -240);
    glVertex3f(-4, -20, -220);
    glVertex3f(-6, -20, -220);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.95, 0.95, 0.51);
    glVertex3f(-15, 0, -200);
    glVertex3f(5, 0, -200);
    glVertex3f(5, 0, -240);
    glVertex3f(-15, 0, -240);
    glEnd();

    //bagian belakang
     //jendela
    glLineWidth(6.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(140.0, -165.0, -140.1);
    glVertex3f(140.0, 150.0, -140.1);
    glVertex3f(119.0, 150.0, -140.1);
    glVertex3f(119.0, -165.0, -140.1);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, 30.0, -140.3);
    glVertex3f(140.0, 30.0, -140.3);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -40.0, -140.3);
    glVertex3f(140.0, -40.0, -140.3);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -110.0, -140.3);
    glVertex3f(91.0, -110.0, -140.3);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(140.0, -110.0, -140.3);
    glVertex3f(119.0, -110.0, -140.3);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(140.0, 120.0, -140.3);
    glVertex3f(70.0, 120.0, -140.3);
    glEnd();

    glLineWidth(9.0);
    glBegin(GL_LINES);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(119.0, -165.0, -143);
    glVertex3f(119.0, 150.0, -143);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(119.0, -165.0, -145);
    glVertex3f(119.0, 150.0, -145);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(91.0, -165.0, -145);
    glVertex3f(91.0, 150.0, -145);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(91.0, -165.0, -143);
    glVertex3f(91.0, 150.0, -143);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -165.0, -145);
    glVertex3f(70.0, 150.0, -145);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, -165.0, -143);
    glVertex3f(70.0, 150.0, -143);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(140.0, -165.0, -145);
    glVertex3f(140.0, 150.0, -145);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, -165.0, -143);
    glVertex3f(140.0, 150.0, -143);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(140.0, -165.0, -141.1);
    glVertex3f(140.0, 150.0, -141.1);
    glVertex3f(119.0, 150.0, -141.1);
    glVertex3f(119.0, -165.0, -141.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(140.0, -165.0, -141.1);
    glVertex3f(140.0, 150.0, -141.1);
    glVertex3f(119.0, 150.0, -141.1);
    glVertex3f(119.0, -165.0, -141.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -165.0, -141.1);
    glVertex3f(70.0, 150.0, -141.1);
    glVertex3f(91.0, 150.0, -141.1);
    glVertex3f(91.0, -165.0, -141.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(70.0, -165.0, -141.1);
    glVertex3f(70.0, 150.0, -141.1);
    glVertex3f(91.0, 150.0, -141.1);
    glVertex3f(91.0, -165.0, -141.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(119.0, -90.0, -141.1);
    glVertex3f(119.0, 150.0, -141.1);
    glVertex3f(91.0, 150.0, -141.1);
    glVertex3f(91.0, -90.0, -141.1);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(119.0, -90.0, -141.0);
    glVertex3f(119.0, 150.0, -141.0);
    glVertex3f(91.0, 150.0, -141.0);
    glVertex3f(91.0, -90.0, -141.0);
    glEnd();

    //kusen jendela
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(103.0, -90.0, -141.3);
    glVertex3f(103.0, 150.0, -141.3);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(109.0, -90.0, -141.3);
    glVertex3f(109.0, 150.0, -141.3);
    glEnd();

    //kusen jendela
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(128.0, -165.0, -141.3);
    glVertex3f(128.0, 150.0, -141.3);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(132.0, -165.0, -141.3);
    glVertex3f(132.0, 150.0, -141.3);
    glEnd();

    //kusen jendela
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(78.0, -165.0, -141.3);
    glVertex3f(78.0, 150.0, -141.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(84.0, -165.0, -141.3);
    glVertex3f(84.0, 150.0, -141.3);
    glEnd();

    //kusen jendela
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, 50.0, -141.3);
    glVertex3f(70.0, 70.0, -141.3);
    glVertex3f(160.0, 70.0, -141.3);
    glVertex3f(160.0, 50.0, -141.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, 150.0, -141.3);
    glVertex3f(70.0, 135.0, -141.3);
    glVertex3f(160.0, 135.0, -141.3);
    glVertex3f(160.0, 150.0, -141.3);
    glEnd();

    //kusen jendela
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -20.0, -141.3);
    glVertex3f(70.0, 0.0, -141.3);
    glVertex3f(160.0, 0.0, -141.3);
    glVertex3f(160.0, -20.0, -141.3);
    glEnd();

    //kusen jendela
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -90.0, -141.3);
    glVertex3f(70.0, -70.0, -141.3);
    glVertex3f(160.0, -70.0, -141.3);
    glVertex3f(160.0, -90.0, -141.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, -165.0, -144);
    glVertex3f(70.0, -140.0, -144);
    glVertex3f(91.0, -140.0, -144);
    glVertex3f(91.0, -165.0, -144);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, -140.0, -141.3);
    glVertex3f(70.0, -140.0, -144);
    glVertex3f(91.0, -140.0, -144);
    glVertex3f(91.0, -140.0, -141.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(91.0, -165.0, -141.3);
    glVertex3f(91.0, -140.0, -141.3);
    glVertex3f(91.0, -140.0, -144);
    glVertex3f(91.0, -165.0, -144);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(119.0, -165.0, -144);
    glVertex3f(119.0, -140.0, -144);
    glVertex3f(140.0, -140.0, -144);
    glVertex3f(140.0, -165.0, -144);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(119.0, -140.0, -141.3);
    glVertex3f(119.0, -140.0, -144);
    glVertex3f(140.0, -140.0, -144);
    glVertex3f(140.0, -140.0, -141.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(119.0, -165.0, -141.3);
    glVertex3f(119.0, -140.0, -141.3);
    glVertex3f(119.0, -140.0, -144);
    glVertex3f(119.0, -165.0, -144);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(119.0, -165.0, -141.3);
    glVertex3f(119.0, -140.0, -141.3);
    glVertex3f(119.0, -140.0, -144);
    glVertex3f(119.0, -165.0, -144);
    glEnd();

    //tembok2 bagian belakang

    //tembok kiri menonjol
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(48.5, -157.0, -155.0);
    glVertex3f(48.5, 175.5, -155.0);
    glVertex3f(70.0, 175.5, -155.0);
    glVertex3f(70.0, -157.0, -155.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(48.5, 175.0, -155.0);
    glVertex3f(48.5, 190.5, -155.0);
    glVertex3f(52.0, 190.5, -155.0);
    glVertex3f(52.0, 175.0, -155.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(52.0, 175.0, -155.0);
    glVertex3f(52.0, 181.5, -155.0);
    glVertex3f(57.0, 181.5, -155.0);
    glVertex3f(57.0, 175.0, -155.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(57.0, 175.0, -155.0);
    glVertex3f(57.0, 190.5, -155.0);
    glVertex3f(60.5, 190.5, -155.0);
    glVertex3f(60.5, 175.0, -155.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(60.5, 175.0, -155.0);
    glVertex3f(60.5, 181.5, -155.0);
    glVertex3f(66.5, 181.5, -155.0);
    glVertex3f(66.5, 175.0, -155.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(66.5, 175.0, -155.0);
    glVertex3f(66.5, 190.5, -155.0);
    glVertex3f(70.0, 190.5, -155.0);
    glVertex3f(70.0, 175.0, -155.0);
    glEnd();

    //tembok kiri menonjol sisi kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, 175.0, -140.0);
    glVertex3f(50.0, 175.5, -155.0);
    glVertex3f(50.0, -157.0, -155.0);
    glVertex3f(50.0, -165.0, -140.0);
    glEnd();
    //kiri
 //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, 191.0, -140.0);
    glVertex3f(50.0, 191.5, -143.5);
    glVertex3f(50.0, 175.0, -143.5);
    glVertex3f(50.0, 175.0, -140.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, 181.0, -143.5);
    glVertex3f(50.0, 181.5, -145.5);
    glVertex3f(50.0, 175.0, -145.5);
    glVertex3f(50.0, 175.0, -143.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, 191.0, -145.5);
    glVertex3f(50.0, 191.5, -148.5);
    glVertex3f(50.0, 175.0, -148.5);
    glVertex3f(50.0, 175.0, -146.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, 181.0, -148.5);
    glVertex3f(50.0, 181.5, -151.5);
    glVertex3f(50.0, 175.0, -151.5);
    glVertex3f(50.0, 175.0, -148.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, 191.0, -151.5);
    glVertex3f(50.0, 191.5, -155.0);
    glVertex3f(50.0, 175.0, -155.0);
    glVertex3f(50.0, 175.0, -151.5);
    glEnd();
    //tembok kiri menonjol sisi kanan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, 175.0, -140.0);
    glVertex3f(70.0, 175.5, -155.0);
    glVertex3f(70.0, -157.0, -155.0);
    glVertex3f(70.0, -165.0, -140.0);
    glEnd();
    //kanan
 //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, 191.0, -140.0);
    glVertex3f(70.0, 191.5, -143.5);
    glVertex3f(70.0, 175.0, -143.5);
    glVertex3f(70.0, 175.0, -140.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, 181.0, -143.5);
    glVertex3f(70.0, 181.5, -145.5);
    glVertex3f(70.0, 175.0, -145.5);
    glVertex3f(70.0, 175.0, -143.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, 191.0, -145.5);
    glVertex3f(70.0, 191.5, -148.5);
    glVertex3f(70.0, 175.0, -148.5);
    glVertex3f(70.0, 175.0, -146.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, 181.0, -148.5);
    glVertex3f(70.0, 181.5, -151.5);
    glVertex3f(70.0, 175.0, -151.5);
    glVertex3f(70.0, 175.0, -148.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70.0, 191.0, -151.5);
    glVertex3f(70.0, 191.5, -155.0);
    glVertex3f(70.0, 175.0, -155.0);
    glVertex3f(70.0, 175.0, -151.5);
    glEnd();
    //tembok kiri menonjol bawah
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.2, 0.2);
    glVertex3f(48.5, -157.0, -158.0);
    glVertex3f(48.5, -140.0, -158.0);
    glVertex3f(70.0, -140.0, -158.0);
    glVertex3f(70.0, -157.0, -158.0);
    glEnd();
    //tembok kiri menonjol bawah sisi kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50, -157.0, -158.0);
    glVertex3f(50, -140.0, -158.0);
    glVertex3f(50, -140.0, -155.0);
    glVertex3f(50, -157.0, -155.0);
    glEnd();

    //tembok kiri menonjol bawah sisi kanan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(70, -157.0, -158.0);
    glVertex3f(70, -140.0, -158.0);
    glVertex3f(70, -140.0, -155.0);
    glVertex3f(70, -157.0, -155.0);
    glEnd();

    //tembok kiri menonjol bawah sisi atas
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, -140.0, -155.0);
    glVertex3f(70.0, -140.0, -155.0);
    glVertex3f(70.0, -140.0, -158.0);
    glVertex3f(50.0, -140.0, -158.0);
    glEnd();

    //tembok kiri menonjol bawah sisi bawah
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, -157.0, -155.0);
    glVertex3f(70.0, -157.0, -155.0);
    glVertex3f(70.0, -157.0, -158.0);
    glVertex3f(50.0, -157.0, -158.0);
    glEnd();

    //tiang kiri sisi bawah
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, -157.0, -155.0);
    glVertex3f(70.0, -157.0, -155.0);
    glVertex3f(70.0, -165.0, -140.0);
    glVertex3f(50.0, -165.0, -140.0);
    glEnd();

    //tiang kiri sisi bawah
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(50.0, -157.0, -155.0);
    glVertex3f(70.0, -157.0, -155.0);
    glVertex3f(70.0, -165.0, -140.0);
    glVertex3f(50.0, -165.0, -140.0);
    glEnd();

    //tembok kanan menonjol
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(140.0, -157.0, -155.0);
    glVertex3f(140.0, 175.5, -155.0);
    glVertex3f(160.0, 175.5, -155.0);
    glVertex3f(160.0, -157.0, -155.0);
    glEnd();
    //depan
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(140.0, 175.0, -155.0);
    glVertex3f(140.0, 190.5, -155.0);
    glVertex3f(143.0, 190.5, -155.0);
    glVertex3f(143.0, 175.0, -155.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(143.0, 175.0, -155.0);
    glVertex3f(143.0, 181.5, -155.0);
    glVertex3f(147.5, 181.5, -155.0);
    glVertex3f(147.5, 175.0, -155.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(147.5, 175.0, -155.0);
    glVertex3f(147.5, 190.5, -155.0);
    glVertex3f(151.5, 190.5, -155.0);
    glVertex3f(151.5, 175.0, -155.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(151.5, 175.0, -155.0);
    glVertex3f(151.5, 181.5, -155.0);
    glVertex3f(157.0, 181.5, -155.0);
    glVertex3f(157.0, 175.0, -155.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(157.0, 175.0, -155.0);
    glVertex3f(157.0, 190.5, -155.0);
    glVertex3f(160.0, 190.5, -155.0);
    glVertex3f(160.0, 175.0, -155.0);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, -157.0, -155.0);
    glVertex3f(160.0, -157.0, -155.0);
    glVertex3f(160.0, -165.0, -140.0);
    glVertex3f(140.0, -165.0, -140.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 150, -140.0);
    glVertex3f(160.0, 150, -140.0);
    glVertex3f(160.0, 145.5, -155.0);
    glVertex3f(140.0, 145.5, -155.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, 175.0, -140.0);
    glVertex3f(160.0, 175.5, -155.0);
    glVertex3f(160.0, -157.0, -155.0);
    glVertex3f(160.0, -165.0, -140.0);
    glEnd();
    //kanan
//tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, 191.0, -140.0);
    glVertex3f(160.0, 191.5, -143.5);
    glVertex3f(160.0, 175.0, -143.5);
    glVertex3f(160.0, 175.0, -140.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, 181.0, -143.5);
    glVertex3f(160.0, 181.5, -145.5);
    glVertex3f(160.0, 175.0, -145.5);
    glVertex3f(160.0, 175.0, -143.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, 191.0, -145.5);
    glVertex3f(160.0, 191.5, -148.5);
    glVertex3f(160.0, 175.0, -148.5);
    glVertex3f(160.0, 175.0, -146.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, 181.0, -148.5);
    glVertex3f(160.0, 181.5, -151.5);
    glVertex3f(160.0, 175.0, -151.5);
    glVertex3f(160.0, 175.0, -148.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, 191.0, -151.5);
    glVertex3f(160.0, 191.5, -155.0);
    glVertex3f(160.0, 175.0, -155.0);
    glVertex3f(160.0, 175.0, -151.5);
    glEnd();


    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 175.0, -140.0);
    glVertex3f(140.0, 175.5, -155.0);
    glVertex3f(140.0, -157.0, -155.0);
    glVertex3f(140.0, -165.0, -140.0);
    glEnd();
    //kiri
//tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 191.0, -140.0);
    glVertex3f(140.0, 191.5, -143.5);
    glVertex3f(140.0, 175.0, -143.5);
    glVertex3f(140.0, 175.0, -140.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 181.0, -143.5);
    glVertex3f(140.0, 181.5, -145.5);
    glVertex3f(140.0, 175.0, -145.5);
    glVertex3f(140.0, 175.0, -143.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 191.0, -145.5);
    glVertex3f(140.0, 191.5, -148.5);
    glVertex3f(140.0, 175.0, -148.5);
    glVertex3f(140.0, 175.0, -146.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 181.0, -148.5);
    glVertex3f(140.0, 181.5, -151.5);
    glVertex3f(140.0, 175.0, -151.5);
    glVertex3f(140.0, 175.0, -148.5);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, 191.0, -151.5);
    glVertex3f(140.0, 191.5, -155.0);
    glVertex3f(140.0, 175.0, -155.0);
    glVertex3f(140.0, 175.0, -151.5);
    glEnd();

    //tembok kanan menonjol bawah
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.2, 0.2);
    glVertex3f(140.0, -157.0, -158.0);
    glVertex3f(140.0, -140.0, -158.0);
    glVertex3f(160.0, -140.0, -158.0);
    glVertex3f(160.0, -157.0, -158.0);
    glEnd();

    //tembok kanan menonjol bawah sisi kiri
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(140.0, -157.0, -158.0);
    glVertex3f(140.0, -140.0, -158.0);
    glVertex3f(140.0, -140.0, -155.0);
    glVertex3f(140.0, -157.0, -155.0);
    glEnd();

    //tembok kanan menonjol bawah sisi kanan
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(160.0, -157.0, -158.0);
    glVertex3f(160.0, -140.0, -158.0);
    glVertex3f(160.0, -140.0, -155.0);
    glVertex3f(160.0, -157.0, -155.0);
    glEnd();

    //tembok kanan menonjol bawah sisi atas
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(138.5, -140.0, -155.0);
    glVertex3f(160.0, -140.0, -155.0);
    glVertex3f(160.0, -140.0, -158.0);
    glVertex3f(138.5, -140.0, -158.0);
    glEnd();

    //tembok kanan menonjol bawah sisi bawah
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(138.5, -157.0, -155.0);
    glVertex3f(160.0, -157.0, -155.0);
    glVertex3f(160.0, -157.0, -158.0);
    glVertex3f(138.5, -157.0, -158.0);
    glEnd();
    //jendela kiri pinggir paling bawah
    //1
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(54.0, -128.0, -158.0);
    glVertex3f(54.0, -108.0, -158.0);
    glVertex3f(63.0, -108.0, -158.0);
    glVertex3f(63.0, -128.0, -158.0);
    glEnd();
    //2
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(54.0, -70.0, -158.0);
    glVertex3f(54.0, -50.0, -158.0);
    glVertex3f(63.0, -50.0, -158.0);
    glVertex3f(63.0, -70.0, -158.0);
    glEnd();
    //3
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(54.0, -12.0, -158.0);
    glVertex3f(54.0, 8.0, -158.0);
    glVertex3f(63.0, 8.0, -158.0);
    glVertex3f(63.0, -12.0, -158.0);
    glEnd();
    //kusen jendela
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(58.5, -128.0, -158.5);
    glVertex3f(58.5, 8.0, -158.5);
    glEnd();
    //depan
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(70.0, 150.0, -142.0);
    glVertex3f(70.0, 170.5, -142.0);
    glVertex3f(80.0, 170.5, -142.0);
    glVertex3f(80.0, 150.0, -142.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(80.0, 150.0, -142.0);
    glVertex3f(80.0, 157.5, -142.0);
    glVertex3f(90.5, 157.5, -142.0);
    glVertex3f(90.5, 150.0, -142.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(90.0, 150.0, -142.0);
    glVertex3f(90.0, 170.5, -142.0);
    glVertex3f(100.0, 170.5, -142.0);
    glVertex3f(100.0, 150.0, -142.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(100.0, 150.0, -142.0);
    glVertex3f(100.0, 157.5, -142.0);
    glVertex3f(110.5, 157.5, -142.0);
    glVertex3f(110.5, 150.0, -142.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(110.0, 150.0, -142.0);
    glVertex3f(110.0, 170.5, -142.0);
    glVertex3f(120.0, 170.5, -142.0);
    glVertex3f(120.0, 150.0, -142.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(120.0, 150.0, -142.0);
    glVertex3f(120.0, 157.5, -142.0);
    glVertex3f(130.5, 157.5, -142.0);
    glVertex3f(130.5, 150.0, -142.0);
    glEnd();
    //tembok bergerigi
    glBegin(GL_QUADS);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(130.0, 150.0, -142.0);
    glVertex3f(130.0, 170.5, -142.0);
    glVertex3f(140.0, 170.5, -142.0);
    glVertex3f(140.0, 150.0, -142.0);
    glEnd();

    //pintu belakang
    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(93.0, -90.0, -143.0);
    glVertex3f(117.0, -90.0, -143.0);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(93.0, -90.0, -142.0);
    glVertex3f(117.0, -90.0, -142.0);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(93.0, -90.0, -142.0);
    glVertex3f(93.0, -165.0, -142.0);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(93.0, -90.0, -143.0);
    glVertex3f(93.0, -165.0, -143.0);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.6, 0.5, 0.4);
    glVertex3f(117.0, -90.0, -142.0);
    glVertex3f(117.0, -165.0, -142.0);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.85, 0.76, 0.67);
    glVertex3f(117.0, -90.0, -143.0);
    glVertex3f(117.0, -165.0, -143.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(93.0, -90.0, -141.0);
    glVertex3f(117.0, -90.0, -141.0);
    glVertex3f(117.0, -165.0, -141.0);
    glVertex3f(93.0, -165.0, -141.0);
    glEnd();

    //dinding-belakang
    glColor3f(0.85, 0.76, 0.67);
    db(50.0, 160.0, -165.0, 150.0, -140.0);

    //MEJA KURSI DI TAMAN
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -140.0, -200.0);
    glVertex3f(120.0, -140.0, -200.0);
    glVertex3f(120.0, -140.0, -235.0);
    glVertex3f(20.0, -140.0, -235.0);
    glEnd();

    glLineWidth(8.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -140.0, -200.0);
    glVertex3f(120.0, -140.0, -200.0);
    glVertex3f(120.0, -140.0, -235.0);
    glVertex3f(20.0, -140.0, -235.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -140.0, -200.0);
    glVertex3f(20.0, -165.0, -200.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(120.0, -140.0, -200.0);
    glVertex3f(120.0, -165.0, -200.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -140.0, -235.0);
    glVertex3f(20.0, -165.0, -235.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(120.0, -140.0, -235.0);
    glVertex3f(120.0, -165.0, -235.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -237.0);
    glVertex3f(120.0, -150.0, -237.0);
    glVertex3f(120.0, -150.0, -255.0);
    glVertex3f(20.0, -150.0, -255.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -237.0);
    glVertex3f(120.0, -150.0, -237.0);
    glVertex3f(120.0, -150.0, -255.0);
    glVertex3f(20.0, -150.0, -255.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -237.0);
    glVertex3f(20.0, -165.0, -237.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -255.0);
    glVertex3f(20.0, -165.0, -255.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(120.0, -150.0, -255.0);
    glVertex3f(120.0, -165.0, -255.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(120.0, -150.0, -237.0);
    glVertex3f(120.0, -165.0, -237.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -198.0);
    glVertex3f(120.0, -150.0, -198.0);
    glVertex3f(120.0, -150.0, -180.0);
    glVertex3f(20.0, -150.0, -180.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -198.0);
    glVertex3f(120.0, -150.0, -198.0);
    glVertex3f(120.0, -150.0, -180.0);
    glVertex3f(20.0, -150.0, -180.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -198.0);
    glVertex3f(20.0, -165.0, -198.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -180.0);
    glVertex3f(20.0, -165.0, -180.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(120.0, -150.0, -198.0);
    glVertex3f(120.0, -165.0, -198.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(120.0, -150.0, -180.0);
    glVertex3f(120.0, -165.0, -180.0);
    glEnd();

    //MEJA KURSI DI TAMAN
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -140.0, -200.0);
    glVertex3f(120.0, -140.0, -200.0);
    glVertex3f(120.0, -140.0, -235.0);
    glVertex3f(20.0, -140.0, -235.0);
    glEnd();

    glLineWidth(8.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -140.0, -200.0);
    glVertex3f(120.0, -140.0, -200.0);
    glVertex3f(120.0, -140.0, -235.0);
    glVertex3f(20.0, -140.0, -235.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -140.0, -200.0);
    glVertex3f(20.0, -160.0, -200.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(120.0, -140.0, -200.0);
    glVertex3f(120.0, -160.0, -200.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -140.0, -235.0);
    glVertex3f(20.0, -160.0, -235.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(120.0, -140.0, -235.0);
    glVertex3f(120.0, -160.0, -235.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -237.0);
    glVertex3f(120.0, -150.0, -237.0);
    glVertex3f(120.0, -150.0, -255.0);
    glVertex3f(20.0, -150.0, -255.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -237.0);
    glVertex3f(120.0, -150.0, -237.0);
    glVertex3f(120.0, -150.0, -255.0);
    glVertex3f(20.0, -150.0, -255.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -237.0);
    glVertex3f(20.0, -160.0, -237.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -255.0);
    glVertex3f(20.0, -160.0, -255.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(120.0, -150.0, -255.0);
    glVertex3f(120.0, -160.0, -255.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(120.0, -150.0, -237.0);
    glVertex3f(120.0, -160.0, -237.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -198.0);
    glVertex3f(120.0, -150.0, -198.0);
    glVertex3f(120.0, -150.0, -180.0);
    glVertex3f(20.0, -150.0, -180.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -198.0);
    glVertex3f(120.0, -150.0, -198.0);
    glVertex3f(120.0, -150.0, -180.0);
    glVertex3f(20.0, -150.0, -180.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -198.0);
    glVertex3f(20.0, -160.0, -198.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(20.0, -150.0, -180.0);
    glVertex3f(20.0, -160.0, -180.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(120.0, -150.0, -198.0);
    glVertex3f(120.0, -160.0, -198.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9, 0.3, 0.16);
    glVertex3f(120.0, -150.0, -180.0);
    glVertex3f(120.0, -160.0, -180.0);
    glEnd();

    //kursi
//senderan depan
    glBegin(GL_QUADS);
    glColor3f(0.721, 0.52, 0.04);
    glVertex3f(150.5, -147.0, 20.0);
    glVertex3f(150.5, -123.0, 20.0);
    glVertex3f(180.0, -123.0, 20.0);
    glVertex3f(180.0, -147.0, 20.0);
    glEnd();
    //senderan belakang
    glBegin(GL_QUADS);
    glColor3f(0.721, 0.52, 0.04);
    glVertex3f(150.5, -160.0, 19.0);
    glVertex3f(150.5, -124.0, 19.0);
    glVertex3f(180.0, -124.0, 19.0);
    glVertex3f(180.0, -160.0, 19.0);
    glEnd();
    //dudukan
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.16, 0.16);
    glVertex3f(150, -147.0, 19.0);
    glVertex3f(180, -147.0, 19.0); //belakang
    glVertex3f(180, -147.0, 30.0); //depan kanan
    glVertex3f(150, -147.0, 30.0); //depan kiri
    glEnd();
    //dudukan
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.16, 0.16);
    glVertex3f(150, -148.0, 19.0);
    glVertex3f(180, -148.0, 19.0); //belakang
    glVertex3f(180, -148.0, 30.0); //depan kanan
    glVertex3f(150, -148.0, 30.0); //depan kiri
    glEnd();
    //kaki depan
    glBegin(GL_QUADS);
    glColor3f(0.721, 0.52, 0.04);
    glVertex3f(150.5, -158.0, 30.0);
    glVertex3f(150.5, -148.0, 30.0);
    glVertex3f(180.0, -148.0, 30.0);
    glVertex3f(180.0, -158.0, 30.0);
    glEnd();
}

void komputer(float xkiri, float xkanan) {
    //KOMPUTER
    //--alas--
    //belakang
    glColor3f(1.0, 0.0, 0.0);
    db(xkiri + 5, xkanan - 5, -130.0, -129.0, -82.5);
    //depan
    db(xkiri + 5, xkanan - 5, -130.0, -129.0, -76.0);
    //atas
    ab(xkiri + 5, xkanan - 5, -129.0, -76.0, -82.5);
    //bawah
    ab(xkiri + 5, xkanan - 5, -130.0, -76.0, -82.5);
    //kiri
    kk(xkiri + 5, -130.0, -129.0, -76.0, -82.5);
    //kanan
    kk(xkanan - 5, -130.0, -129.0, -76.0, -82.5);
    //--layar--
    //belakang
    glColor3f(0.2, 0.2, 0.2);
    db(xkiri, xkanan, -127.0, -102.0, -80.0);
    //kiri
    kk(xkiri, -127.0, -102.0, -78.5, -80.0);
    //kanan
    kk(xkanan, -127.0, -102.0, -78.5, -80.0);
    //depankiri
    db(xkiri, xkiri + 1, -127.0, -102.0, -78.5);
    //depankanan
    db(xkanan - 1, xkanan, -127.0, -102.0, -78.5);
    //depanatas
    db(xkiri + 1, xkanan - 1, -103.0, -102.0, -78.5);
    //depanbawah
    db(xkiri + 1, xkanan - 1, -127.0, -126.0, -78.5);
    //depanatas2
    ab(xkiri + 1, xkanan - 1, -103.0, -78.5, -79.0);
    //depanbawah2
    ab(xkiri + 1, xkanan - 1, -126.0, -78.5, -79.0);
    //depankiri2
    kk(xkiri + 1, -126.0, -103.0, -78.5, -79.0);
    //depankanan2
    kk(xkanan - 1, -126.0, -103.0, -78.5, -79.0);
    //monitor
    glColor3f(0.0, 0.0, 0.0);
    db(xkiri + 1, xkanan - 1, -126.0, -103.0, -79.0);
    //--sandaran--
    //depan
    glColor3f(0.2, 0.2, 0.2);
    db(xkiri + 7.5, xkanan - 7.5, -129.0, -126.0, -79.0);
    //belakang
    db(xkiri + 7.5, xkanan - 7.5, -129.0, -126.0, -79.5);
    //kiri
    kk(xkiri + 7.5, -129.0, -126.0, -79.0, -79.5);
    //kanan
    kk(xkanan - 7.5, -129.0, -126.0, -79.0, -79.5);

    //KEYBOARD
    glColor3f(0.0, 0.0, 0.0);
    //depan
    db(xkiri, xkanan, -130.0, -128.0, -55.0);
    //belakang
    db(xkiri, xkanan, -130.0, -128.0, -70.0);
    //kiri
    kk(xkiri, -130.0, -128.0, -55.0, -70.0);
    //kanan
    kk(xkanan, -130.0, -128.0, -55.0, -70.0);
    //atas
    ab(xkiri, xkanan, -128.0, -55.0, -70.0);
    //bawah
    ab(xkiri, xkanan, -130.0, -55.0, -70.0);

    //CPU
    //belakang
    glColor3f(0.2, 0.2, 0.2);
    db(xkanan + 3, xkanan + 13, -130.0, -100.0, -82.0);
    //depan
    db(xkanan + 3, xkanan + 13, -130.0, -100.0, -62.0);
    //kiri
    kk(xkanan + 3, -130.0, -100.0, -62.0, -82.0);
    //kanan
    kk(xkanan + 13, -130.0, -100.0, -62.0, -82.0);
}

void isi() {
    //db(-165.0, 50.0, -165.0, -10.0, 0.0);
    //MEJA
    //bawah
    glColor3f(0.61, 0.41, 0.25);
    ab(-145.0, 10.0, -135.0, -50.0, -90.0);
    //depan
    glColor3f(0.0, 0.0, 0.0);
    db(-145.0, 10.0, -135.0, -130.0, -50.0);
    //belakang
    db(-145.0, 10.0, -135.0, -130.0, -90.0);
    //kiri
    kk(-145.0, -135.0, -130.0, -50.0, -90.0);
    //kanan
    kk(10.0, -135.0, -130.0, -50.0, -90.0);
    //atas
    glColor3f(0.61, 0.41, 0.25);
    ab(-145.0, 10.0, -130.0, -50.0, -90.0);

    //KAKI MEJA
    //--kiri depan--
    //depan
    db(-145.0, -142.0, -165.0, -135.0, -50.0);
    //belakang
    db(-145.0, -142.0, -165.0, -135.0, -53.0);
    //kiri
    kk(-145.0, -165.0, -135.0, -50.0, -53.0);
    //kanan
    kk(-142.0, -165.0, -135.0, -50.0, -53.0);
    //--kiri belakang--
    //depan
    db(-145.0, -142.0, -165.0, -135.0, -90.0);
    //belakang
    db(-145.0, -142.0, -165.0, -135.0, -87.0);
    //kiri
    kk(-145.0, -165.0, -135.0, -90.0, -87.0);
    //kanan
    kk(-142.0, -165.0, -135.0, -90.0, -87.0);
    //--kanan depan--
    //depan
    db(7.0, 10.0, -165.0, -135.0, -50.0);
    //belakang
    db(7.0, 10.0, -165.0, -135.0, -53.0);
    //kiri
    kk(7.0, -165.0, -135.0, -50.0, -53.0);
    //kanan
    kk(10.0, -165.0, -135.0, -50.0, -53.0);
    //--kanan belakang--
    //depan
    db(7.0, 10, -165.0, -135.0, -90.0);
    //belakang
    db(7.0, 10, -165.0, -135.0, -87.0);
    //kiri
    kk(7.0, -165.0, -135.0, -90.0, -87.0);
    //kanan
    kk(10.0, -165.0, -135.0, -90.0, -87.0);

    //PAPAN TULIS
    //--belakang--
    glColor3f(0.5, 0.5, 0.5);
    db(-145.0, 10.0, -130.0, -30.0, -139.995);
    //--depan--
    glColor3f(1.0, 1.0, 1.0);
    db(-142.0, 7.0, -127.0, -33.0, -139.5);
    //depankiri
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-145.0, -130.0, -139.0);
    glVertex3f(-145.0, -30.0, -139.0);
    glVertex3f(-142.0, -33.0, -139.5);
    glVertex3f(-142.0, -127.0, -139.5);
    glEnd();
    //depankanan
    glBegin(GL_QUADS);
    glVertex3f(10.0, -130.0, -139.0);
    glVertex3f(10.0, -30.0, -139.0);
    glVertex3f(7.0, -33.0, -139.5);
    glVertex3f(7.0, -127.0, -139.5);
    glEnd();
    //depanatas
    glBegin(GL_QUADS);
    glVertex3f(-142.0, -33.0, -139.0);
    glVertex3f(-145.0, -30.0, -139.0);
    glVertex3f(10.0, -30.0, -139.5);
    glVertex3f(7.0, -33.0, -139.5);
    glEnd();
    //depanbawah
    glBegin(GL_QUADS);
    glVertex3f(-142.0, -127.0, -139.0);
    glVertex3f(-145.0, -130.0, -139.0);
    glVertex3f(10.0, -130.0, -139.5);
    glVertex3f(7.0, -127.0, -139.5);
    glEnd();
    //--kiri--
    kk(-145.0, -130.0, -30.0, -139.995, -139.0);
    //--kanan--
    kk(10.0, -130.0, -30.0, -139.995, -139.0);
    //--tempat penghapus--
    glColor3f(0.0, 0.0, 0.0);
    ab(-125.0, -10.0, -128.5, -135.0, -139.0);

    //KOMPUTER
    komputer(-140.0, -120.0);
    komputer(-105.0, -85.0);
    komputer(-65.0, -45.0);
    komputer(-25.0, -5.0);
}

void mobil() {
    //perintah animasi
    glPushMatrix();
    glTranslatef(gerak, 0, 0);

    //tengah
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(23.5, -155.0, 55.0);
    glVertex3f(23.5, -145.5, 55.0);
    glVertex3f(70.0, -145.5, 55.0);
    glVertex3f(70.0, -155.0, 55.0);
    glEnd();
    //tengah atas
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(28.5, -145.5, 55.0);
    glVertex3f(31.5, -130.5, 55.0);
    glVertex3f(67.0, -130.5, 55.0);
    glVertex3f(70.0, -145.5, 55.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(70.0, -155.0, 55.0);
    glVertex3f(70.0, -145.5, 55.0);
    glVertex3f(81.0, -145.5, 55.0);
    glVertex3f(81.0, -155.0, 55.0);
    glEnd();

    //tengah
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(23.5, -155.0, 35.0);
    glVertex3f(23.5, -145.5, 35.0);
    glVertex3f(70.0, -145.5, 35.0);
    glVertex3f(70.0, -155.0, 35.0);
    glEnd();
    //tengah atas
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(28.5, -145.5, 35.0);
    glVertex3f(31.5, -130.5, 35.0);
    glVertex3f(67.0, -130.5, 35.0);
    glVertex3f(70.0, -145.5, 35.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(70.0, -155.0, 35.0);
    glVertex3f(70.0, -145.5, 35.0);
    glVertex3f(81.0, -145.5, 35.0);
    glVertex3f(81.0, -155.0, 35.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(31, -130.5, 35.0);
    glVertex3f(67, -130.5, 35.0); //belakang
    glVertex3f(67, -130.5, 55.0); //depan kanan
    glVertex3f(31, -130.5, 55.0); //depan kiri
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(67.0, -130.0, 55.0);
    glVertex3f(70.0, -145.0, 55.0);
    glVertex3f(70.0, -145.0, 35.0);
    glVertex3f(67.0, -130.0, 35.0);
    glEnd();
    //kaca-depan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(67.1, -130.0, 53.0);
    glVertex3f(70.1, -145.0, 53.0);
    glVertex3f(70.1, -145.0, 38.0);
    glVertex3f(67.1, -130.0, 38.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(31.0, -130.0, 55.0);
    glVertex3f(28.0, -145.0, 55.0);
    glVertex3f(28.0, -145.0, 35.0);
    glVertex3f(31.0, -130.0, 35.0);
    glEnd();
    //tutup cap depan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(67, -145.5, 55.0);
    glVertex3f(80, -145.5, 55.0); //belakang
    glVertex3f(80, -145.5, 35.0); //depan kanan
    glVertex3f(67, -145.5, 35.0); //depan kiri
    glEnd();
    //tutup cap belakang
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(23, -145.5, 55.0);
    glVertex3f(28, -145.5, 55.0); //belakang
    glVertex3f(28, -145.5, 35.0); //depan kanan
    glVertex3f(23, -145.5, 35.0); //depan kiri
    glEnd();
    //tempat lampu
    //depan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(81.0, -145.0, 55.0);
    glVertex3f(81.0, -155.0, 55.0);
    glVertex3f(81.0, -155.0, 35.0);
    glVertex3f(81.0, -145.0, 35.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(23.0, -145.0, 55.0);
    glVertex3f(23.0, -155.0, 55.0);
    glVertex3f(23.0, -155.0, 35.0);
    glVertex3f(23.0, -145.0, 35.0);
    glEnd();
    //jendela 1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(50.5, -145.5, 55.1);
    glVertex3f(50.5, -130.5, 55.1);
    glVertex3f(62.0, -130.5, 55.1);
    glVertex3f(66.0, -145.5, 55.1);
    glEnd();
    //jendela 1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(50.5, -145.5, 35.1);
    glVertex3f(50.5, -130.5, 35.1);
    glVertex3f(62.0, -130.5, 35.1);
    glVertex3f(66.0, -145.5, 35.1);
    glEnd();

    //jendela 1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(32.0, -145.5, 55.1);
    glVertex3f(34.0, -130.5, 55.1);
    glVertex3f(48.5, -130.5, 55.1);
    glVertex3f(48.5, -145.5, 55.1);
    glEnd();
    //jendela 1
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(32.0, -145.5, 35.1);
    glVertex3f(34.0, -130.5, 35.1);
    glVertex3f(48.5, -130.5, 35.1);
    glVertex3f(48.5, -145.5, 35.1);
    glEnd();

    //ban depan1
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);

    radius = 400;
    jumlah_titik = 60;
    x_tengah = 3500;
    y_tengah = -15500;

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x / 100, y / 100, 55.1);
    }
    glEnd();
    glFlush();

    //ban depan2
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);

    radius = 400;
    jumlah_titik = 60;
    x_tengah = 6700;
    y_tengah = -15500;

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x / 100, y / 100, 55.1);
    }
    glEnd();
    glFlush();

    //ban belakang1
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);

    radius = 400;
    jumlah_titik = 60;
    x_tengah = 3500;
    y_tengah = -15500;

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x / 100, y / 100, 34.9);
    }
    glEnd();
    glFlush();

    //ban belakang2
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);

    radius = 400;
    jumlah_titik = 60;
    x_tengah = 6700;
    y_tengah = -15500;

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x / 100, y / 100, 34.9);
    }
    glEnd();
    glFlush();
    glPopMatrix();


}

void timer2(int t) {
    angle -= 6.3;
    glutPostRedisplay();

    glutTimerFunc(1000, timer2, 0);
}

void timer(int t)
{
    if (atas) {
        gerak += 1;
    }
    else {
        gerak -= 1;
    }
    if (gerak > 100) {
        atas = false;
    }
    else if (gerak < -200) {
        atas = true;
    }
    glutPostRedisplay();

    /*
    kecepatan mobil berbanding terbalik
    semakin besar nilai glutTimerFunc maka akan semakin pelan gerakannya
    note: angka 50
    */
    glutTimerFunc(50, timer, 0);
}

void jalan() {
    glColor3f(0.0, 0.0, 0.0);
    ab(-200.0, 200.0, -160.0, 57, 32);

    //garis
    glColor3f(1.0, 1.0, 1.0);
    ab(-180.0, -150.0, -159.9, 46.0, 43.0);
    ab(-120.0, -90.0, -159.9, 46.0, 43.0);
    ab(-60.0, -30.0, -159.9, 46.0, 43.0);
    ab(0.0, 30.0, -159.9, 46.0, 43.0);
    ab(60.0, 90.0, -159.9, 46.0, 43.0);
    ab(120.0, 150.0, -159.9, 46.0, 43.0);
    ab(180.0, 200.0, -159.9, 46.0, 43.0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(xrot, 0.0f, 1.0f, 0.0f);
    glRotatef(yrot, 1.0f, 0.0f, 0.0f);

    glTranslatef(xmov, ymov, zmov);
    tampil();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("University of Bristol");
    init();
    glutDisplayFunc(tampil);
    glutTimerFunc(1, timer, 0);
    glutTimerFunc(1, timer2, 0);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.53, 0.8, 0.98, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    //glOrtho(-100.0, 100.0, -100.0, 100.0, -0.0, 5.0);
    glPointSize(9.0);
    glLineWidth(6.0f);
}

void tampil(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    bangunan_kiri_belakang();
    bangunan_kiri_depan();
    bangunan_kanan();
    isi();
    jalan();
    mobil();
    jam();


    glPushMatrix();
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

void mouseMotion(int x, int y) {
    if (mouseDown) {
        xrot = x - xdiff;
        yrot = y + ydiff;

        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zmov += 10;
        break;
    case 'd':
    case 'D':
        xmov += 10;
        break;
    case 's':
    case 'S':
        zmov -= 10;
        break;
    case 'a':
    case 'A':
        xmov -= 10;
        break;
    case '7':
        ymov += 10;
        break;
    case '9':
        ymov -= 10;
        break;
    case '2':
        xrot += 10;
        break;
    case '8':
        xrot -= 10;
        break;
    case '6':
        yrot += 10;
        break;
    case '4':
        yrot -= 10;
        break;
    case '1':
        zrot += 10;
        break;
    case '3':
        zrot -= 10;
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    glutPostRedisplay();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, lebar / tinggi, 5.0, 5000.0);
    glViewport(0, 0, 900, 600);
    glTranslatef(0.0, -5.0, -220.0);
    glMatrixMode(GL_MODELVIEW);
}
