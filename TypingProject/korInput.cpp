
#include <iostream>
#include <locale> // 유니코드 관련 헤더
#include <Windows.h> // 윈도우 키코드를 쓰기위해 include
#include <conio.h> // 키입력에 관한 헤더
#include <map> // map
#include <vector>
#include "koreanInput.h"
/*
* 유니코드 한글 조합 방식을 사용한 한글 입력기 구현
*/


bool korInput::isKor = true;
int korInput::hangulCnt = 0;
int korInput::cursor = -1;
const int korInput::maxCount = 30;
hangulChar* korInput::hanguls = new hangulChar[maxCount + 2];

void korInput::cursorRight() {
	// 문자열을 가리키는 커서를 우측으로 이동시킨다.

hanguls[cursor].setComplete();

if (cursor < hangulCnt - 1)
	cursor++;

}
void korInput::cursorLeft() {
	// 문자열을 가리키는 커서를 좌측으로 이동시킨다.
	hanguls[cursor].setComplete();

	if (cursor > -1)
	{
		cursor--;
	}
}
// 초성 ㄱ = 0 ㄲ= 1 중성 ㅏ = 0 1 23  종성  ㄱ =1 
// 초성 * 588 + 중성 * 28 + 종성
//

int korInput::combineHangul(wchar_t _target, int _input, wchar_t& _result)
{
	// 한글을 조합하는 기능
	// EX : 구 에서 ㅔ를 입력하면 궤가 되고 갑에 ㅅ를 입력하면 ㅅ이 됨

	if (hangulTables::containCombine(_target) == false) // 조합 테이블을 체크하여 조합이 가능한지 확인
		return -1; // 글쇠에 맞는 조합이 존재하지 않는다.

	std::vector<wchar_t> v = hangulTables::getCombine(_target); // v에 현재 타겟과 동일한 문자를 키로 갖는 벡터 원소를 가져온다.
	std::vector<wchar_t>::iterator iter;

	int add = 1; // 원본 글쇠에서 더해줄 값.
	for (iter = v.begin(); iter != v.end(); iter++) // 입력된 단어에 대응하는 글쇠들을 반복자로 하나씩 받아옴.
	{
		if (*iter != NULL && _input == *iter)
		{
			_result = _target + add; // add값을 더해 글자를 조합한다, EX : ㄹ의 유니코드에 1을 더하면 ㄺ이 만들어진다
			return 0; // 문자 변환에 성공했으면 0을 리턴한다.
		}

		add++; // 반복자가 하나씩 반복될때마다 원본 문자에 더해줄 값을 1씩 더해줌.
	}

	return -1; // 문자 변환에 실패했으면 -1을 리턴한다.
}

