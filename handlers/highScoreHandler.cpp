#ifndef HIGHSCOREHANDLER_H
#define HIGHSCOREHANDLER_H
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include "../helpers/helpers.cpp"
using namespace std;

class highScoreHandler {
private:
    vector<int> highScoreList;
    void readHighScores() {
        ifstream file("handlers/highscore.txt");
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                highScoreList.push_back(stoi(line));
            }
            file.close();
        }
        else {
            ofstream file("handlers/highscore.txt");
            file.close();
        }
    }
    void printHighScores() {
        for (auto i : highScoreList)
            cout << i << endl;
    }

public:
    highScoreHandler() {
        readHighScores();
    }

    void writeHighScores() {
        ofstream file("handlers/highscore.txt");
        for (auto i : highScoreList) {
            file << i << endl;
        }
        file.close();
    }
    int addScore(int socre) {
        highScoreList.push_back(socre);
        sort(highScoreList.begin(), highScoreList.end(), greater<int>());
        if (highScoreList.size() > 7)
            highScoreList.pop_back();
        int position = find(highScoreList.begin(), highScoreList.end(), socre) - highScoreList.begin();
        this->writeHighScores();
        return position + 1;
    }

    void drawHighScores() {
        textPrint textPrintInstance;

        int textHeight = 18;
        int textPosX = 0;
        int textPosY = 0;
        colorRGB HighScoreColor = colorRGB(255, 255, 255);
        glColor3f(HighScoreColor.getR(), HighScoreColor.getG(), HighScoreColor.getB());
        textPrintInstance.printText("High Scores", 40, 90, 18);
        for (int i = 0; i < (int)highScoreList.size(); i++) {
            textPosX = 10;
            textPosY = 70 - i * 10;
            string scoreStr = to_string(i + 1) + ". " + to_string(highScoreList[i]);
            textPrintInstance.printText(scoreStr, textPosX, textPosY, textHeight);
        }
    }

};
#endif
