
#include <iostream>
#include <locale> // �����ڵ� ���� ���
#include <Windows.h> // ������ Ű�ڵ带 �������� include
#include <conio.h> // Ű�Է¿� ���� ���
#include <map> // map
#include <vector>
#include "koreanInput.h"
/*
* �����ڵ� �ѱ� ���� ����� ����� �ѱ� �Է±� ����
*/


bool korInput::isKor = true;
int korInput::hangulCnt = 0;
int korInput::cursor = -1;
const int korInput::maxCount = 30;
hangulChar* korInput::hanguls = new hangulChar[maxCount + 2];

void korInput::cursorRight() {
	// ���ڿ��� ����Ű�� Ŀ���� �������� �̵���Ų��.

hanguls[cursor].setComplete();

if (cursor < hangulCnt - 1)
	cursor++;

}
void korInput::cursorLeft() {
	// ���ڿ��� ����Ű�� Ŀ���� �������� �̵���Ų��.
	hanguls[cursor].setComplete();

	if (cursor > -1)
	{
		cursor--;
	}
}
// �ʼ� �� = 0 ��= 1 �߼� �� = 0 1 23  ����  �� =1 
// �ʼ� * 588 + �߼� * 28 + ����
//

int korInput::combineHangul(wchar_t _target, int _input, wchar_t& _result)
{
	// �ѱ��� �����ϴ� ���
	// EX : �� ���� �ĸ� �Է��ϸ� �˰� �ǰ� ���� ���� �Է��ϸ� ���� ��

	if (hangulTables::containCombine(_target) == false) // ���� ���̺��� üũ�Ͽ� ������ �������� Ȯ��
		return -1; // �ۼ迡 �´� ������ �������� �ʴ´�.

	std::vector<wchar_t> v = hangulTables::getCombine(_target); // v�� ���� Ÿ�ٰ� ������ ���ڸ� Ű�� ���� ���� ���Ҹ� �����´�.
	std::vector<wchar_t>::iterator iter;

	int add = 1; // ���� �ۼ迡�� ������ ��.
	for (iter = v.begin(); iter != v.end(); iter++) // �Էµ� �ܾ �����ϴ� �ۼ���� �ݺ��ڷ� �ϳ��� �޾ƿ�.
	{
		if (*iter != NULL && _input == *iter)
		{
			_result = _target + add; // add���� ���� ���ڸ� �����Ѵ�, EX : ���� �����ڵ忡 1�� ���ϸ� ���� ���������
			return 0; // ���� ��ȯ�� ���������� 0�� �����Ѵ�.
		}

		add++; // �ݺ��ڰ� �ϳ��� �ݺ��ɶ����� ���� ���ڿ� ������ ���� 1�� ������.
	}

	return -1; // ���� ��ȯ�� ���������� -1�� �����Ѵ�.
}

int korInput::detachJong(wchar_t _joong) // �������� ������ �Է������� �и���Ű��
{
	// ������ �и��ϴ� �Լ� 
	// EX : '��' ���ڸ� ģ ���¿��� '��'�� �Է��ϸ� '����'�� �ȴ�.

	wchar_t target = hanguls[cursor].getJong();

	if (hangulTables::containDetach(hanguls[cursor].getJong()) == true)
	{
		wchar_t jong = hangulTables::getDetach(target).at(0);
		wchar_t cho = hangulTables::getDetach(target).at(1);
		hanguls[cursor].setJong(jong); // ���� ������ ��ȯ�Ѵ�.
		insertNextSlot(cho, _joong); // ���� ���ڵ�� �Է��� �߼����� �� ���ڸ� �����.
		return 0;
	}
	return -1;

}

void korInput::setCurrCho(wchar_t _cho)
{
	hanguls[cursor].setCho(_cho);
}
void korInput::setCurrJoong(wchar_t _joong)
{
	hanguls[cursor].setJoong(_joong);
}
void korInput::setCurrJong(wchar_t _jong)
{
	hanguls[cursor].setJong(_jong);
}



