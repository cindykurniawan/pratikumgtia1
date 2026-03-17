
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

// Fungsi untuk menggambar titik
void point(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Atur ukuran titik
    glPointSize(5.0f);

    // Mulai menggambar titik
    glBegin(GL_POINTS);

        // Warna merah (R, G, B)
        glColor3f(1.0f, 0.0f, 0.0f);

        // Posisi titik (x, y, z)
        glVertex3f(0.25f, 0.25f, 0.0f);

    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Titik");

    // Warna background biru
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    glutDisplayFunc(point);
    glutMainLoop();

    return 0;
}

