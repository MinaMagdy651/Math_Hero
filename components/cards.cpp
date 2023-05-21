#ifndef CARDS_H
#define CARDS_H

#include <bits/stdc++.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include "../helpers/helpers.cpp"
using namespace std;

class cards {
private:
    int width;
    int height;
    pair<string, int> equation;
    colorRGB cardColor;
    colorRGB textColor;
    // Generate a random equation
    pair<string, int> generateEquation() {
        vector<char> ops = { '+', '-', '*', '/' };

        int temp1 = rand() % 12 + 1;
        int temp2 = rand() % 12 + 1;
        int num1 = max(temp1, temp2);
        int num2 = min(temp1, temp2);
        char op = rand() % 4;

        string equationString = to_string(num1) + " " + ops[op] + " " + to_string(num2);
        int answer;

        switch (ops[op]) {
        case '+':
            answer = num1 + num2;
            break;
        case '-':
            answer = num1 - num2;
            break;
        case '*':
            answer = num1 * num2;
            break;
        case '/':
            // If the division is not an integer, then add the numbers
            if (num1 % num2 != 0) {
                answer = num1 + num2;
                equationString = to_string(num1) + " + " + to_string(num2);
            }
            else
                answer = num1 / num2;
            break;
        default:
            break;
        }
        return { equationString, answer };
    }

public:
    cards(int width, int height, colorRGB cardColor, colorRGB textColor) : cardColor(cardColor), textColor(textColor) {
        this->width = width;
        this->height = height;
        this->equation = generateEquation();
    }
    cards() {

    }
    void printInCard(int cX, int cY) {
        int textWidth = equation.first.length();
        int textHeight = 18;
        int textPosX = cX - textWidth / 2;
        int textPosY = cY - 1;
        if (textWidth > width / 2) {
            textPosX = cX - width / 2 + 1;
        }
        glColor3f(textColor.getR(), textColor.getG(), textColor.getB());
        textPrint::printText(equation.first, textPosX, textPosY, textHeight);
    }
    void draw(int cX, int cY) {
        glColor3f(cardColor.getR(), cardColor.getG(), cardColor.getB());
        glBegin(GL_POLYGON);
        glVertex2f(cX - width / 2, cY - height / 2);
        glVertex2f(cX + width / 2, cY - height / 2);
        glVertex2f(cX + width / 2, cY + height / 2);
        glVertex2f(cX - width / 2, cY + height / 2);
        glEnd();
        printInCard(cX, cY);
    }
    string getEquation() {
        return this->equation.first;
    }
    int getAnswer() {
        return this->equation.second;
    }
    // fill cards with random numbers, and fill answers queue, and fill translateY array, and fill drawCards array, and fill translated array
    static void fillCards(bool drawCards[], queue<int>& answers, cards equations[], float translateY[], int numberOfCards) {
        fill(drawCards, drawCards + numberOfCards, 1);
        while (!answers.empty())
            answers.pop();
        for (int i = 0; i < numberOfCards; i++) {
            equations[i] = cards(20, 10, colorRGB(153, 217, 234), colorRGB(255, 255, 255));
            answers.push(equations[i].getAnswer());
        }
        for (int i = numberOfCards - 1; i >= 0; i--) {
            translateY[i] = -(numberOfCards * 20) + (numberOfCards - i) * 20;
        }
    }

};
#endif