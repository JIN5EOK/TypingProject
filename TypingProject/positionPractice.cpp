#include "typingpractice.h"
#include "koreanInput.h"
#include "gameLogic.h"
#include <map>

class keyPosition {
    wchar_t accKey; // 현재 강조되고 있는 키
    map<wchar_t, vector<int>>positions{
        {L'ㅂ', {32,13}},
        {L'ㅈ', {36,13}},
        {L'ㄷ', {40,13}},
        {L'ㄱ', {44,13}},
        {L'ㅅ', {48,13}},
        {L'ㅛ', {52,13}},
        {L'ㅕ', {56,13}},
        {L'ㅑ', {60,13}},
        {L'ㅐ', {64,13}},
        {L'ㅔ', {68,13}},
        {L'ㅁ', {34,15}},
        {L'ㄴ', {38,15}},
        {L'ㅇ', {42,15}},
        {L'ㄹ', {46,15}},
        {L'ㅎ', {50,15}},
        {L'ㅗ', {54,15}},
        {L'ㅓ', {58,15}},
        {L'ㅏ', {62,15}},
        {L'ㅣ', {66,15}},
        {L'ㅋ', {36,17}},
        {L'ㅌ', {40,17}},
        {L'ㅊ', {44,17}},
        {L'ㅍ', {48,17}},
        {L'ㅠ', {52,17}},
        {L'ㅜ', {56,17}},
        {L'ㅡ', {60,17}},
    };

public:
    void printKey()
    {
        gotoxy(32, 13);
        cout << "ㅂ  ㅈ  ㄷ  ㄱ  ㅅ  ㅛ  ㅕ  ㅑ  ㅐ  ㅔ";
        gotoxy(32, 15);
        cout << "  ㅁ  ㄴ  ㅇ  ㄹ  ㅎ  ㅗ  ㅓ  ㅏ  ㅣ";
        gotoxy(32, 17);
        cout << "    ㅋ  ㅌ  ㅊ  ㅍ  ㅠ  ㅜ  ㅡ ";
    }

    void accentKey(char _key) // 특정 키를 강조한다
    {
        deAccentKey();
        
        textcolor(9, 0);
        accKey = hangulTables::ascii2Hangul(_key);
        gotoxy(positions.at(accKey)[0], positions.at(accKey)[1]);
        std::wcout << accKey;
        textcolor(15, 0);
    }

    void deAccentKey() // 현재 강조중인 키를 초기화
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
    srand((unsigned int)time(NULL)); // getWord에서 랜덤값을 뽑기 위해 현재 시간을 시드로 사용

    system("cls"); // 화면 모두 지우기
    basicDraw();
    wordManagerDraw();
    keyPosition keyPos;
    
    
    wchar_t kbdArr[] = {
        L'ㅂ',L'ㅈ',L'ㄷ',L'ㄱ',L'ㅅ',L'ㅛ',L'ㅕ',L'ㅑ',L'ㅐ',L'ㅔ',
          L'ㅁ',L'ㄴ',L'ㅇ',L'ㄹ',L'ㅎ',L'ㅗ',L'ㅓ',L'ㅏ',L'ㅣ',
          L'ㅋ',L'ㅌ',L'ㅊ',L'ㅍ',L'ㅠ',L'ㅜ',L'ㅡ'
    };
    char targetKey;

    keyPos.printKey();
    targetKey = getRandomKey();
    keyPos.accentKey(targetKey);

    gotoxy(35, 2);
    std::cout << "연습을 그만두려면 ESC를 누르세요";
    
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