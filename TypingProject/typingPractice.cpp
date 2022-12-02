#include "typingpractice.h"
#include "koreanInput.h"
#include "gameLogic.h"

void typingPractice() {
    system("cls"); // 화면 모두 지우기
    basicDraw();
    wordManagerDraw();
    keyboardDraw();
    
    typingPracticeLogic game;
    game.run();
}


void wordManagerDraw() {
    // 첫번째 줄
    gotoxy(2, 2);
    cout << "┏";
    for (int i = 3; i < 95; i++)
    {
        gotoxy(i, 2);
        cout << "━";
    }
        
    gotoxy(96, 2);
    cout << "┓" << endl;

    // 중간 줄
    for (int i = 3; i < 9; i++) {
        gotoxy(2, i);
        cout << "┃";
        gotoxy(96, i);
        cout << "┃" << endl;
    }

    // 마지막 줄
    gotoxy(2, 9);
    cout << "┗";
    for (int i = 3; i < 95; i++)
    {
        gotoxy(i, 9);
        cout << "━";
    }
    gotoxy(96, 9);
    cout << "┛";
}

void keyboardDraw() { // 임시 키보드
    gotoxy(32, 13);
    cout << "ㅂ  ㅈ  ㄷ  ㄱ  ㅅ  ㅛ  ㅕ  ㅑ  ㅐ  ㅔ" << endl;
    gotoxy(32, 15);
    cout << "  ㅁ  ㄴ  ㅇ  ㄹ  ㅎ  ㅗ  ㅓ  ㅏ  ㅣ" << endl;
    gotoxy(32, 17);
    cout << "    ㅋ  ㅌ  ㅊ  ㅍ  ㅠ  ㅜ  ㅡ " << endl;
}