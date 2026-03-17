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

void SegiEmpat(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor4f(1.0f, 1.0f, 0.0f, 0.5f);   // Warna merah
    glRectf(-0.18f, 0.18f, 0.18f, -0.18f);

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Segi Empat");

    glutDisplayFunc(SegiEmpat);

    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Background biru

    glutMainLoop();
    return 0;
}

