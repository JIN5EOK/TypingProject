#include <iostream>
#include <conio.h>
#include <Windows.h>

// �ܼ�â ���� 
void setConsol() {
    system("mode con cols=110 lines=25");
    system("title TypingProject");

    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.dwSize = 1; //Ŀ�� ����
    ConsoleCursor.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

// ��ǥ ���� �Լ�
void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}