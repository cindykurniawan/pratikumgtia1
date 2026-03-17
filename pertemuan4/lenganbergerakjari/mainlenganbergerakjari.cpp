#include <GL/glut.h>

float bahu = 0;
float siku = 0;
float telapak = 0;
float jari[5] = {0,0,0,0,0}; // 5 jari

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -6.0);

    // ===== LENGAN ATAS =====
    glRotatef(bahu, 0.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(1.5, 0.3, 0.3);
        glutWireCube(1.0);
    glPopMatrix();

    // ===== LENGAN BAWAH =====
    glTranslatef(1.5, 0.0, 0.0);
    glRotatef(siku, 0.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(1.2, 0.3, 0.3);
        glutWireCube(1.0);
    glPopMatrix();

    // ===== TELAPAK TANGAN =====
    glTranslatef(1.2, 0.0, 0.0);
    glRotatef(telapak, 0.0, 0.0, 1.0);
    glPushMatrix();
        glScalef(0.5, 0.3, 0.5);
        glutWireCube(1.0);
    glPopMatrix();

    // ===== JARI (5 JARI) =====
    glTranslatef(0.5, 0.0, 0.0);

    for(int i = 0; i < 5; i++)
    {
        glPushMatrix();
            glTranslatef(0.0, 0.25*i - 0.5, 0.0); // posisi jari
            glRotatef(jari[i], 0.0, 0.0, 1.0);   // gerakan jari
            glScalef(0.3, 0.1, 0.1);
            glutWireCube(1.0);
        glPopMatrix();
    }

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        // bahu
        case 'q': bahu += 5; break;
        case 'a': bahu -= 5; break;

        // siku
        case 'w': siku += 5; break;
        case 's': siku -= 5; break;

        // telapak
        case 'e': telapak += 5; break;
        case 'd': telapak -= 5; break;

        // jari 1 - 5
        case '1': jari[0] += 5; break;
        case '2': jari[1] += 5; break;
        case '3': jari[2] += 5; break;
        case '4': jari[3] += 5; break;
        case '5': jari[4] += 5; break;

        // balik (luruskan)
        case '!': jari[0] -= 5; break;
        case '@': jari[1] -= 5; break;
        case '#': jari[2] -= 5; break;
        case '$': jari[3] -= 5; break;
        case '%': jari[4] -= 5; break;
    }

    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(float)w/(float)h,1.0,10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Lengan + Tangan + 5 Jari");

    glClearColor(0.0,0.0,0.0,0.0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

