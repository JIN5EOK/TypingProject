#include "dinogame.h"

void typingGame() {
    system("cls");
    
    scoreDraw();
    basicDraw();
    dinousDraw();
    while (true) { // ������ ����Ǵ� ����
        legUpdate();
    }
}

void legUpdate() {
    static bool legFlag = false; // ���ŵ� �� ���� ��ġ�� �ٲ�
    legFlag = !legFlag;

    if (legFlag)
    {
        gotoxy(4, 17);
        cout << "         #   ##    " << endl;
        gotoxy(4, 18);
        cout << "         ##         ";
    }
    else
    {
        gotoxy(4, 17);
        cout << "          ##  #     " << endl;
        gotoxy(4, 18);
        cout << "              ##    ";
    }
}

void dinousDraw() {

    gotoxy(4, 8);
    cout << "         ###### " << endl;
    gotoxy(4, 9);
    cout << "         ## #####" << endl;
    gotoxy(4, 10);
    cout << "         #######" << endl;
    gotoxy(4, 11);
    cout << "     #   ####      " << endl;
    gotoxy(4, 12);
    cout << "     ##  #######  " << endl;
    gotoxy(4, 13);
    cout << "      ## ###### " << endl;
    gotoxy(4, 14);
    cout << "       ##########   " << endl;
    gotoxy(4, 15);
    cout << "        ########   " << endl;
    gotoxy(4, 16);
    cout << "         ######    " << endl;


    // �ٴ� �׸�
    gotoxy(2, 19);
    for (int i = 1; i < 50; i++)
        cout << "��";
}

void scoreDraw() {
    gotoxy(94, 1);
    cout << "score";
}

void gameOver() {
    gotoxy(23, 5);
    cout << "�������  �������  ��        ��  ������" << endl;
    gotoxy(23, 6);
    cout << "��            ��        ��  ���    ���  ��" << endl;
    gotoxy(23, 7);
    cout << "��    ����  �������  �� ��  �� ��  ������" << endl;
    gotoxy(23, 8);
    cout << "��        ��  ��        ��  ��  ���  ��  ��" << endl;
    gotoxy(23, 9);
    cout << "�������  ��        ��  ��   ��   ��  ������" << endl;

    gotoxy(25, 11);
    cout << "�������  ��      ��  ������  ������" << endl;
    gotoxy(25, 12);
    cout << "��        ��   ��    ��   ��          ��      ��" << endl;
    gotoxy(25, 13);
    cout << "��        ��    ��  ��    ������  ������" << endl;
    gotoxy(25, 14);
    cout << "��        ��     ���     ��          ����" << endl;
    gotoxy(25, 15);
    cout << "�������      ��      ������  ��  ����";
}