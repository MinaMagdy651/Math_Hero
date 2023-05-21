#ifndef SCREENS_H
#define SCREENS_H

#include "../helpers/helpers.cpp"
#include "../components/button.cpp"
#include "../handlers/highScoreHandler.cpp"

class screens {
public:
    static void firstScreen(bool& changeBgColor, int buttonCx, int playButtonCy, int highScoresButtonCy, int quitButtonCy, int buttonWidth, int buttonHeight) {
        // Game screen can change color
        changeBgColor = true;
        colorRGB backGroundCOlor = colorRGB(0, 0, 0);
        glClearColor(backGroundCOlor.getR(), backGroundCOlor.getG(), backGroundCOlor.getB(), 1.0);
        glutPostRedisplay();

        colorRGB headerRGB = colorRGB(253, 168, 185);
        glColor3f(headerRGB.getR(), headerRGB.getG(), headerRGB.getB());
        textPrint::printText("Ma+h Her0", 40, 85, 24);

        colorRGB buttonColor = colorRGB(255, 255, 255);
        colorRGB textColor = colorRGB(16, 172, 234);

        button playButton = button(buttonCx, playButtonCy, buttonWidth, buttonHeight, buttonColor, "PLAY", textColor);
        button highScoresButton = button(buttonCx, highScoresButtonCy, buttonWidth, buttonHeight, buttonColor, "HIGHSCORES", textColor);
        button quitButton = button(buttonCx, quitButtonCy, buttonWidth, buttonHeight, buttonColor, "QUIT", textColor);

        playButton.draw();
        highScoresButton.draw();
        quitButton.draw();
    }
    static void highScoreScreen(bool& changeBgColor, highScoreHandler highScoreHandlerInstance) {
        changeBgColor = true;
        highScoreHandlerInstance.drawHighScores();
    }

    static void endScreen(bool& changeBgColor, bool& timerActive, int score, highScoreHandler highScoreHandlerInstance) {
        // Game screen can change color
        changeBgColor = true;
        // Closing the timer, not redisplay
        timerActive = false;

        colorRGB backGroundCOlor = colorRGB(200, 191, 231);
        glColor3f(backGroundCOlor.getR(), backGroundCOlor.getG(), backGroundCOlor.getB());

        // Change background color
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(0, 100);
        glVertex2f(100, 100);
        glVertex2f(100, 0);
        glEnd();
        colorRGB textColor = colorRGB(231, 237, 251);
        glColor3f(textColor.getR(), textColor.getG(), textColor.getB());
        textPrint::printText("Your Score is: " + to_string(score), 40, 60, 24);
        int position = highScoreHandlerInstance.addScore(score);
        textPrint::printText("Your rank is: " + to_string(position), 40, 40, 24);
    }

    static void game(bool& changeBgColor, int numberOfCards, float translateY[], queue<int>& answers, string& answerString, int& answer, int& score, bool translated[], bool drawCards[], bool& timerActive, int& status, int& counterTimer, cards equations[]) {
        textPrint::printText("Score: " + to_string(score), 5, 95, 24);
        textPrint::printText(to_string(counterTimer), 95, 95, 24);

        colorRGB backGroundCOlor = colorRGB(195, 195, 195);
        glClearColor(backGroundCOlor.getR(), backGroundCOlor.getG(), backGroundCOlor.getB(), 1.0);
        // Change background color
        if (changeBgColor) {
            glutPostRedisplay();
            changeBgColor = false;
        }
        for (int i = 0; i < numberOfCards; i++) {
            cout << answer << " " << answers.front() << endl;
            // cout << i << " " << translateY[i] << endl;
            translateY[i] += 1;
            // No answers left
            if (answers.empty())
                break;
            // Answer is correct and card isn't translated
            if (answer != -1 && answer == answers.front()) {
                score++;
                answers.pop();
                translated[i] = true;
                answer = -1;
                answerString = "";
                // Getting the right index of the answered card
                drawCards[numberOfCards - answers.size() - 1] = false;
            }
            // Card is translated above the frame
            if (translateY[i] >= 100 && !translated[i] && (answer != answers.front() || answer == -1)) {
                answers.pop();
                answer = -1;
                answerString = "";
                translated[i] = true;
            }
            // Drawing cards that are not answered yet nor translated
            if (drawCards[i])
                equations[i].draw(50, translateY[i]);
        }

        // No cards left, game is over
        if (translated[numberOfCards - 1] || counterTimer >= 60 || answers.empty()) {
            fill(translated, translated + numberOfCards, 0);
            status = 3;
        }
    }


};
#endif
