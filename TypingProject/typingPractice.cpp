#include "typingpractice.h"

void typingPractice() {
    system("cls"); // ȭ�� ��� �����
    basicDraw();
    wordManagerDraw();
    scoreManagerText();
    keyboardDraw();
    wordText();
}

void scoreManagerText() {
    gotoxy(4, 1);
    cout << "��Ȯ�� :";
    gotoxy(39, 1);
    cout << "Ÿ�� �ð� :";
    gotoxy(74, 1);
    cout << "Ÿ�� :";
}

void wordManagerDraw() {
    // ù��° ��
    gotoxy(2, 2);
    cout << "��";
    for (int i = 2; i < 95; i++)
        cout << "��";
    cout << "��" << endl;

    // �߰� ��
    for (int i = 1; i < 5; i++) {
        gotoxy(2, 3);
        cout << "��";
        for (int j = 2; j < 95; j++)
            cout << " ";
        cout << "��" << endl;
    }

    // ������ ��
    gotoxy(2, 9);
    cout << "��";
    for (int i = 2; i < 95; i++)
        cout << "��";
    cout << "��";
}

void wordText() {
    int word;
    gotoxy(47, 3);
    cout << "�ܾ�1";
    gotoxy(78, 3);
    cout << "�ܾ�2";
    gotoxy(42, 7);
    cout << "��������������";
    gotoxy(45, 6);
    cin >> word; // cin ��� ���� �� ����..
}

void keyboardDraw() { // �ӽ� Ű����
    gotoxy(32, 13);
    cout << "��  ��  ��  ��  ��  ��  ��  ��  ��  ��" << endl;
    gotoxy(32, 15);
    cout << "  ��  ��  ��  ��  ��  ��  ��  ��  ��" << endl;
    gotoxy(32, 17);
    cout << "    ��  ��  ��  ��  ��  ��  �� " << endl;
}