#include <iostream>
#include "koreanInput.h"

void hangulChar::combine()
{
	if (choJoongJong[0] == NULL && choJoongJong[1] == NULL)
	{
		text = NULL; // �ʼ��� �߼��� ��������� �ƹ� ���ڵ� ���ٴ� ���̹Ƿ� NULL
		return;
	}
	if (choJoongJong[1] == NULL && choJoongJong[2] == NULL) // �߼��� ������ ����ִٸ� �ѱ��� ���յ��� �ʾ����Ƿ� �ʼ����� ���ڸ�
	{
		text = choJoongJong[0];
		return;
	}
	if (choJoongJong[0] == NULL && choJoongJong[2] == NULL) // �ʼ��� ������ ����ִٸ� �ѱ��� ���յ��� �ʾ����Ƿ� �߼����� ���ڸ�
	{
		text = choJoongJong[1];
		return;
	}

	int sum = 44032; // �����ڵ� �ѱ��ڵ尡 ���۵Ǵ� �ε���
	// 44032 + (�ʼ� * 588) + (�߼� * 28) + ���� = ���յ� �ѱ�
	if (choJoongJong[0] != NULL && hangulTables::containCho(choJoongJong[0]) == true)
		sum += hangulTables::hangul2Cho(choJoongJong[0]) * 588;
	if (choJoongJong[1] != NULL && hangulTables::containJoong(choJoongJong[1]) == true)
		sum += hangulTables::hangul2Joong(choJoongJong[1]) * 28;
	if (choJoongJong[2] != NULL && hangulTables::containJong(choJoongJong[2]) == true)
		sum += hangulTables::hangul2Jong(choJoongJong[2]);
	text = sum; // ���յ� ���� ����
}
wchar_t hangulChar::getText() // �ʼ�,�߼�,������ ���� ���� �ѱ��� �����Ͽ� ��������.
{
	return text;
}

void hangulChar::setCho(wchar_t _set)
{
	if (cnt < 1) // 1�̻� �Ѿ�� �ʵ���
		cnt = 1;

	choJoongJong[0] = _set;
	combine();
}
void hangulChar::setJoong(wchar_t _set)
{
	if (cnt < 2) // cnt���� 2�� �Ѿ�� �ʵ��� ��.
		cnt = 2;

	choJoongJong[1] = _set;
	combine();
}
void hangulChar::setJong(wchar_t _set)
{
	if (cnt < 3) // cnt���� 3�� �Ѿ�� �ʵ��� ��.
		cnt = 3;

	if (_set == NULL) // NULL�� �Է��� ������ cnt--
		cnt--;

	choJoongJong[2] = _set;
	combine();
}

wchar_t hangulChar::getCho()
{
	return choJoongJong[0];
}

wchar_t hangulChar::getJoong()
{
	return choJoongJong[1];
}

wchar_t hangulChar::getJong()
{
	return choJoongJong[2];
}

bool hangulChar::getComplete()
{
	return isComplete;
}
void hangulChar::setComplete()
{
	isComplete = true;
}

int hangulChar::erase()
{
	if (isComplete == true || cnt == 1 || choJoongJong[0] == NULL) // �ѹ� �Է��� �Ϸ��ߴ� ���ڰų� �ʼ��� �Էµ� ���ڴ� ������ ������
	{
		eraseAll();
		return -1;
	}
	else
	{
		choJoongJong[cnt - 1] = NULL;
		cnt--;
		combine();
		return 0;
	}
}

void hangulChar::eraseAll()
{
	choJoongJong[0] = NULL;
	choJoongJong[1] = NULL;
	choJoongJong[2] = NULL;
	cnt = 0;
	isComplete = false;
	combine();
}

int hangulChar::getCnt() {
	return cnt;
}

void hangulChar::copyText(hangulChar _hc)
{
	this->isComplete = _hc.isComplete;
	this->cnt = _hc.cnt;
	this->choJoongJong[0] = _hc.choJoongJong[0];
	this->choJoongJong[1] = _hc.choJoongJong[1];
	this->choJoongJong[2] = _hc.choJoongJong[2];
	this->text = _hc.text;
}