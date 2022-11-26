#pragma once
#include <iostream>
#include <string>
#include "words.h"
#include <locale>
#include "koreanInput.h"
#include <Windows.h>
#include "mainscreen.h"
#include <time.h>

class typingPracticeLogic
{
	int accuracy = 100; // ��Ȯ��, ���� ���� * 60 / �Է°���
	int speed = 0; // Ÿ��
	clock_t playTime; // ��ü �÷��� �ð� ���� ��������
	clock_t startTime; // ��ü �÷��� ���۽ð�
	clock_t wordPlayTime; // ���� �ܾ ġ�� �������� ���� ��������
	clock_t wordStartTime; // ���� �ܾ� Ÿ������ ������ �ð�
	clock_t currentTime; // ���� �ð�
	wstring nextWord; // �����ܾ�




	void printing(wstring _target); // ȭ��ǥ�� ������

	int chkPerfect(wstring _target); // �¾Ҵ��� üũ

	void timer(); // �÷��� �ð� ����

	void calcSpeed(); // Ÿ�� ����
public:
	void playPractice(); // Ÿ�ڿ��� �����Լ�, ���� �׽�Ʈ ��

};

