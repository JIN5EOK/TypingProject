#include "typingpractice.h"
#include "koreanInput.h"

void krInputTester();

void typingPractice() {
    
    system("cls"); // ȭ�� ��� �����
    basicDraw();
    wordManagerDraw();
    //scoreManagerText();
    keyboardDraw();
    //wordText();
    while (true)
    {
        gotoxy(45, 6);
        krInputTester();
    }
}

/*
void scoreManagerText() {
    gotoxy(4, 1);
    cout << "��Ȯ�� :";
    gotoxy(39, 1);
    cout << "Ÿ�� �ð� :";
    gotoxy(74, 1);
    cout << "Ÿ�� :";
}
*/

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
/*
void wordText() {
    
    gotoxy(47, 3);
    cout << "�ܾ�1";
    gotoxy(78, 3);
    cout << "�ܾ�2";
    gotoxy(42, 7);
    //���⿡ �ܾ� ����
    
    gotoxy(45, 6);
    
}
*/
void keyboardDraw() { // �ӽ� Ű����
    gotoxy(32, 13);
    cout << "��  ��  ��  ��  ��  ��  ��  ��  ��  ��" << endl;
    gotoxy(32, 15);
    cout << "  ��  ��  ��  ��  ��  ��  ��  ��  ��" << endl;
    gotoxy(32, 17);
    cout << "    ��  ��  ��  ��  ��  ��  �� " << endl;
}