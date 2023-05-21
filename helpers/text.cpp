#ifndef TEXT_H
#define TEXT_H
#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

class textPrint {
public:
    textPrint() {}
    // Print text in the screen
    static void printText(string str, int x, int y, int font) {
        glRasterPos2d(x, y);
        for (auto i : str) {
            if (font == 24)
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
            else if (font == 10)
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, i);
            else if (font == 18)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, i);
        }
    }
};
#endif


