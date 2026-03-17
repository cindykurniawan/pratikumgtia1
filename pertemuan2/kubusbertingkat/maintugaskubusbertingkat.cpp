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

void kotak(float x, float y)
{
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x+0.2, y);
        glVertex2f(x+0.2, y-0.2);
        glVertex2f(x, y-0.2);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Warna biru muda
    glColor3f(0.2, 0.6, 1.0);

    // ===== Baris bawah (4 kubus)
    kotak(-0.4, -0.3);
    kotak(-0.15, -0.3);
    kotak(0.1, -0.3);
    kotak(0.35, -0.3);

    // ===== Baris tengah (2 kubus)
    kotak(-0.275, 0.0);
    kotak(0.075, 0.0);

    // ===== Baris atas (1 kubus)
    kotak(-0.1, 0.3);

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Kubus Bertingkat Kreatif");

    glutDisplayFunc(display);
    glClearColor(1,1,1,1);

    glutMainLoop();
    return 0;
}
