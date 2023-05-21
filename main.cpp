#include <GL/glut.h>
#include <bits/stdc++.h>
#include "components/button.cpp"
#include "handlers/highScoreHandler.cpp"
#include "components/cards.cpp"
#include "screens/screens.cpp"
#include "helpers/helpers.cpp"
// #include "globalVariables.cpp"
using namespace std;


int phyWidth = 700;
int phyHeight = 700;
int logWidth = 100;
int logHeight = 100;
int centerX = logWidth / 2;
int centerY = logHeight / 2;

int mouseX = 0;
int mouseY = 0;

// Screen Status and changing background color for game screen
int status = 0;
bool changeBgColor = true;

// Buttons Y-level
int playButtonCy = 65;
int highScoresButtonCy = 50;
int quitButtonCy = 35;

// Buttons height and width
int buttonWidth = 20;
int buttonHeight = 6;
int buttonCx = 50;

// Cards number, translation and drawing
// if tanslateY[i] >= 110 then the card is out of the screen
// if translated[i] == true then the card is translated
// if drawCards[i] == false then the card won't be drawn
const int numberOfCards = 4;
float translateY[numberOfCards];
bool translated[numberOfCards];
bool drawCards[numberOfCards];

// Cards and answers
cards equations[numberOfCards];
queue<int> answers;
string answerString = "";
int answer = -1;
int score = 0;

highScoreHandler highScoreHandlerInstance;

// Timer
bool timerActive = false;
int counterTimer = 0;
int secondCounter = 0;

void init2D(float r, float g, float b) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, logWidth, 0.0, logHeight);
}
// fill cards with random numbers, and fill answers queue, and fill translateY array, and fill drawCards array, and fill translated array
void fillCards() {
    cards::fillCards(drawCards, answers, equations, translateY, numberOfCards);
}

void mouseClick(int btn, int state, int x, int y) {
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseX = x;
        mouseX = 0.5 + 1.0 * mouseX * logWidth / phyWidth;
        mouseY = phyHeight - y;
        mouseY = 0.5 + 1.0 * mouseY * logHeight / phyHeight;
        if (status == 0 && mouseX >= (buttonCx - buttonWidth / 2) && mouseX <= (buttonCx + buttonWidth / 2) && mouseY >= (playButtonCy - buttonHeight / 2) && mouseY <= (playButtonCy + buttonHeight / 2)) {
            status = 1;
            fillCards();
            counterTimer = 0;
            secondCounter = 0;
            // Filling the arrays with false and true
            fill(translated, translated + numberOfCards, 0);
            fill(drawCards, drawCards + numberOfCards, 1);
        }
        if (status == 0 && mouseX >= (buttonCx - buttonWidth / 2) && mouseX <= (buttonCx + buttonWidth / 2) && mouseY >= (highScoresButtonCy - buttonHeight / 2) && mouseY <= (highScoresButtonCy + buttonHeight / 2)) {
            status = 2;
        }
        if (status == 0 && mouseX >= (buttonCx - buttonWidth / 2) && mouseX <= (buttonCx + buttonWidth / 2) && mouseY >= (quitButtonCy - buttonHeight / 2) && mouseY <= (quitButtonCy + buttonHeight / 2)) {
            exit(0);
        }
        glutPostRedisplay();
    }

}
void specialKeyboard(int key, int x, int y) {
    if (key == GLUT_KEY_F1) {
        score = 0;
        status = 1;
        fillCards();
        counterTimer = 0;
        secondCounter = 0;
        // Filling the arrays with false and true
        fill(translated, translated + numberOfCards, 0);
        fill(drawCards, drawCards + numberOfCards, 1);

    }
    if (key == GLUT_KEY_F2)
        status = 0;
    glutPostRedisplay();

}

void keyboard(unsigned char key, int x, int y) {
    // If key pressed is a number, it will be added to the answer string, 
    // If it is enter, the answerString will be converted to an integer
    answerString += key;
    if (key == 13) {
        try {
            answer = stoi(answerString);
        }
        catch (const std::exception& e) {
            answer = -1;
        }
        answerString = "";
    }
}
void animAteCards(int value) {
    if (timerActive) {
        glutPostRedisplay();
        // 1000 /50 = 20, there is 20 frames in a second
        secondCounter++;
        if (secondCounter == 20) {
            secondCounter = 0;
            counterTimer++;
        }
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    if (status == 0) {
        timerActive = false;
        screens::firstScreen(changeBgColor, buttonCx, playButtonCy, highScoresButtonCy, quitButtonCy, buttonWidth, buttonHeight);
    }
    else if (status == 1) {
        timerActive = true;
        glutTimerFunc(50, animAteCards, 0);
        screens::game(changeBgColor, numberOfCards, translateY, answers, answerString, answer, score, translated, drawCards, timerActive, status, counterTimer, equations);
    }
    else if (status == 2) {
        timerActive = false;
        screens::highScoreScreen(changeBgColor, highScoreHandlerInstance);
    }
    else if (status == 3) {
        timerActive = false;
        screens::endScreen(changeBgColor, timerActive, score, highScoreHandlerInstance);
    }
    glFlush();
    glutSwapBuffers();
}


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(phyWidth, phyHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Math Hero");
    init2D(0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutMouseFunc(mouseClick);
    glutSpecialFunc(specialKeyboard);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}


