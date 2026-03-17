#include <GL/glut.h>
#include <math.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    float x, y;
    float radius = 0.5;

    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float sudut = i * 3.14159 / 180;
        x = radius * cos(sudut);
        y = radius * sin(sudut);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lingkaran");

    glClearColor(0.0,0.0,0.0,0.0);

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