// Ŀ���� ��ĭ �ű�� �ش� �ڸ��� �Ű������� �Ѿ�� ��,��,�������� ä��� �Լ�
int korInput::insertNextSlot(wchar_t _cho, wchar_t _joong, wchar_t _jong)
{
	if (hangulCnt >= maxCount)
		return -1;

	if (cursor < hangulCnt - 1) // Ŀ���� �ǵڿ� ���� ������ ���� ����Ʈ�� ����
	{
		cursorRight();
		if (rightShift() == -1)
			return -1; // ����Ʈ ����
	}
	else
	{
		hanguls[cursor].setComplete();
		hangulCnt++;
		cursorRight();
	}

	hanguls[cursor].eraseAll();

	if (_cho != NULL)
		setCurrCho(_cho);
	if (_joong != NULL)
		setCurrJoong(_joong);
	if (_jong != NULL)
		setCurrJong(_jong);

	return 0;
}

int korInput::chkCombine(int _input)
{
	if (hanguls[cursor].getComplete() == true)
		return -1;

	wchar_t result;
	int cnt = hanguls[cursor].getCnt();

	if (cnt == 2) // �߼�
	{
		wchar_t target = hanguls[cursor].getJoong();
		if (combineHangul(target, _input, result) == 0)
		{
			hanguls[cursor].setJoong(result);
			return 0;
		}
	}

	if (cnt == 3) // ����
	{
		wchar_t target = hanguls[cursor].getJong();
		if (combineHangul(target, _input, result) == 0)
		{
			hanguls[cursor].setJong(result);
			return 0;
		}
	}
	return -1;
}

int korInput::chkDetach(int _input)
{
	int cnt = hanguls[cursor].getCnt();

	if (cnt == 3 && hangulTables::containJoong(_input) == true) // �Էµ� �ۼ谡 �߼��̶�� �и��Ѵ�. (EX : �� + �� -> ���, �� + �� -> ����)
	{
		detachJong(_input);
		return 0;
	}
	return -1;
}

int korInput::chkInsert(int _input)
{
	int cnt = hanguls[cursor].getCnt();
	bool complete = hanguls[cursor].getComplete(); // �ۼ� �Ϸ�� ���ڸ� ���ο� ���� ������
	if (complete == true)
	{
		if (hangulTables::containCho(_input) == true)
		{
			insertNextSlot(_input);
			return 0;
		}
		else if (hangulTables::containJoong(_input) == true)
		{
			insertNextSlot(NULL, _input);
			return 0;
		}
	}

	if (cnt == 0 && hangulTables::containCho(_input) == true) // ���� �Է��� �ۼ谡 �ʼ����� ��� ������ ���ڶ��
	{
		setCurrCho(_input);
		return 0;
	}
	else if (cnt == 0 && hangulTables::containJoong(_input) == true) // �߼��� �Է����ٸ�
	{
		if (hanguls[cursor].getJoong() == NULL)
		{
			setCurrJoong(_input);
			return 0;
		}
		return -1;
	}

	if (cnt == 1 && hangulTables::containJoong(_input) == true) // ���� �Է��� �ۼ谡 �߼����� ��� ������ �������� Ȯ��
	{
		if (hanguls[cursor].getJoong() == NULL)
		{
			hanguls[cursor].setJoong(_input);
			return 0;
		}
	}
	else if (cnt == 1 && hangulTables::containCho(_input) == true)
	{
		insertNextSlot(_input);
		return 0;
	}
	else if (cnt == 1 && hangulTables::containJoong(_input) == true)
	{
		insertNextSlot(NULL, _input);
		return 0;
	}

	if (cnt == 2 && hangulTables::containJong(_input) == true && hanguls[cursor].getCho() != NULL)
	{
		hanguls[cursor].setJong(_input);
		return 0;
	}
	else if (cnt == 2 && hangulTables::containCho(_input) == true) // �ʼ����� �߼��� �Էµ� ��Ȳ���� �ʼ��� �Է�������
	{
		insertNextSlot(_input);
		return 0;
	}
	else if (cnt == 2 && hangulTables::containJoong(_input) == true) // �ʼ����� �߼��� �Էµ� ��Ȳ���� �߼��� �Է�������
	{
		insertNextSlot(NULL, _input);
		return 0;
	}

	if (cnt == 3 && hangulTables::containCho(_input) == true) // ������ �Էµ� ��Ȳ���� ���� �Է�
	{
		insertNextSlot(_input);
		return 0;
	} // �ƴ϶�� ���ںи� ����


	return -1;
}

