#include <iostream>
#include <conio.h>
#include <Windows.h>

// 키보드 값
#define TYPING 0
#define POSITION 1
#define GAME 2
using namespace std;

void setConsol();
void basicDraw();
void basicText();
int choiceText();
int keyControl();
void typingPractice();
void typingGame();
void gotoxy(int x, int y);