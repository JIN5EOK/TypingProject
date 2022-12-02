#include "mainscreen.h"



void mainRun()
{
    drawAll();
    while (1) {
        int n = keyControl();
        switch (n) {
        case TYPING: { // 1�� ������ Ÿ�� �������� �̵�
            typingPractice();
            drawAll();
            break;
        }
        case POSITION: { // 2�� ������ �ڸ� �������� �̵�
            
            drawAll();
            break;
        }
        case GAME: { // 3�� ������ Ÿ�� �������� �̵�
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
    // ù��° ��
    gotoxy(0, 0);
    cout << "��";
    for (int i = 1; i < 100; i++)
    {
        gotoxy(i, 0);
        cout << "��";
    }
    gotoxy(100, 0);
    cout << "��" << endl;

    // �߰� ��
    for (int i = 1; i < 20; i++) {
        {
            gotoxy(0, i);
            cout << "��";
            gotoxy(100, i);
            cout << "��";
        }
    }

    // ������ ��
    gotoxy(0, 20);
    cout << "��";
    for (int i = 1; i < 100; i++)
    {
        gotoxy(i, 20);
        cout << "��";
    }
    gotoxy(100, 20);
    cout << "��";
}

void basicText() {
    gotoxy(20, 4);
    cout << "������  ��      ��  �����   ��  ��       ��  ������";
    gotoxy(20, 5);
    cout << "    ��        ��  ��    ��    ��   ��  �� ��    ��  ��     ";
    gotoxy(20, 6);
    cout << "    ��          ��      �����   ��  ��   ��  ��  ��    ���";
    gotoxy(20, 7);
    cout << "    ��          ��      ��         ��  ��     ���  ��      ��";
    gotoxy(20, 8);
    cout << "    ��          ��      ��         ��  ��       ��  ������";
    gotoxy(45, 11);
    cout << "p r o j e c t";
}

int choiceText() {
    gotoxy(30, 17);
    cout << "1. Ÿ�� ����";
    gotoxy(45, 17);
    cout << "2. �ڸ� ����";
    gotoxy(60, 17);
    cout << "3. Ÿ�� ����";

    return 0;
}

int keyControl() {
    char temp = _getch(); // ���� ������ �ʾƵ� Ű�� ��ȯ

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
