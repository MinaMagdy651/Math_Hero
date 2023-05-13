#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
#ifndef COLORRGB_H
#define COLORRGB_H
class utlity {
    public:
        void printText(string str, int x, int y, int font) {
            glRasterPos2d(x, y);
            for (auto i : str) {
                if(font == 24)
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
                else if (font == 10)
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, i);
                else if (font == 18)
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, i);

            }
        }
};

class colorRGB {
    private:
        double r;
        double g;
        double b;
        
    public:
        colorRGB(int r, int g, int b) {
            this->r = r/255.0f;
            this->g = g/255.0f;
            this->b = b / 255.0f;
        }
        double getR() {
            return this->r;
        }
        double getG() {
            return this->g;
        }
        double getB() {
            return this->b;
        }
};
#endif