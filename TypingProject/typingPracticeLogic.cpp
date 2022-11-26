#include <iostream>
#include <string>
#include "words.h"
#include <locale>
#include "koreanInput.h"
#include <Windows.h>
#include "mainscreen.h"
#include <time.h>
int accuracy = 100; // 맞은 개수 / 입력개수
int speed = 0;
clock_t playTime;
clock_t startTime;
clock_t wordPlayTime;
clock_t wordStartTime;
clock_t currentTime;


wstring nextWord;

void printing(wstring _target)
{
	std::wstring inputString = korInput::getWString();
	for (int i = 6; i <= 8; i++) // 글자 지우기
	{
		for (int j = 3; j < 90; j++)
		{
			gotoxy(j, i);
			std::cout << " ";
		}
	}
	gotoxy(4, 3);
	std::cout << "다음단어 : ";
	std::wcout << nextWord << "                        ";


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
	std::cout << "정확도 : ";
	cout.width(3);
	std::cout<<accuracy << "%    ";

	gotoxy(4, 7);
	korInput::printBuffer();

	for (int i = 21; i <= 23; i++)
	{
		for (int j = 4; j < 90; j++)
		{
			gotoxy(j, i);
			std::cout << " ";
		}
	}

	gotoxy(0, 21);
	korInput::printInfo();

}

int chkPerfect(wstring _target)
{
	std::wstring inputString = korInput::getWString();

	if (_target == inputString)
		return 0;
	else
		return -1;
}

void timer()
{
	currentTime = clock();
	playTime = (currentTime - startTime) / CLOCKS_PER_SEC;
	wordPlayTime = (currentTime - wordStartTime) / CLOCKS_PER_SEC;
	gotoxy(39, 1);
	std::cout << "타자 시간 : " << playTime << "초";

}

void calcSpeed()
{
	int len = korInput::getWString().length();
	if (len > 0 && wordPlayTime > 0)
		speed = ((len * 60) / (int)wordPlayTime) * (float) accuracy / 100.f;
	else
		speed = 0;

	gotoxy(74, 1);
	std::cout << "타수 : " << speed << "      ";
		
}

void krInputTester()
{
	startTime = clock() - 1000; // 타자시간 1초부터 시작하도록 1000을 뺀다.
	setlocale(LC_ALL, "korean");

	Words words;
	words.addWord(L"백석대학교 컴퓨터공학부");
	words.addWord(L"남산위에 저 소나무");
	words.addWord(L"무궁화 삼천리 화려강산");
	words.addWord(L"대한사람 대한으로 길이 보전하세");
	words.addWord(L"이 기상과 이 맘으로 충성을 다 하여");
	words.addWord(L"동해물과 백두산이 마르고 닳도록");
	words.addWord(L"하느님이 보우하사 우리나라 만세");
	
	gotoxy(4, 1);
	std::cout << "정확도 : ";
	
	std::wstring s = words.getWord();
	nextWord = words.getWord();
	gotoxy(4, 3);
	std::cout << "다음단어 : ";
	std::wcout << nextWord << "                        ";

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
					gotoxy(4, 8);
					std::cout << "Perfect!" << std::endl;
				}
				else
				{
					gotoxy(4, 8);
					std::cout << "Wrong.." << std::endl;
				}
				korInput::eraseTexts(); // 입력기에 입력된 글자들을 지움
				s = nextWord;
				nextWord = words.getWord();
				Sleep(1000);


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

