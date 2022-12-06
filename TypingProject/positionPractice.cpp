#include "typingpractice.h"
#include "koreanInput.h"
#include "gameLogic.h"
#include <map>

class keyPosition {
    wchar_t accKey; // ���� �����ǰ� �ִ� Ű
    map<wchar_t, vector<int>>positions{
        {L'��', {32,13}},
        {L'��', {36,13}},
        {L'��', {40,13}},
        {L'��', {44,13}},
        {L'��', {48,13}},
        {L'��', {52,13}},
        {L'��', {56,13}},
        {L'��', {60,13}},
        {L'��', {64,13}},
        {L'��', {68,13}},
        {L'��', {34,15}},
        {L'��', {38,15}},
        {L'��', {42,15}},
        {L'��', {46,15}},
        {L'��', {50,15}},
        {L'��', {54,15}},
        {L'��', {58,15}},
        {L'��', {62,15}},
        {L'��', {66,15}},
        {L'��', {36,17}},
        {L'��', {40,17}},
        {L'��', {44,17}},
        {L'��', {48,17}},
        {L'��', {52,17}},
        {L'��', {56,17}},
        {L'��', {60,17}},
    };

public:
    void printKey()
    {
        gotoxy(32, 13);
        cout << "��  ��  ��  ��  ��  ��  ��  ��  ��  ��";
        gotoxy(32, 15);
        cout << "  ��  ��  ��  ��  ��  ��  ��  ��  ��";
        gotoxy(32, 17);
        cout << "    ��  ��  ��  ��  ��  ��  �� ";
    }

    void accentKey(char _key) // Ư�� Ű�� �����Ѵ�
    {
        deAccentKey();
        
        textcolor(9, 0);
        accKey = hangulTables::ascii2Hangul(_key);
        gotoxy(positions.at(accKey)[0], positions.at(accKey)[1]);
        std::wcout << accKey;
        textcolor(15, 0);
    }

    void deAccentKey() // ���� �������� Ű�� �ʱ�ȭ
    {
        if (accKey != NULL)
        {
            
            gotoxy(positions.at(accKey)[0], positions.at(accKey)[1]);
            std::wcout << accKey;
            
        }
    }
};

char getRandomKey()
{
    return (rand() % 26) + 97;
}

void positionPractice() {
    srand((unsigned int)time(NULL)); // getWord���� �������� �̱� ���� ���� �ð��� �õ�� ���

    system("cls"); // ȭ�� ��� �����
    basicDraw();
    wordManagerDraw();
    keyPosition keyPos;
    
    
    wchar_t kbdArr[] = {
        L'��',L'��',L'��',L'��',L'��',L'��',L'��',L'��',L'��',L'��',
          L'��',L'��',L'��',L'��',L'��',L'��',L'��',L'��',L'��',
          L'��',L'��',L'��',L'��',L'��',L'��',L'��'
    };
    char targetKey;

    keyPos.printKey();
    targetKey = getRandomKey();
    keyPos.accentKey(targetKey);

    gotoxy(35, 2);
    std::cout << "������ �׸��η��� ESC�� ��������";
    
    gotoxy(50, 6);
    std::wcout << hangulTables::ascii2Hangul(targetKey);
    while (true)
    {
        if (_kbhit)
        {
            int input = _getch();
            if (input == 27)
            {
                break;
            }

            if (input == targetKey)
            {
                targetKey = getRandomKey();
                keyPos.accentKey(targetKey);
                gotoxy(50, 6);
                std::wcout << hangulTables::ascii2Hangul(targetKey);
            }
        }
        
    }
} 