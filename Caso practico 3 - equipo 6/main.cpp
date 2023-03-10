#include <GL/glut.h>
#include <math.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const float PI = 3.14159265f;

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT); 
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

  
    int maxX = WINDOW_WIDTH;
    int maxY = WINDOW_HEIGHT;

    
    int radio = 50;

   
    glColor3f(1.0f, 1.0f, 1.0f); 
    glBegin(GL_LINE_LOOP);
    for (float angle = 0; angle < 2 * PI; angle += 0.01) {
        float x = radio * cos(angle) + maxX/2;
        float y = radio * sin(angle) + maxY/2;
        glVertex2f(x, y);
    }
    glEnd();

    
    int lineaSize = radio * 2;

   
    glColor3f(0.0f, 1.0f, 0.0f); 
    glBegin(GL_LINES);
    glVertex2f(maxX/2 - lineaSize/2, maxY/2 + lineaSize/2);
    glVertex2f(maxX/2 + lineaSize/2, maxY/2 - lineaSize/2);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Linea recta diagonal con OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


