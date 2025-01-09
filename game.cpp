
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

// Define the map size
bool gameOver;
int playerX = 20, playerY = 6, obstacleX[10], obstacleY[10];
int logX[10], logY;
int obstacleSpeed = 2; // Adjust this value to change obstacle speed
const int width = 30;
const int height = 20;
int playerHealth;

void Setup() {
    gameOver = false;
    playerHealth = 3; // Set initial player health
    srand(static_cast<unsigned int>(time(0))); // Fix type conversion warning
    playerX = width / 2;
    playerY = height - 1;

    // Place obstacles in groups
    for (int i = 0; i < 10; i += 8) {
        int baseX = rand() % (width - 2); // Ensure there's space for the group
        int baseY = rand() % (height - 2); // Ensure there's space for the group

        obstacleX[i] = baseX;
        obstacleY[i] = baseY;
        obstacleX[i + 1] = baseX + 1;
        obstacleY[i + 1] = baseY;

        obstacleX[i + 2] = baseX - 1;
        obstacleY[i + 2] = baseY + 1;
        obstacleX[i + 3] = baseX;
        obstacleY[i + 3] = baseY + 1;
        obstacleX[i + 4] = baseX + 1;
        obstacleY[i + 4] = baseY + 1;
        obstacleX[i + 5] = baseX + 2;
        obstacleY[i + 5] = baseY + 1;

        obstacleX[i + 6] = baseX;
        obstacleY[i + 6] = baseY + 2;
        obstacleX[i + 7] = baseX + 1;
        obstacleY[i + 7] = baseY + 2;
    }
}

void Map() {
    system("cls");
    cout << "\t\t  FINISH\n";
    for (int i = 0; i <= width; i++) {
        cout << "_";
    }
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= width; j++) {
            if (i == playerY && j == playerX) {
                if (playerY == 1) gameOver = true;
                cout << "$";
            } else {
                bool obstaclePresent = false;
                for (int k = 0; k < 10; k++) {
                    if (i == obstacleY[k] && j == obstacleX[k]) {
                        cout << "O";
                        obstaclePresent = true;
                        break;
                    }
                }
                if (!obstaclePresent) {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    for (int i = 0; i <= width; i++) {
        cout << "_";
    }
    cout << "\n\t\t  START\n";
    cout << "Health: " << playerHealth << endl; // Display player's health
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
    if (playerX > width || playerX < 0 || playerY > height || playerY < 0) {
        cout << "You Win!" << endl;
        gameOver = true;
    }

    static int obstacleCounter = 0;
    obstacleCounter++;
    if (obstacleCounter >= obstacleSpeed) {
        for (int i = 0; i < 10; i++) {
            obstacleY[i]++;
            if (obstacleY[i] >= height) {
                obstacleY[i] = 0;
                obstacleX[i] = rand() % width;
            }
            if (playerX == obstacleX[i] && playerY == obstacleY[i]) {
                playerHealth--; // Decrease health on collision
                if (playerHealth <= 0) {
                    gameOver = true;
                }
            }
        }
        obstacleCounter = 0;
    }
}

int main() {
    Setup();
    while (!gameOver) {
        Map();
        Input();
        Logic();
        Sleep(100); // Add a delay for smoother movement
    }

    cout << endl;
    system("pause");
    return 0;
}
