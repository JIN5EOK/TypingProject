#include <iostream>
#include <string>
#include "words.h"
#include <locale>
#include "koreanInput.h"
#include <Windows.h>
#include "mainscreen.h"
#include <time.h>
#include "gameLogic.h"


void typingPracticeLogic::update() // 정보들을 갱신한다.
{
	std::wstring inputString = korInput::getWString();
	gotoxy(4, 3);
	std::cout << "                                                            ";
	gotoxy(4, 3);
	std::cout << "다음단어 : ";
	std::wcout << nextWord;

	gotoxy(4, 6);
	std::cout << "                                                 ";
	gotoxy(4, 6);

	int right = 0;
	for (int i = 0; i < currWord.length(); i++)
	{
		if (i < inputString.length())
		{
			if (currWord[i] == inputString[i])
			{
				right++;
				textcolor(9, 0);
			}
			else
				textcolor(4, 0);
		}

		std::wcout << currWord[i];
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
	std::cout << "                                                                               ";
	gotoxy(4, 7);
	korInput::printBuffer();


	gotoxy(0, 21);
	std::cout << "                                                                               ";
	gotoxy(0, 22);
	std::cout << "                                                                               ";
	gotoxy(0, 21);
	korInput::printInfo();
	gotoxy(4, 10);
	std::cout << "                           ";
	gotoxy(4, 10);
	std::cout << playCnt << '/' << maxPlayCnt << "       ";
}

void typingPracticeLogic::updateSecond()
{
	// 타수표시와 시간표시는 키보드 입력과 별개로 시간이 지나면 계속 갱신되어야 함.
	calcSpeed();
	gotoxy(74, 1);
	std::cout << "타수 : " << speed << "      ";
	timer();
	gotoxy(39, 1);
	std::cout << "타자 시간 : " << playTime << "초" << "     ";

}

void typingPracticeLogic::calcSpeed()
{
	int len = korInput::getWString().length();
	if (len > 0 && wordPlayTime > 0)
		speed = ((len * 60) / (int)wordPlayTime) * (float) accuracy / 100.f;
	else
		speed = ((len * 60) * (float)accuracy / 100.f);
}

void typingPracticeLogic::calcAvg()
{
	if (playCnt == 0)
		speedAvg = speed;
	else
		speedAvg = (speedAvg * playCnt + speed) / (playCnt + 1);

	if (accuracyAvg == 0)
		accuracyAvg = accuracy;
	else
		accuracyAvg = (accuracyAvg * playCnt + accuracy) / (playCnt + 1);
}

void typingPracticeLogic::pressEnter()
{
	
	if (chkPerfect() == 0)
		answerCnt++;

	calcAvg();
	wordStartTime = clock();
	playCnt++;
	getNextWord();
	update();
}


void typingPracticeLogic::run()
{
	maxPlayCnt = 10;
	init();
	currWord = words.getWord();
	nextWord = words.getWord();
	update();

	korInput::printBuffer();
	while (true)
	{
		if (playCnt >= maxPlayCnt) // 게임이 끝났으면 break;
			break;

		updateSecond();
		if (_kbhit())
		{
			int input = _getch();
			if (input == 13) // enter 입력
			{
				pressEnter();
			}
			else if (input == 27) // esc 입력
			{
				system("cls");
				korInput::eraseTexts();
				return;
			}
			else if(korInput::inputBuffer(input) == 0) // 그 외 키 입력시 문자 입력
			{
				update();
			}
		}
	}

	system("cls");
	std::cout << "정확히 입력한 단어 수 : " << answerCnt << "/" << playCnt << std::endl;
	std::cout << "평균 정확도 : " << ((float)answerCnt / (float)playCnt) * 100  << "%" << std::endl;
	std::cout << "평균 타수 : " << speedAvg << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "-계속하려면 Enter키를 누르세요-" << std::endl;
	while (_getch() != 13)
	{

	}
}

