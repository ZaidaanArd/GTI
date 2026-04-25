#include <GL/glut.h>
#include <cmath>

// Fungsi pembantu untuk membuat lingkaran
void drawCircle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float theta = i * 3.14159f / 180.0f;
        glVertex2f(cx + r * cosf(theta), cy + r * sinf(theta));
    }
    glEnd();
}

void drawWheel(float cx, float cy, float r) {
    glColor3ub(20, 20, 20);
    drawCircle(cx, cy, r);

    glColor3ub(190, 190, 190);
    drawCircle(cx, cy, r * 0.6f);

    glColor3ub(110, 110, 110);
    drawCircle(cx, cy, r * 0.22f);

    glColor3ub(145, 145, 145);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(cx - r * 0.45f, cy);
    glVertex2f(cx + r * 0.45f, cy);
    glVertex2f(cx, cy - r * 0.45f);
    glVertex2f(cx, cy + r * 0.45f);
    glVertex2f(cx - r * 0.3f, cy - r * 0.3f);
    glVertex2f(cx + r * 0.3f, cy + r * 0.3f);
    glVertex2f(cx - r * 0.3f, cy + r * 0.3f);
    glVertex2f(cx + r * 0.3f, cy - r * 0.3f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Bodi bawah mobil
    glBegin(GL_POLYGON);
    glColor3ub(198, 26, 30);
    glVertex2f(-145.0f, -10.0f);
    glVertex2f(-130.0f, 18.0f);
    glVertex2f(-88.0f, 26.0f);
    glVertex2f(120.0f, 26.0f);
    glVertex2f(148.0f, 8.0f);
    glVertex2f(152.0f, -10.0f);
    glVertex2f(132.0f, -24.0f);
    glVertex2f(-130.0f, -24.0f);
    glEnd();

    // Kabin atas
    glBegin(GL_POLYGON);
    glColor3ub(176, 18, 22);
    glVertex2f(-70.0f, 26.0f);
    glVertex2f(-35.0f, 76.0f);
    glVertex2f(45.0f, 76.0f);
    glVertex2f(90.0f, 26.0f);
    glEnd();

    // Highlight bodi
    glColor3ub(240, 95, 95);
    glRectf(-108.0f, 8.0f, 115.0f, 12.0f);

    // Kaca depan dan belakang
    glColor3ub(160, 220, 255);
    glBegin(GL_POLYGON);
    glVertex2f(-58.0f, 30.0f);
    glVertex2f(-29.0f, 72.0f);
    glVertex2f(0.0f, 72.0f);
    glVertex2f(0.0f, 30.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(6.0f, 30.0f);
    glVertex2f(6.0f, 72.0f);
    glVertex2f(39.0f, 72.0f);
    glVertex2f(77.0f, 30.0f);
    glEnd();

    // Pilar dan outline kaca
    glColor3ub(55, 20, 20);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
    glVertex2f(3.0f, 30.0f);
    glVertex2f(3.0f, 72.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-58.0f, 30.0f);
    glVertex2f(-29.0f, 72.0f);
    glVertex2f(0.0f, 72.0f);
    glVertex2f(0.0f, 30.0f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(6.0f, 30.0f);
    glVertex2f(6.0f, 72.0f);
    glVertex2f(39.0f, 72.0f);
    glVertex2f(77.0f, 30.0f);
    glEnd();

    // Garis pintu
    glBegin(GL_LINES);
    glVertex2f(-6.0f, -22.0f);
    glVertex2f(-6.0f, 26.0f);
    glVertex2f(64.0f, -22.0f);
    glVertex2f(64.0f, 26.0f);
    glEnd();

    // Handle pintu
    glColor3ub(230, 230, 230);
    glRectf(-32.0f, 4.0f, -17.0f, 8.0f);
    glRectf(17.0f, 4.0f, 32.0f, 8.0f);

    // Lampu depan, belakang, dan grille
    glColor3ub(255, 244, 180);
    glRectf(-145.0f, 4.0f, -132.0f, 16.0f);
    glColor3ub(255, 70, 60);
    glRectf(139.0f, 2.0f, 152.0f, 16.0f);
    glColor3ub(20, 20, 24);
    glRectf(-131.0f, -2.0f, -119.0f, 14.0f);

    // Bumper
    glColor3ub(95, 95, 100);
    glRectf(-153.0f, -18.0f, -138.0f, -6.0f);
    glRectf(145.0f, -18.0f, 160.0f, -6.0f);

    // Roda
    drawWheel(-72.0f, -24.0f, 27.0f);
    drawWheel(82.0f, -24.0f, 27.0f);

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200.0, 200.0, -150.0, 150.0); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 450); 
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil 2D Stylish");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}