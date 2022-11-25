#include <iostream>
#include <conio.h>
#include <Windows.h>

// 콘솔창 세팅 
void setConsol() {
    system("mode con cols=110 lines=25");
    system("title TypingProject");

    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.dwSize = 1; //커서 굵기
    ConsoleCursor.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

// 좌표 지정 함수
void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}