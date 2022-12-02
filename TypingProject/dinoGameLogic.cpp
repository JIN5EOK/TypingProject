#include <iostream>
#include <string>
#include "words.h"
#include <locale>
#include "koreanInput.h"
#include <Windows.h>
#include "mainscreen.h"
#include <time.h>
#include "gameLogic.h"

int dinoGameLogic::isDead()
{
	if (xPos - currWord.length() > 21) // x좌표 위치가 일정위치보다 작아지면 충돌로 판정한다.
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void dinoGameLogic::legUpdate() {
	static bool legFlag = false; // 갱신될 때 발의 위치를 바꿈
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

void dinoGameLogic::moveWord()
{
	gotoxy(24, 17);
	std::cout << "                                                                            ┃";
	gotoxy(xPos - currWord.length() -1, 17);
	std::wcout << currWord;
	xPos -= 3 + ((playCnt / 3) * 2); // 단어 3개를 칠때마다 속도가 빨라진다.
}

void dinoGameLogic::updateSecond()
{
	static clock_t prevPlayTime;

	if (prevPlayTime != playTime) // 플레이 타임에서 1초가 지날때마다 업데이트 수행
	{
		prevPlayTime = playTime;
		moveWord();
	}
}

void dinoGameLogic::scorePlus()
{
	score += 10 * currWord.length(); // 단어의 길이에 비례하여 점수가 더 증가함.
	gotoxy(4, 1);
	cout << "score : " << score; // 현재점수 출력하기
}
void dinoGameLogic::update()
{
	std::wstring inputString = korInput::getWString(); // 현재 입력된 한글을 얻어옴

	int right = 0;
	gotoxy(25, 4);
	std::cout << "                                                 ";
	gotoxy(25, 4);
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

	gotoxy(25, 5);
	std::cout << "                                                 ";
	gotoxy(25, 5);
	korInput::printBuffer();
	gotoxy(0, 22);
	std::cout << "                                                                               ";
	gotoxy(0, 22);
	std::cout << "                                                                               ";
	gotoxy(0, 22);
	korInput::printInfo();

}
void dinoGameLogic::pressEnter()
{
	if (chkPerfect() == 0) // 타자연습과는 달리 단어를 완벽히 맞췄을 때만 다음 단어로 넘어간다.
	{
		gotoxy(24, 17);
		std::cout << "                                                                           ";
		xPos = defaultXPos;
		scorePlus();
		getNextWord();
		korInput::eraseTexts();
		playCnt++;
		update();
	}
}
void dinoGameLogic::gameOver() // 게임오버 출력
{
	gotoxy(15, 9);
	textcolor(4, 0);
	cout << 'x';
	textcolor(15, 0);
	gotoxy(25, 4);
	std::cout << "                                                 ";
	gotoxy(25, 5);
	std::cout << "                                                 ";
	gotoxy(25, 4);
	std::cout << "당신의 점수는 : " << score;
	gotoxy(25, 5);
	std::cout << "Enter키를 눌러 처음 화면으로 돌아가세요.";

	while (_getch() != 13)
	{
		
	}
}

void dinoGameLogic::run()
{
	maxPlayCnt = 1000;
	init();
	currWord = words.getWord();
	nextWord = words.getWord();
	update();
	while (isDead() == 0) // 죽으면 게임 끝
	{
		timer();
		updateSecond(); // 1초마다 업데이트
		legUpdate();
		if (_kbhit())
		{
			int input = _getch();
			if (input == 13) // enter 입력
			{
				pressEnter();
			}
			else if (input == 27) // esc 입력, 게임을 나간다
			{
				system("cls");
				korInput::eraseTexts();
				return;
			}
			else if (korInput::inputBuffer(input) == 0) // 그 외 키 입력시 문자 입력
			{
				update();
			}
		}
	}
	gameOver();

}