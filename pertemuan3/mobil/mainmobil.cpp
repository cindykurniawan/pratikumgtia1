#include <GL/glut.h>
#include <math.h>

float posisi = -1.0;
float rotasi_roda = 0;

void drawCircle(float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float sudut = i * 3.14159 / 180;
        glVertex2f(radius*cos(sudut), radius*sin(sudut));
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // ===== JALAN =====
    glColor3f(0.3,0.3,0.3);
    glBegin(GL_QUADS);
        glVertex2f(-1.0,-0.5);
        glVertex2f(1.0,-0.5);
        glVertex2f(1.0,-1.0);
        glVertex2f(-1.0,-1.0);
    glEnd();

    // ===== MOBIL =====
    glPushMatrix();
        glTranslatef(posisi, 0.0, 0.0);

        // badan mobil
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_QUADS);
            glVertex2f(-0.4, -0.2);
            glVertex2f(0.4, -0.2);
            glVertex2f(0.4, 0.2);
            glVertex2f(-0.4, 0.2);
        glEnd();

        // atap mobil
        glColor3f(0.8,0.0,0.0);
        glBegin(GL_QUADS);
            glVertex2f(-0.2, 0.2);
            glVertex2f(0.2, 0.2);
            glVertex2f(0.1, 0.4);
            glVertex2f(-0.1, 0.4);
        glEnd();

        // ===== RODA KIRI =====
        glPushMatrix();
            glTranslatef(-0.25, -0.3, 0.0);
            glRotatef(rotasi_roda, 0.0,0.0,1.0);
            glColor3f(0.0,0.0,0.0);
            drawCircle(0.1);
        glPopMatrix();

        // ===== RODA KANAN =====
        glPushMatrix();
            glTranslatef(0.25, -0.3, 0.0);
            glRotatef(rotasi_roda, 0.0,0.0,1.0);
            glColor3f(0.0,0.0,0.0);
            drawCircle(0.1);
        glPopMatrix();

    glPopMatrix();

    glFlush();
}

void idle()
{
    posisi += 0.001;
    rotasi_roda -= 2;

    if(posisi > 1.2)
        posisi = -1.2;

    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Mobil 2D");

    glClearColor(0.5,0.8,1.0,0.0); // langit

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}
