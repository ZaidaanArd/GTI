#include <GL/glut.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

static int shoulder = 0, elbow = 0, telapak = 0;
static int finger1 = 0, finger2 = 0, finger3 = 0;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Bagian Bahu
    glPushMatrix();
    glTranslatef(-3.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Bagian Sikut
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // telapak
    glPushMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)telapak, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();
    glScalef(1.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // // Finger 1
    float initalZIndexFinger = 0.25;
    for (int i = 0; i < 4; i++)
    {
        glPushMatrix();
        glTranslatef(0.5, -0.15, 0.38 - (initalZIndexFinger * i));
        glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0);
        glTranslatef(0.2, 0.0, 0.0);

        glPushMatrix();
        glScalef(0.4, 0.1, 0.25);
        glutWireCube(1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.2, 0.0, 0.0);
        glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);
        glTranslatef(0.15, 0.0, 0.0);

        glPushMatrix();
        glScalef(0.3, 0.1, 0.25);
        glutWireCube(1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.1, 0.0, 0.0);
        glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0);
        glTranslatef(0.1, 0.0, 0.0);

        glPushMatrix();
        glScalef(0.2, 0.1, 0.25);
        glutWireCube(1.0);
        glPopMatrix();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();
    }

    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        shoulder = (shoulder + 5) % 360;
        glutPostRedisplay();
        break;

    case 'S':
        shoulder = (shoulder - 5) % 360;
        glutPostRedisplay();
        break;

    case 'a':
        if (elbow <= 150)
        {
            elbow = (elbow + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'A':
        if (elbow > 0)
        {
            elbow = (elbow - 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'f':
        if (telapak <= 90)
        {
            telapak = (telapak + 5) % 360;
            glutPostRedisplay();
        }
        break;
    case 'F':
        if (telapak > -45)
        {
            telapak = (telapak - 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'w':
        if (finger1 <= 65)
        {
            finger1 = (finger1 + 5) % 360;
            finger2 = (finger1 + 5) % 360;
            finger3 = (finger2 + 5) % 360;
            glutPostRedisplay();
        }
        break;

    case 'W':
        if (finger1 - 5 >= 5)
        {
            finger1 = (finger1 - 5) % 360;
            finger2 = (finger1 - 5) % 360;
            finger3 = (finger2 - 5) % 360;
            glutPostRedisplay();
        }
        else if (finger1 - 5 == 0)
        {
            finger1 = 0;
            finger2 = 0;
            finger3 = 0;
            glutPostRedisplay();
        }
        break;

    case 27: // ESC
        exit(0);
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Robot Arm");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}