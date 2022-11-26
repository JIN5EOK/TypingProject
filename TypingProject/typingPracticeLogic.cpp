#include <iostream>
#include <string>
#include "words.h"
#include <locale>
#include "koreanInput.h"
#include <Windows.h>
#include "mainscreen.h"
#include <time.h>
#include "gameLogic.h"


void typingPracticeLogic::printing(wstring _target)
{
	std::wstring inputString = korInput::getWString();
	gotoxy(4, 3);
	std::cout << "                                                            ";
	gotoxy(4, 3);
	std::cout << "다음단어 : ";
	std::wcout << nextWord;


	gotoxy(4, 6);
	std::cout << "                                   ";
	gotoxy(4, 6);

	int right = 0;
	for (int i = 0; i < _target.length(); i++)
	{
		if (i < inputString.length())
		{
			if (_target[i] == inputString[i])
			{
				right++;
				textcolor(9, 0);
			}
			else
				textcolor(4, 0);
		}

		std::wcout << _target[i];
		textcolor(15, 0);

	}

	if (inputString.length() > 0) // 입력되지 않았으면
		accuracy = 100 * ((float)right / (float)inputString.length());
	else
		accuracy = 0;

	gotoxy(4, 1);
	std::cout << "              ";
	gotoxy(4, 1);
	std::cout << "정확도 : ";
	cout.width(3);
	std::cout<<accuracy << "%    ";

	gotoxy(4, 7);
	std::cout << "                                                                               ";
	gotoxy(4, 7);
	korInput::printBuffer();


	gotoxy(0, 21);
	std::cout << "                                                                               ";
	gotoxy(0, 22);
	std::cout << "                                                                               ";
	gotoxy(0, 21);
	korInput::printInfo();

}

int typingPracticeLogic::chkPerfect(wstring _target)
{
	std::wstring inputString = korInput::getWString();

	if (_target == inputString)
		return 0;
	else
		return -1;
}

void typingPracticeLogic::timer()
{
	currentTime = clock();
	playTime = (currentTime - startTime) / CLOCKS_PER_SEC;
	wordPlayTime = (currentTime - wordStartTime) / CLOCKS_PER_SEC;
	gotoxy(39, 1);
	std::cout << "타자 시간 : " << playTime << "초" << "     ";

}

void typingPracticeLogic::calcSpeed()
{
	int len = korInput::getWString().length();
	if (len > 0 && wordPlayTime > 0)
		speed = ((len * 60) / (int)wordPlayTime) * (float) accuracy / 100.f;
	else
		speed = 0;

	gotoxy(74, 1);
	std::cout << "타수 : " << speed << "      ";
}

void typingPracticeLogic::playPractice()
{
	startTime = clock() - 1000; // 타자시간 1초부터 시작하도록 1000을 뺀다.
	setlocale(LC_ALL, "korean");

	Words words;
	words.addWord(L"낄끼빠빠");
	words.addWord(L"악으로 깡으로 버텨라");
	words.addWord(L"군침이 싹 돈다");
	words.addWord(L"어쩔티비");
	words.addWord(L"갑자기 분위기 싸해짐");
	words.addWord(L"임포스터");
	words.addWord(L"멍청비용");
	
	gotoxy(4, 1);
	std::cout << "정확도 : -";
	
	std::wstring s = words.getWord();
	nextWord = words.getWord();
	gotoxy(4, 3);
	std::cout << "다음단어 : ";
	std::wcout << nextWord << "                                                                  ";

	gotoxy(4, 6);
	
	std::wcout  << s << std::endl;

	gotoxy(4, 7);
	korInput::printBuffer();

	while (true)
	{
		timer();
		calcSpeed();
		if (_kbhit())
		{
			int input = _getch();
			if (input == 13)
			{
				if (chkPerfect(s) == 0)
				{
					gotoxy(4, 10);
					textcolor(9, 0);
					std::cout << "Perfect!" << std::endl;
					textcolor(15, 0);
				}
				else
				{
					gotoxy(4, 10);
					textcolor(4, 0);
					std::cout << "Wrong.." << std::endl;
					textcolor(15, 0);
				}
				korInput::eraseTexts(); // 입력기에 입력된 글자들을 지움
				s = nextWord;
				nextWord = words.getWord();
				Sleep(1000);

				gotoxy(4, 10);
				std::cout << "                 ";

				wordStartTime = clock() - 1000;
				printing(s);
				continue;
			}
			if(korInput::inputBuffer(input) == 0)
			{
				printing(s);
			}
		}
	}
}

