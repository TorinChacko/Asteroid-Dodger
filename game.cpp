#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;
bool gameOver;
const int width = 40;
const int height = 7;
int playerX = 20, playerY = 6, obstacleX[10], obstacleY[10];
int logX[10], logY;

void Setup() {
    gameOver = false;
    obstacleX[1] = rand() % width;
    obstacleY[1] = 0;
    logY = 3;
    for (int i = 0; i < 10; i++) {
        logX[i] = rand() % width;
    }
}

void Map() {
    system("cls");
    cout << "\t\t  FINISH\n";
    for (int i = 0; i <= width; i++) {
        cout << "_";
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= width; j++) {
            if (i == playerY && j == playerX) {
                if (playerY == 1) gameOver = true;
                cout << "$";
            }
            else if (i == obstacleY[1] && j == obstacleX[1]) {
                cout << "O";
            }
            else if (i == logY && (j == logX[0] || j == logX[1] || j == logX[2] || j == logX[3] || j == logX[4] || j == logX[5] || j == logX[6] || j == logX[7] || j == logX[8] || j == logX[9])) {
                cout << "_";
            }
            else if (i == obstacleY[2] && j == obstacleX[2]) {
                cout << "O";
            }
            else if (i == obstacleY[3] && j == obstacleX[3]) {
                cout << "O";
            }
            else if (i == obstacleY[4] && j == obstacleX[4]) {
                cout << "O";
            }
            else if (i == obstacleY[5] && j == obstacleX[5]) {
                cout << "O";
            }
            else if (i == obstacleY[6] && j == obstacleX[6]) {
                cout << "O";
            }
            else if (i == obstacleY[7] && j == obstacleX[7]) {
                cout << "O";
            }
            else if (i == obstacleY[8] && j == obstacleX[8]) {
                cout << "O";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i <= width; i++) {
        cout << "_";
    }
    cout << "\n\t\t  START\n";
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            playerX--;
            break;
        case 'd':
            playerX++;
            break;
        case 'w':
            playerY--;
            break;
        case 's':
            playerY++;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic() {
    if (playerX > width || playerX < 0 || playerY > height || playerY < 0)
        gameOver = true;
    
    obstacleY[1]++;
    if (obstacleY[1] >= height) {
        obstacleY[1] = 0;
        obstacleX[1] = rand() % width;
    }
    if (playerX == obstacleX[1] && playerY == obstacleY[1]) {
        gameOver = true;
    }

    for (int i = 0; i < 10; i++) {
        logX[i]++;
        if (logX[i] >= width) {
            logX[i] = 0;
        }
    }

    if (playerY == logY) {
        bool onLog = false;
        for (int i = 0; i < 10; i++) {
            if (playerX == logX[i]) {
                onLog = true;
                break;
            }
        }
        if (!onLog) {
            gameOver = true;
        }
    }

    obstacleX[2]++;
    obstacleX[3]++;
    obstacleX[4]++;
    obstacleX[5]++;
    obstacleX[6]++;
    obstacleX[7]++;
    obstacleX[8]++;

    if (playerX == obstacleX[2] && playerY == obstacleY[2]) {
        gameOver = true;
    }
    if (playerX == obstacleX[3] && playerY == obstacleY[3]) {
        gameOver = true;
    }
    if (playerX == obstacleX[4] && playerY == obstacleY[4]) {
        gameOver = true;
    }
    if (playerX == obstacleX[5] && playerY == obstacleY[5]) {
        gameOver = true;
    }
    if (playerX == obstacleX[6] && playerY == obstacleY[6]) {
        gameOver = true;
    }
    if (playerX == obstacleX[7] && playerY == obstacleY[7]) {
        gameOver = true;
    }
    if (playerX == obstacleX[8] && playerY == obstacleY[8]) {
        gameOver = true;
    }
    if (obstacleX[2] == 39) {
        obstacleX[2] = 1;
        obstacleY[2] = 5;
    }
    if (obstacleX[3] == 39) {
        obstacleX[3] = 1;
        obstacleY[3] = 5;
    }
    if (obstacleX[4] == 39) {
        obstacleX[4] = 1;
        obstacleY[4] = 4;
    }
    if (obstacleX[5] == 39) {
        obstacleX[5] = 1;
        obstacleY[5] = 4;
    }
    if (obstacleX[6] == 39) {
        obstacleX[6] = 1;
        obstacleY[6] = 3;
    }
    if (obstacleX[7] == 39) {
        obstacleX[7] = 1;
        obstacleY[7] = 2;
    }
    if (obstacleX[8] == 39) {
        obstacleX[8] = 1;
        obstacleY[8] = 2;
    }
}

int main() {
    obstacleX[1] = 1;
    obstacleY[1] = 5;
    obstacleX[2] = 3;
    obstacleY[2] = 5;

    obstacleX[3] = 11;
    obstacleY[3] = 4;
    obstacleX[4] = 18;
    obstacleY[4] = 4;

    obstacleX[5] = 25;
    obstacleY[5] = 3;
    obstacleX[6] = 32;
    obstacleY[6] = 3;

    obstacleX[7] = 1;
    obstacleY[7] = 2;
    obstacleX[8] = 25;
    obstacleY[8] = 2;
    Setup();
    while (!gameOver) {
        Map();
        Input();
        Logic();
    }

    cout << endl;
    system("pause");
    return 0;
}
