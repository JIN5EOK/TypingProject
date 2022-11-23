#include "dinogame.h"

void typingGame() {
    system("cls");
    basicDraw();
    scoreDraw();

    while (true) { // 게임이 진행되는 동안
        dinousDraw();
    }
}

void dinousDraw() {
    static bool legFlag = false; // 갱신될 때 발의 위치를 바꿈
    gotoxy(1, 8);

    cout << "         ###### " << endl;
    cout << "         ## #####" << endl;
    cout << "         #######" << endl;
    cout << "     #   ####      " << endl;
    cout << "     ##  #######  " << endl;
    cout << "      ## ###### " << endl;
    cout << "       ##########   " << endl;
    cout << "        ########   " << endl;
    cout << "         ######    " << endl;

    if (legFlag)
    {
        cout << "         #   ##    " << endl;
        cout << "         ##         ";
    }
    else
    {
        cout << "          ##  #     " << endl;
        cout << "              ##    ";
    }

    legFlag = !legFlag;

    // 바닥 그림
    gotoxy(2, 19);
    for (int i = 1; i < 50; i++)
        cout << "■";
}

void scoreDraw() {
    gotoxy(94, 1);
    cout << "score";
}

void gameOver() {
    gotoxy(23, 5);
    cout << "■■■■■■  ■■■■■■  ■        ■  ■■■■■" << endl;
    gotoxy(23, 6);
    cout << "■            ■        ■  ■■    ■■  ■" << endl;
    gotoxy(23, 7);
    cout << "■    ■■■  ■■■■■■  ■ ■  ■ ■  ■■■■■" << endl;
    gotoxy(23, 8);
    cout << "■        ■  ■        ■  ■  ■■  ■  ■" << endl;
    gotoxy(23, 9);
    cout << "■■■■■■  ■        ■  ■   ■   ■  ■■■■■" << endl;

    gotoxy(25, 11);
    cout << "■■■■■■  ■      ■  ■■■■■  ■■■■■" << endl;
    gotoxy(25, 12);
    cout << "■        ■   ■    ■   ■          ■      ■" << endl;
    gotoxy(25, 13);
    cout << "■        ■    ■  ■    ■■■■■  ■■■■■" << endl;
    gotoxy(25, 14);
    cout << "■        ■     ■■     ■          ■■■" << endl;
    gotoxy(25, 15);
    cout << "■■■■■■      ■      ■■■■■  ■  ■■■";
}