#include "typingpractice.h"
#include "koreanInput.h"
#include "gameLogic.h"

void typingPractice() {
    system("cls"); // ȭ�� ��� �����
    basicDraw();
    wordManagerDraw();
    keyboardDraw();
    
    typingPracticeLogic game;
    game.run();
}


void wordManagerDraw() {
    // ù��° ��
    gotoxy(2, 2);
    cout << "��";
    for (int i = 3; i < 95; i++)
    {
        gotoxy(i, 2);
        cout << "��";
    }
        
    gotoxy(96, 2);
    cout << "��" << endl;

    // �߰� ��
    for (int i = 3; i < 9; i++) {
        gotoxy(2, i);
        cout << "��";
        gotoxy(96, i);
        cout << "��" << endl;
    }

    // ������ ��
    gotoxy(2, 9);
    cout << "��";
    for (int i = 3; i < 95; i++)
    {
        gotoxy(i, 9);
        cout << "��";
    }
    gotoxy(96, 9);
    cout << "��";
}

void keyboardDraw() { // �ӽ� Ű����
    gotoxy(32, 13);
    cout << "��  ��  ��  ��  ��  ��  ��  ��  ��  ��" << endl;
    gotoxy(32, 15);
    cout << "  ��  ��  ��  ��  ��  ��  ��  ��  ��" << endl;
    gotoxy(32, 17);
    cout << "    ��  ��  ��  ��  ��  ��  �� " << endl;
}