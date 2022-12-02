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
	if (xPos - currWord.length() > 21) // x��ǥ ��ġ�� ������ġ���� �۾����� �浹�� �����Ѵ�.
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void dinoGameLogic::legUpdate() {
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

void dinoGameLogic::moveWord()
{
	gotoxy(24, 17);
	std::cout << "                                                                            ��";
	gotoxy(xPos - currWord.length() -1, 17);
	std::wcout << currWord;
	xPos -= 3 + ((playCnt / 3) * 2); // �ܾ� 3���� ĥ������ �ӵ��� ��������.
}

void dinoGameLogic::updateSecond()
{
	static clock_t prevPlayTime;

	if (prevPlayTime != playTime) // �÷��� Ÿ�ӿ��� 1�ʰ� ���������� ������Ʈ ����
	{
		prevPlayTime = playTime;
		moveWord();
	}
}

void dinoGameLogic::scorePlus()
{
	score += 10 * currWord.length(); // �ܾ��� ���̿� ����Ͽ� ������ �� ������.
	gotoxy(4, 1);
	cout << "score : " << score; // �������� ����ϱ�
}
void dinoGameLogic::update()
{
	std::wstring inputString = korInput::getWString(); // ���� �Էµ� �ѱ��� ����

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
	if (chkPerfect() == 0) // Ÿ�ڿ������� �޸� �ܾ �Ϻ��� ������ ���� ���� �ܾ�� �Ѿ��.
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
void dinoGameLogic::gameOver() // ���ӿ��� ���
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
	std::cout << "����� ������ : " << score;
	gotoxy(25, 5);
	std::cout << "EnterŰ�� ���� ó�� ȭ������ ���ư�����.";

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
	while (isDead() == 0) // ������ ���� ��
	{
		timer();
		updateSecond(); // 1�ʸ��� ������Ʈ
		legUpdate();
		if (_kbhit())
		{
			int input = _getch();
			if (input == 13) // enter �Է�
			{
				pressEnter();
			}
			else if (input == 27) // esc �Է�, ������ ������
			{
				system("cls");
				korInput::eraseTexts();
				return;
			}
			else if (korInput::inputBuffer(input) == 0) // �� �� Ű �Է½� ���� �Է�
			{
				update();
			}
		}
	}
	gameOver();

}