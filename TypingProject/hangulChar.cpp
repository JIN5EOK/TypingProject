#include <iostream>
#include "koreanInput.h"

void hangulChar::combine()
{
	if (choJoongJong[0] == NULL && choJoongJong[1] == NULL)
	{
		text = NULL; // 초성과 중성이 비어있으면 아무 글자도 없다는 뜻이므로 NULL
		return;
	}
	if (choJoongJong[1] == NULL && choJoongJong[2] == NULL) // 중성과 종성이 비어있다면 한글이 조합되지 않았으므로 초성부의 글자만
	{
		text = choJoongJong[0];
		return;
	}
	if (choJoongJong[0] == NULL && choJoongJong[2] == NULL) // 초성과 종성이 비어있다면 한글이 조합되지 않았으므로 중성부의 글자만
	{
		text = choJoongJong[1];
		return;
	}

	int sum = 44032; // 유니코드 한글코드가 시작되는 인덱스
	// 44032 + (초성 * 588) + (중성 * 28) + 종성 = 조합된 한글
	if (choJoongJong[0] != NULL && hangulTables::containCho(choJoongJong[0]) == true)
		sum += hangulTables::hangul2Cho(choJoongJong[0]) * 588;
	if (choJoongJong[1] != NULL && hangulTables::containJoong(choJoongJong[1]) == true)
		sum += hangulTables::hangul2Joong(choJoongJong[1]) * 28;
	if (choJoongJong[2] != NULL && hangulTables::containJong(choJoongJong[2]) == true)
		sum += hangulTables::hangul2Jong(choJoongJong[2]);
	text = sum; // 조합된 글자 세팅
}
wchar_t hangulChar::getText() // 초성,중성,종성의 값에 따라 한글을 조합하여 리턴해줌.
{
	return text;
}

void hangulChar::setCho(wchar_t _set)
{
	if (cnt < 1) // 1이상 넘어가지 않도록
		cnt = 1;

	choJoongJong[0] = _set;
	combine();
}
void hangulChar::setJoong(wchar_t _set)
{
	if (cnt < 2) // cnt값이 2를 넘어가지 않도록 함.
		cnt = 2;

	choJoongJong[1] = _set;
	combine();
}
void hangulChar::setJong(wchar_t _set)
{
	if (cnt < 3) // cnt값이 3을 넘어가지 않도록 함.
		cnt = 3;

	if (_set == NULL) // NULL값 입력이 들어오면 cnt--
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
	if (isComplete == true || cnt == 1 || choJoongJong[0] == NULL) // 한번 입력을 완료했던 글자거나 초성만 입력된 글자는 완전히 지워짐
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