#include <GL/glut.h>
#include <math.h>
#include <bits/stdc++.h>
#include "utility.h"
#include "button.h"
using namespace std;

int phyWidth = 700;
int phyHeight = 700;
int logWidth = 100;
int logHeight = 100;
int centerX = logWidth/2;
int centerY = logHeight/2;
void init2D(float r, float g, float b) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, logWidth, 0.0, logHeight);
}
void firstScreen() {
     utlity utlityInstance;
    
    colorRGB headerRGB = colorRGB(253, 168, 185);
    glColor3f(headerRGB.getR(), headerRGB.getG(), headerRGB.getB());
    utlityInstance.printText("Ma+h Her0", 40, 85, 24);
    
    
    colorRGB buttonColor = colorRGB(255, 255, 255);
    colorRGB textColor = colorRGB(16, 172, 234);
    
    button playButton = button(50, 65, 20, 6, buttonColor, "PLAY", textColor);
    button highScoresButton = button(50, 50, 20, 6, buttonColor, "HIGHSCORES", textColor);
    button quitButton = button(50, 35, 20, 6, buttonColor, "QUIT", textColor);

    playButton.draw();
    highScoresButton.draw();
    quitButton.draw();
}
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    firstScreen();
    glutSwapBuffers();
    glFlush();
}

int main(int argc,char *argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowSize(phyWidth, phyHeight);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("points and lines");
    init2D(0.0,0.0,0.0);
    glutDisplayFunc(display);
    glutMainLoop();
}


