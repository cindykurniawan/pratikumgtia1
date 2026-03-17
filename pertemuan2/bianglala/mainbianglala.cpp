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
#include <math.h>

float radius = 0.5;

// Fungsi menggambar lingkaran (roda)
void drawWheel()
{
    // Roda luar
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 100; i++)
    {
        float angle = 2 * 3.1416 * i / 100;
        glVertex2f(cos(angle) * radius, sin(angle) * radius);
    }
    glEnd();

    // Jari-jari roda
    glBegin(GL_LINES);
    for(int i = 0; i < 8; i++)
    {
        float angle = 2 * 3.1416 * i / 8;
        glVertex2f(0, 0);
        glVertex2f(cos(angle) * radius, sin(angle) * radius);
    }
    glEnd();

    // Pusat roda
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0, 0);
        for(int i = 0; i <= 20; i++)
        {
            float angle = 2 * 3.1416 * i / 20;
            glVertex2f(cos(angle) * 0.05, sin(angle) * 0.05);
        }
    glEnd();
}

// Fungsi menggambar kursi
void drawSeats()
{
    glColor3f(0.2, 0.6, 1.0);

    for(int i = 0; i < 8; i++)
    {
        float angle = 2 * 3.1416 * i / 8;
        float x = cos(angle) * radius;
        float y = sin(angle) * radius;

        glBegin(GL_QUADS);
            glVertex2f(x - 0.05, y - 0.15);
            glVertex2f(x + 0.05, y - 0.15);
            glVertex2f(x + 0.05, y - 0.05);
            glVertex2f(x - 0.05, y - 0.05);
        glEnd();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Geser roda ke atas
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.0);

    drawWheel();
    drawSeats();

    glPopMatrix();

    // Penyangga (GL_TRIANGLE_STRIP)
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.1, -0.5);
        glVertex2f(-0.05, -0.2);
        glVertex2f(0.1, -0.5);
        glVertex2f(0.05, -0.2);
    glEnd();

    // Tanah (GL_QUAD_STRIP)
    glColor3f(0.3, 0.8, 0.3);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(-1.0, -0.6);
        glVertex2f(-1.0, -0.8);
        glVertex2f(1.0, -0.6);
        glVertex2f(1.0, -0.8);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bianglala - OpenGL");

    glutDisplayFunc(display);
    glClearColor(0.5, 0.8, 1.0, 1.0); // background langit

    glutMainLoop();
    return 0;
}
