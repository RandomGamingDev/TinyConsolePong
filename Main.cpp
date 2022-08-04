#include<iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

const char paddleChar = '|', ballChar = 'O';
const int paddleLength = 5;
char display[20][100] = {};
int paddles[2] = { 8, 8 };
int ballLoc[4] = { 10, 50 , 1, 5 };

int main() {
    for (int i = 0; i < sizeof(display) / sizeof(display[0]); i++) for (int j = 0; j < sizeof(display[0]) / sizeof(display[0][0]); j++) display[i][j] = ' ';
    std::cout << "Pong!\n Press Enter to Continue:\n";
    std::cin.get();
    while (true) {
        Sleep(100); std::system("cls");
        for (int i = 0; i < sizeof(display) / sizeof(display[0]); i++) {
            for (int j = 0; j < sizeof(display[0]) / sizeof(display[0][0]); j++) {
                std::cout << display[i][j];
                display[i][j] = ' ';
            }
            std::cout << '\n';
        }
        for (int i = 0; i < 2; i++) for (int j = 0; j < paddleLength; j++) {
            int paddleLoc = paddles[i] + j;
            if (paddleLoc >= 0 && paddleLoc <= sizeof(display) / sizeof(display[0])) {
                if (i) display[paddleLoc][(sizeof(display[0]) / sizeof(display[0][0])) - 1] = paddleChar;
                else display[paddleLoc][0] = paddleChar;
            }
        }

        display[ballLoc[0]][ballLoc[1]] = ballChar;
        for (int i = 0; i < 2; i++) {
            int prediction = ballLoc[i] + ballLoc[i + 2], length;
            if (i) length = sizeof(display[0]) / sizeof(display[0][0]) - 2;
            else length = sizeof(display) / sizeof(display[0]) - 1;
            if (prediction > length || prediction < i) { prediction = ballLoc[i] - ballLoc[i + 2]; ballLoc[i + 2] = -ballLoc[i + 2]; }
            ballLoc[i] = prediction;
        }
        paddles[ballLoc[3] > 0] = ballLoc[0] - 2;
    }
}