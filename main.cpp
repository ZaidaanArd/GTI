/*
 * FreeGLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone 
 * and torus shapes in FreeGLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include <GL/glut.h>

#include <stdlib.h>

#include <math.h> // Wajib ada untuk sin() dan cos()

void drawLingkaran(float centerX, float centerY, float radius, int jumlahSisi) {
    glBegin(GL_POLYGON); // Gunakan GL_POLYGON untuk lingkaran padat, atau GL_LINE_LOOP untuk garis tepi
    for (int i = 0; i < jumlahSisi; i++) {
        // Hitung sudut dalam radian
        float sudut = 2.0f * 3.1415926f * (float)i / (float)jumlahSisi;
        
        // Hitung koordinat x dan y
        float x = radius * cosf(sudut);
        float y = radius * sinf(sudut);
        
        // Gambar titiknya
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Gambar lingkaran warna biru di tengah (0,0)
    glColor3f(0.0, 0.0, 1.0);
    drawLingkaran(0.0, 0.0, 0.5, 50);
    glFlush();
}

void reshape(int w,int h){
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w<=h)
        gluOrtho2D(-1,1,-1*(float)h/w,1*(float)h/w);
    else
        gluOrtho2D(-1*(float)w/h,1*(float)w/h,-1,1);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    // 2. Tambahkan inisialisasi mode display
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    
    glutInitWindowSize(1920, 1080); 
    glutCreateWindow("Contoh glRect");
    
    glutDisplayFunc(display);
    
    // 3. Daftarkan fungsi reshape ke GLUT
    glutReshapeFunc(reshape); 
    
    glutMainLoop();
    return 0;
}
