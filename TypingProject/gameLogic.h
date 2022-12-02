
#pragma once
#include <iostream>
#include <string>
#include "words.h"
#include <locale>
#include "koreanInput.h"
#include <Windows.h>
#include "mainscreen.h"
#include <time.h>

class gameLogic
{
public:
	Words words;
	int maxPlayCnt = 0; // �ִ� ��� �ܾ���� �÷��� ��������
	int playCnt = 0; // � �ܾ �÷��� �ߴ���
	wstring currWord; // ����ܾ�
	wstring nextWord; // �����ܾ�

	clock_t playTime; // ��ü �÷��� �ð��� �󸶳� ���������� ����
	clock_t startTime; // ���� �÷��̸� ������ �ð�
	clock_t currentTime; // ���� �ð��� ����
	clock_t wordPlayTime; // ���� �ܾ ġ�� �������� ���� ��������
	clock_t wordStartTime; // ���� �ܾ� Ÿ������ ������ �ð�

	void init(); // ���� ���� �ʱ�ȭ �� ��
	int chkPerfect(); // �ܾ �¾Ҵ��� üũ
	void getNextWord(); // ������ ���� �ܾ� ������
	void timer(); // �÷��� �ð� ����
	virtual void update() = 0; // ȭ�������� ������Ʈ �Լ�, �����Լ�
	virtual void updateSecond() = 0; // 1�ʸ��� ������Ʈ, �����Լ�
	virtual void pressEnter() = 0; // ���� �������� ����Ǵ� ��
	virtual void run() = 0; // ���� ���� �Լ�
};



class typingPracticeLogic : protected gameLogic
{
	int answerCnt = 0; // ��� �������
	int speedAvg = 0; // ���ǵ� ���
	int accuracyAvg = 0; // ���ǵ� ���
	int accuracy = 100; // ��Ȯ��, ���� ���� * 60 / �Է°���
	int speed = 0; // Ÿ��
	
	void calcSpeed(); // Ÿ�� ����
	void calcAvg();
	void update(); // ������Ʈ
	void updateSecond(); // 1�ʸ��� �ڵ�����
	void pressEnter();
public:
	void run(); // Ÿ�ڿ��� �����Լ�
};

class dinoGameLogic : protected gameLogic
{
	int defaultXPos = 95;
	int xPos = defaultXPos; // ���� �ܾ��� x�� 
	int score = 0; //���� ����
	void legUpdate();
	void moveWord();
	void update();
	void updateSecond();
	void scorePlus();
	void pressEnter();
	void gameOver();
	int isDead();
public:
	void run(); // Ÿ�ڿ��� �����Լ�
};
