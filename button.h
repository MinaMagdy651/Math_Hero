#include <bits/stdc++.h>
#include <GL/glut.h>
#include "utility.h"
using namespace std;
class button {
private:
    int width;
    int height;
    int cX;
    int cY;
    string text;
    colorRGB buttonColor;
    colorRGB textColor;


    public:
        button(int cX, int cY, int width, int height,  colorRGB buttonColor, string text, colorRGB textColor) : buttonColor(buttonColor), textColor(textColor) {
            this->cX = cX;
            this->cY = cY;
            this->width = width;
            this->height = height;
            this->text = text;
        }
        
        void printInButton() {
            utlity u;
            int textWidth = text.length();
            int font = 24;
            glColor3f(textColor.getR(), textColor.getG(), textColor.getB());
            u.printText(text, cX - (textWidth/2), cY, font);
        }
        
        void draw() {
            glColor3f(buttonColor.getR(), buttonColor.getG(), buttonColor.getB());
            glBegin(GL_POLYGON);
                glVertex2f(cX - width / 2, cY - height / 2);
                glVertex2f(cX + width / 2, cY - height / 2);
                glVertex2f(cX + width / 2, cY + height / 2);
                glVertex2f(cX - width / 2, cY + height / 2);
            glEnd();
            printInButton();
        }

};