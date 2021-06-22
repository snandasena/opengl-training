//
// Created by sajith on 6/22/21.
//


#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    for (GLfloat i = -2.5; i <= 2.5; i += 0.25)
    {
        glVertex3f(i * 1.0, 0, 2.5);
        glVertex3f(i * 1.0, 0, -0.25);

        glVertex3f(2.5, 0, i * 1.0);
        glVertex3f(-2.5, 0, i * 1.0);
    }
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 1);
    glVertex3f(0, 2, 0);
    glColor3f(1, 0, 0);
    glVertex3f(-1, 0, 1);
    glColor3f(0, 1, 0);
    glVertex3f(1, 0, 1);
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, -1.4);
    glColor3f(1, 1, 1);
    glVertex3f(0, 2, 0);
    glColor3f(1, 0, 0);
    glVertex3f(-1, 0, 1);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.1, 0.39, 0.88, 1.0);
    glColor3f(1.0, 1.0, 1.0);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-2, 2, -1.5, 1.5, 1, 40);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -3);
    glRotatef(50, 1, 0, 0);
    glRotatef(70, 0, 1, 0);

}

int main(int arc, char **argv)
{

    glutInit(&arc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Tutorials");
    glutDisplayFunc(display);

    init();
    glutMainLoop();
    return 0;
}