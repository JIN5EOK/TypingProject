#include <iostream>
#include <string>
#include "words.h"
#include <locale>
#include "koreanInput.h"
#include <Windows.h>
#include "mainscreen.h"
#include <time.h>
#include "gameLogic.h"


int gameLogic::chkPerfect() // �ܾ �´����� üũ�Ѵ�.
{
	std::wstring inputString = korInput::getWString(); // ���� �Էµ� �ܾ ���´�.
	if (currWord == inputString) // �Է��ؾ� �ϴ� �ܾ�� �Էµ� �ܾ ���Ͽ� ������ 0 Ʋ���� -1 ����
		return 0;
	else
		return -1;
}

void gameLogic::getNextWord()
{
	korInput::eraseTexts(); // �Է±⿡ �Էµ� ���ڵ��� ����

	currWord = nextWord; // ���� �ܾ ���� �ܾ�� �ű��.
	if (playCnt == maxPlayCnt - 1)
		nextWord = L"----"; // ������ �ܾ��� ��� ----
	else
		nextWord = words.getWord(); // ���� �ܾ �̸� ���´�.
}

void gameLogic::init()
{
	setlocale(LC_ALL, "korean");

	words.addWord(L"��������");
	words.addWord(L"�Ǳ���");
	words.addWord(L"����");
	words.addWord(L"��¿Ƽ��");
	words.addWord(L"���н�");
	words.addWord(L"��������");
	words.addWord(L"��û���");
	words.addWord(L"��ī��������");
	words.addWord(L"����������");
	words.addWord(L"����");
	words.addWord(L"���ߵ���");
	words.addWord(L"��ٻ�");
	words.addWord(L"ŷ�޳�");
	words.addWord(L"���߽�");
	words.addWord(L"������");
	words.addWord(L"�����ڰ�");
	words.addWord(L"������");
	words.addWord(L"������");
	words.addWord(L"����");
	words.addWord(L"Ķ��");
	words.addWord(L"���񱸾�");
	words.addWord(L"���");
	words.addWord(L"�ݸ�");
	words.addWord(L"�����");
	words.addWord(L"������");
	words.addWord(L"������");
	words.addWord(L"����ȣ");
	words.addWord(L"������");
	words.addWord(L"��������");
	words.addWord(L"���Գ�");
	words.addWord(L"�پȲ�");
	words.addWord(L"�ٲٲ�");
	words.addWord(L"������");
	words.addWord(L"�����");
	words.addWord(L"������");
	words.addWord(L"Ȯ����");
	words.addWord(L"�ڰ���õ");
	words.addWord(L"�������");
	words.addWord(L"��û���");
	words.addWord(L"�ڰ���õ");
	words.addWord(L"��Ȯ��");
	words.addWord(L"�����");
	words.addWord(L"������");
	words.addWord(L"��ʹ�");
	words.addWord(L"�����ߺ�");
	words.addWord(L"��ʹ�");
	words.addWord(L"����Ƴ�");
}

void gameLogic::timer()
{
	if (startTime == NULL)
		startTime = clock(); // startTime�� ���� ��� ���� �ð��� ����.

	currentTime = clock(); // ����ð�
	playTime = (currentTime - startTime) / CLOCKS_PER_SEC; // ���� �ð� - ���۽ð� ���� �� ������ ������
	wordPlayTime = (currentTime - wordStartTime) / CLOCKS_PER_SEC; // ����ð� - ����ܾ �޾ƿ� �ð��� �� ������ ������
}