int korInput::insertKor(int _hangulCode)
{
	if (hangulCnt > maxCount)
		return -1;

	if (cursor == -1) // ������� �� �Է½� Cnt++
	{
		hanguls[cursor + 1].eraseAll();
		hangulCnt++;
		cursorRight();
	}

	if (chkCombine(_hangulCode) == 0) // �ۼ� ���� ���� 
		return 0; // ������ ���� 0

	if (chkInsert(_hangulCode) == 0) // ���� ���� ���� 
		return 0; // ������ ���� 0

	if (chkDetach(_hangulCode) == 0) // ���� �и� �õ�
		return 0; // ������ ���� 0

	return -1; // ����
}
int korInput::insertAscii(wchar_t _char)
{
	if (hangulCnt >= maxCount)
		return -1;

	insertNextSlot();
	hanguls[cursor].setCho(_char);
	hanguls[cursor].setComplete();

	return 0;
}

int korInput::rightShift()
{
	if (cursor >= hangulCnt)
	{
		return -1;
	}

	for (int i = hangulCnt; i > cursor; i--)
	{
		hanguls[i].copyText(hanguls[i - 1]);
	}
	hanguls[cursor].eraseAll();
	hangulCnt++;

	return 0;
}

int korInput::leftShift(int _pos)
{
	if (_pos >= hangulCnt)
	{
		return -1;
	}

	for (int i = _pos; i < hangulCnt; i++)
	{
		hanguls[i].copyText(hanguls[i + 1]);
	}
	hangulCnt--;

	return 0;
}

void korInput::eraseCursor()
{
	if (cursor <= -1 || hangulCnt <= 0)
		return;
	if (hanguls[cursor].erase() == 0)
		return;
	if (leftShift(cursor) == -1)
		return;
	cursorLeft();
}


void korInput::deleteCursor()
{
	if (hangulCnt <= 0 || cursor == hangulCnt - 1)
		return;
	leftShift(cursor + 1);
}

bool korInput::isKorMode() {
	return isKor;
}
void korInput::altEngKor() {
	isKor = !isKor;
}

int korInput::inputBuffer(int input)
{

	if (input == 224) // �ƽ�Ű�ڵ�� ǥ���� �� ���� �Ϻ� Ű���� 224�� �߰��ڵ�. �ΰ����� �ڵ带 ��ȯ��.
		return -1;


	if (GetAsyncKeyState(VK_BACK) & 0x8000) // �齺���̽� �Է�
	{
		eraseCursor();
		return 0;
	}
	else if (GetAsyncKeyState(VK_TAB) & 0x8000) // ��Ű�� �ѿ���ȯ (���� ALTŰ�� �ȸ�����..)
	{
		altEngKor();
		return 0;
	}
	else if (input == 83)
	{
		deleteCursor();
		return 0;
	}
	else if (input == 75)
	{
		cursorLeft();
		return 0;
	}
	else if (input == 77)
	{
		cursorRight();
		return 0;
	}
	else
	{
		if (hangulTables::containHangul(input) == false || isKorMode() == false)// �ѱ��� �ƴ� ���
			insertAscii(input);
		else
		{
			input = hangulTables::ascii2Hangul(input); // �Էµ� �ƽ�Ű�ڵ带 �ѱ� �����ڵ�� 
			insertKor(input);
		}
		return 0;
	}

	return -1;
}
void korInput::printBuffer()
{
	for (int i = 0; i < hangulCnt; i++)
	{
		if (i == cursor) textcolor(0, 7);
		std::wcout << hanguls[i].getText();
		if (i == cursor) textcolor(15, 0);
	}
	std::cout << std::endl;
}
void korInput::printInfo()
{
	std::cout << "���� Ŀ�� ��ġ : " << cursor << " || �ؽ�Ʈ ���� : " << hangulCnt << std::endl;
	if (cursor >= 0)
	{
		std::cout << "�ʼ� >> ";
		std::wcout << hanguls[cursor].getCho();
		std::cout << " \n�߼� >> ";
		std::wcout << hanguls[cursor].getJoong();
		std::cout << " \n���� >> ";
		std::wcout << hanguls[cursor].getJong();
	}
	else
	{
		std::cout << "�Էµ� �ؽ�Ʈ�� ����.\n\n";
	}
	std::cout << std::endl;
}
std::wstring korInput::getWString()
{
	
	std::wstring wStr;
	
	for (int i = 0; i < hangulCnt; i++)
	{
		wStr += hanguls[i].getText();	
	}
	std::cout << std::endl;
	return wStr;
}
void korInput::eraseTexts()
{
	cursor = hangulCnt - 1;
	for (int i = hangulCnt; i > 0; i--)
	{
		leftShift(cursor--);
	}
		
}