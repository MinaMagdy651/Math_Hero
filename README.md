# Math Hero

Math Hero is a fun and addictive game that challenges your arithmetic skills. Test your mental agility and become a true Math Hero! Solve randomly generated simple arithmetic equations against the clock and see how high you can score.

## Table of Contents

- [Introduction](#introduction)
- [Game Features](#game-features)
- [Installation](#installation)
- [How to Play](#how-to-play)
- [Contributing](#contributing)

## Introduction

Math Hero is a game designed to help you improve your math skills while having fun. It offers a simple yet engaging gameplay experience that keeps you on your toes. The game presents you with randomly generated arithmetic equations and challenges you to solve them before time runs out or the card runs out of the frame.

## Game Features

- **Opening Screen:** The game begins with an opening screen that provides three options: Play, Highscores, or Quit.
- **Randomly Generated Equations:** Math Hero generates simple arithmetic equations, such as addition, subtraction, multiplication, and division problems.
- **Timer:** You have a limited amount of time to solve each equation. Challenge yourself to solve as many equations as possible before the timer runs out.
- **Scoring System:** Earn points for every correct answer. Your score increases as you solve more equations accurately.
- **Highscores:** Check out the highscores to see how you rank among other Math Heroes.
- **Engaging Gameplay:** Enjoy a fast-paced and addictive gameplay experience that tests your mental agility and mathematical skills.

## Installation

To play Math Hero, follow these steps:

1. Please make sure you have isntalled OpengGL, GLUT, mingw32

   <a href="https://github.com/marketplace/actions/setup-opengl" target="_blank">How to install OpenGL</a>

2. Clone this repository to your local machine:

```bash
git clone https://github.com/amwopps/Math_Hero
```

3. Navigate to the project directory and run

```bash
cd MathHero
mingw32-g++.exe -Wall -g -IC:MinGWinclude main.cpp -o Program.exe -L C:MinGWlib -lglut32 -lopengl32 -lglu32 -lwinmm -lgdi32
```

**OR:** You can simply install Run++ on Vscode, and change the json files configuarations acording to your machine.

## How to Play

1. On the opening screen, you will be presented with three options:
   <img src="https://github.com/amwopps/Math_Hero/blob/main/ScreenShots/menu.png" alt="Main Menu" width="700" height="700">

- **Play:** Start the game and test your math skills.
- **Highscores:** View the leaderboard and see the top Math Heroes.
- **Quit:** Exit the game.

2. If you choose to play, you will be shown a randomly generated arithmetic equations on cards.
   <img src="https://github.com/amwopps/Math_Hero/blob/main/screenShots/inGame.png" alt="In Game" width="700" height="700">

3. Solve the equation as quickly as possible by entering the correct answer.

4. If you solve the equation correctly, you earn points.

5. Keep solving equations and accumulating points until the timer runs out or the card runs out of the frame.

6. Your final score will be displayed at the end of the game.
   <img src="https://github.com/amwopps/Math_Hero/blob/main/screenShots/endGame.png" alt="End Game" width="700" height="700">

7. If you achieve a high score, you enter the leaderboard.
   <img src="https://github.com/amwopps/Math_Hero/blob/main/screenShots/highScores.png" alt="High Scores" width="700" height="700">

## Contributing

Contributions to Math Hero are welcome! If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.