int korInput::detachJong(wchar_t _joong) // 종성에서 모음을 입력했을때 분리시키기
{
	// 종성을 분리하는 함수 
	// EX : '없' 문자를 친 상태에서 'ㅣ'를 입력하면 '업시'가 된다.

	wchar_t target = hanguls[cursor].getJong();

	if (hangulTables::containDetach(hanguls[cursor].getJong()) == true)
	{
		wchar_t jong = hangulTables::getDetach(target).at(0);
		wchar_t cho = hangulTables::getDetach(target).at(1);
		hanguls[cursor].setJong(jong); // 현재 종성을 변환한다.
		insertNextSlot(cho, _joong); // 남은 글자들과 입력한 중성으로 새 글자를 만든다.
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



// 커서를 한칸 옮기고 해당 자리에 매개변수로 넘어온 초,중,종성으로 채우는 함수
int korInput::insertNextSlot(wchar_t _cho, wchar_t _joong, wchar_t _jong)
{
	if (hangulCnt >= maxCount)
		return -1;

	if (cursor < hangulCnt - 1) // 커서가 맨뒤에 있지 않으면 우측 시프트를 실행
	{
		cursorRight();
		if (rightShift() == -1)
			return -1; // 시프트 실패
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

	if (cnt == 2) // 중성
	{
		wchar_t target = hanguls[cursor].getJoong();
		if (combineHangul(target, _input, result) == 0)
		{
			hanguls[cursor].setJoong(result);
			return 0;
		}
	}

	if (cnt == 3) // 종성
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

	if (cnt == 3 && hangulTables::containJoong(_input) == true) // 입력된 글쇠가 중성이라면 분리한다. (EX : 업 + ㅣ -> 어비, 없 + ㅣ -> 업시)
	{
		detachJong(_input);
		return 0;
	}
	return -1;
}

int korInput::chkInsert(int _input)
{
	int cnt = hanguls[cursor].getCnt();
	bool complete = hanguls[cursor].getComplete(); // 작성 완료된 글자면 새로운 문자 삽입함
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

	if (cnt == 0 && hangulTables::containCho(_input) == true) // 현재 입력한 글쇠가 초성으로 사용 가능한 문자라면
	{
		setCurrCho(_input);
		return 0;
	}
	else if (cnt == 0 && hangulTables::containJoong(_input) == true) // 중성을 입력헀다면
	{
		if (hanguls[cursor].getJoong() == NULL)
		{
			setCurrJoong(_input);
			return 0;
		}
		return -1;
	}

	if (cnt == 1 && hangulTables::containJoong(_input) == true) // 현재 입력한 글쇠가 중성으로 사용 가능한 문자인지 확인
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
	else if (cnt == 2 && hangulTables::containCho(_input) == true) // 초성없이 중성만 입력된 상황에서 초성을 입력했을때
	{
		insertNextSlot(_input);
		return 0;
	}
	else if (cnt == 2 && hangulTables::containJoong(_input) == true) // 초성없이 중성만 입력된 상황에서 중성을 입력했을때
	{
		insertNextSlot(NULL, _input);
		return 0;
	}

	if (cnt == 3 && hangulTables::containCho(_input) == true) // 종성이 입력된 상황에서 종성 입력
	{
		insertNextSlot(_input);
		return 0;
	} // 아니라면 문자분리 수행


	return -1;
}

int korInput::insertKor(int _hangulCode)
{
	if (hangulCnt > maxCount)
		return -1;

	if (cursor == -1) // 비어있을 때 입력시 Cnt++
	{
		hanguls[cursor + 1].eraseAll();
		hangulCnt++;
		cursorRight();
	}

	if (chkCombine(_hangulCode) == 0) // 글쇠 조합 수행 
		return 0; // 성공시 리턴 0

	if (chkInsert(_hangulCode) == 0) // 문자 삽입 수행 
		return 0; // 성공시 리턴 0

	if (chkDetach(_hangulCode) == 0) // 문자 분리 시도
		return 0; // 성공시 리턴 0

	return -1; // 실패
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

	if (input == 224) // 아스키코드로 표현할 수 없는 일부 키들은 224와 추가코드. 두가지의 코드를 반환함.
		return -1;


	if (GetAsyncKeyState(VK_BACK) & 0x8000) // 백스페이스 입력
	{
		eraseCursor();
		return 0;
	}
	else if (GetAsyncKeyState(VK_TAB) & 0x8000) // 탭키로 한영전환 (우측 ALT키는 안먹혀서..)
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
		if (hangulTables::containHangul(input) == false || isKorMode() == false)// 한글이 아닐 경우
			insertAscii(input);
		else
		{
			input = hangulTables::ascii2Hangul(input); // 입력된 아스키코드를 한글 유니코드로 
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
	std::cout << "현재 커서 위치 : " << cursor << " || 텍스트 개수 : " << hangulCnt << std::endl;
	if (cursor >= 0)
	{
		std::cout << "초성 >> ";
		std::wcout << hanguls[cursor].getCho();
		std::cout << " \n중성 >> ";
		std::wcout << hanguls[cursor].getJoong();
		std::cout << " \n종성 >> ";
		std::wcout << hanguls[cursor].getJong();
	}
	else
	{
		std::cout << "입력된 텍스트가 없음.\n\n";
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