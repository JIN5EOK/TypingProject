#include "mainscreen.h"



void mainRun()
{
    drawAll();
    while (1) {
        int n = keyControl();
        switch (n) {
        case TYPING: { // 1번 눌리면 타자 연습으로 이동
            typingPractice();
            drawAll();
            break;
        }
        case POSITION: { // 2번 눌리면 자리 연습으로 이동
            
            drawAll();
            break;
        }
        case GAME: { // 3번 눌리면 타자 게임으로 이동
            typingGame();
            drawAll();
            break;
        }
        }
    }
    mainRun();
}

void drawAll()
{
    setConsol();
    basicDraw();
    basicText();
    choiceText();
}

void basicDraw() {
    // 첫번째 줄
    gotoxy(0, 0);
    cout << "┏";
    for (int i = 1; i < 100; i++)
    {
        gotoxy(i, 0);
        cout << "━";
    }
    gotoxy(100, 0);
    cout << "┓" << endl;

    // 중간 줄
    for (int i = 1; i < 20; i++) {
        {
            gotoxy(0, i);
            cout << "┃";
            gotoxy(100, i);
            cout << "┃";
        }
    }

    // 마지막 줄
    gotoxy(0, 20);
    cout << "┗";
    for (int i = 1; i < 100; i++)
    {
        gotoxy(i, 20);
        cout << "━";
    }
    gotoxy(100, 20);
    cout << "┛";
}

void basicText() {
    gotoxy(20, 4);
    cout << "■■■■■  ■      ■  ■■■■   ■  ■       ■  ■■■■■";
    gotoxy(20, 5);
    cout << "    ■        ■  ■    ■    ■   ■  ■ ■    ■  ■     ";
    gotoxy(20, 6);
    cout << "    ■          ■      ■■■■   ■  ■   ■  ■  ■    ■■";
    gotoxy(20, 7);
    cout << "    ■          ■      ■         ■  ■     ■■  ■      ■";
    gotoxy(20, 8);
    cout << "    ■          ■      ■         ■  ■       ■  ■■■■■";
    gotoxy(45, 11);
    cout << "p r o j e c t";
}

int choiceText() {
    gotoxy(30, 17);
    cout << "1. 타자 연습";
    gotoxy(45, 17);
    cout << "2. 자리 연습";
    gotoxy(60, 17);
    cout << "3. 타자 게임";

    return 0;
}

int keyControl() {
    char temp = _getch(); // 엔터 누르지 않아도 키값 반환

    if (temp == '1') {
        return TYPING;
    }
    else if (temp == '2') {
        return POSITION;
    }
    else if (temp == '3') {
        return GAME;
    }
}


int main() {
    mainRun();
}
