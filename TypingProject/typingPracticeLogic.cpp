#include <iostream>
#include <string>
#include "words.h"
#include <locale>
#include "koreanInput.h"
#include <Windows.h>
#include "mainscreen.h"
#include <time.h>
#include "gameLogic.h"


void typingPracticeLogic::update() // �������� �����Ѵ�.
{
	std::wstring inputString = korInput::getWString();
	gotoxy(4, 3);
	std::cout << "                                                            ";
	gotoxy(4, 3);
	std::cout << "�����ܾ� : ";
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

	if (inputString.length() > 0) // �Էµ��� �ʾ�����
		accuracy = 100 * ((float)right / (float)inputString.length());
	else
		accuracy = 0;

	gotoxy(4, 1);
	std::cout << "��Ȯ�� : ";
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
	// Ÿ��ǥ�ÿ� �ð�ǥ�ô� Ű���� �Է°� ������ �ð��� ������ ��� ���ŵǾ�� ��.
	calcSpeed();
	gotoxy(74, 1);
	std::cout << "Ÿ�� : " << speed << "      ";
	timer();
	gotoxy(39, 1);
	std::cout << "Ÿ�� �ð� : " << playTime << "��" << "     ";

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
		if (playCnt >= maxPlayCnt) // ������ �������� break;
			break;

		updateSecond();
		if (_kbhit())
		{
			int input = _getch();
			if (input == 13) // enter �Է�
			{
				pressEnter();
			}
			else if (input == 27) // esc �Է�
			{
				system("cls");
				korInput::eraseTexts();
				return;
			}
			else if(korInput::inputBuffer(input) == 0) // �� �� Ű �Է½� ���� �Է�
			{
				update();
			}
		}
	}

	system("cls");
	std::cout << "��Ȯ�� �Է��� �ܾ� �� : " << answerCnt << "/" << playCnt << std::endl;
	std::cout << "��� ��Ȯ�� : " << ((float)answerCnt / (float)playCnt) * 100  << "%" << std::endl;
	std::cout << "��� Ÿ�� : " << speedAvg << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "-����Ϸ��� EnterŰ�� ��������-" << std::endl;
	while (_getch() != 13)
	{

	}
}

