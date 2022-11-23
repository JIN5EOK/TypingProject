#include "typingpractice.h"

void typingPractice() {
    system("cls"); // 화면 모두 지우기
    basicDraw();
    wordManagerDraw();
    scoreManagerText();
    keyboardDraw();
    wordText();
}

void scoreManagerText() {
    gotoxy(4, 1);
    cout << "정확도 :";
    gotoxy(39, 1);
    cout << "타자 시간 :";
    gotoxy(74, 1);
    cout << "타수 :";
}

void wordManagerDraw() {
    // 첫번째 줄
    gotoxy(2, 2);
    cout << "┏";
    for (int i = 2; i < 95; i++)
        cout << "━";
    cout << "┓" << endl;

    // 중간 줄
    for (int i = 1; i < 5; i++) {
        gotoxy(2, 3);
        cout << "┃";
        for (int j = 2; j < 95; j++)
            cout << " ";
        cout << "┃" << endl;
    }

    // 마지막 줄
    gotoxy(2, 9);
    cout << "┗";
    for (int i = 2; i < 95; i++)
        cout << "━";
    cout << "┛";
}

void wordText() {
    int word;
    gotoxy(47, 3);
    cout << "단어1";
    gotoxy(78, 3);
    cout << "단어2";
    gotoxy(42, 7);
    cout << "￣￣￣￣￣￣￣";
    gotoxy(45, 6);
    cin >> word; // cin 대신 만든 거 연결..
}

void keyboardDraw() { // 임시 키보드
    gotoxy(32, 13);
    cout << "ㅂ  ㅈ  ㄷ  ㄱ  ㅅ  ㅛ  ㅕ  ㅑ  ㅐ  ㅔ" << endl;
    gotoxy(32, 15);
    cout << "  ㅁ  ㄴ  ㅇ  ㄹ  ㅎ  ㅗ  ㅓ  ㅏ  ㅣ" << endl;
    gotoxy(32, 17);
    cout << "    ㅋ  ㅌ  ㅊ  ㅍ  ㅠ  ㅜ  ㅡ " << endl;
}