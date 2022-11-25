#pragma once
#include <iostream>
#include <locale>
#include <conio.h> // 키입력에 관한 헤더
#include <map> // map
#include <vector>


/*
* 한글 입력에 필요한 코드나 값들을 맵 형태로 정리한 데이터들
*/
class hangulTables {
	// 한글 문자에 대응되는 초성 코드를 저장한 맵
	static std::map<wchar_t, int> choMap;
	// 한글 문자에 대응되는 중성 코드를 저장한 맵
	static std::map<wchar_t, int> joongMap;
	// 한글 문자에 대응되는 종성 코드를 저장한 맵
	static std::map<wchar_t, int> jongMap;
	// 아스키 코드에 대응되는 한글 코드를 저장한 맵
	static std::map<char, wchar_t> hangulMap;
	// 글쇠별 조합 가능한 경우를 모은 map, key가 원본 문자, vector상의 글자들은 해당 문자에 조합이 가능한 문자이다. 
	// vector상에서의 순서+1 을 수행하면 조합글쇠가 만들어짐
	static std::map <wchar_t, std::vector<wchar_t>> combineMap;
	// ㄳ ㅀ과 같은 글자에서 분리가 가능한 글자들을 저장한 맵 EX : 앉 + ㅣ -> 안지
	static std::map <wchar_t, std::vector<wchar_t>> detachMap;

public:
	// 맵에 해당 키에 대응하는 요소들이 존재하는지 알려주는 함수들
	static bool containHangul(char _code);
	static bool containCho(wchar_t _code);
	static bool containJoong(wchar_t _code);
	static bool containJong(wchar_t _code);
	static bool containCombine(wchar_t _code);
	static bool containDetach(wchar_t _code);
	// 키를 주면 요소를 리턴해주는 함수들
	static wchar_t ascii2Hangul(char _code);
	static int hangul2Cho(wchar_t _code);
	static int hangul2Jong(wchar_t _code);
	static int hangul2Joong(wchar_t _code);
	static std::vector<wchar_t> getCombine(wchar_t _code);
	static std::vector<wchar_t> getDetach(wchar_t _code);
};


class hangulChar {
	wchar_t text; // 입력 완료된 글자
	bool isComplete; // 입력이 완료된 글자인지 구분 (입력이 완료된 글자는 지우기 외에는 수정이 불가능해짐.)
	wchar_t choJoongJong[3]; // 초성,중성,종성을 저장하는 배열
	int cnt; // 현재 입력된 글자의 숫자 (0 : 없음, 1 : 초성, 2: 초성+중성, 3: 초성+중성+종성
	void combine(); // 입력된 초성,중성,종성으로 조합글자를 생성하여 text에 저장한다.
public:
	wchar_t getText(); // 조합된 글자를 리턴한다.
	void setCho(wchar_t); //초성을 설정한다
	void setJoong(wchar_t); //중성을 설정한다
	void setJong(wchar_t); // 종성을 설정한다
	wchar_t getCho(); // 초성을 리턴한다
	wchar_t getJoong(); // 중성을 리턴한다
	wchar_t getJong(); // 종성을 리턴한다
	bool getComplete(); // 입력이 완료되었는지를 반환한다.
	void setComplete(); // 입력완료를 설정한다
	int erase(); // 초성,중성,종성을 하나씩 지운다, 지울글자가 하나만 남으면 eraseAll을 호출시킨다.
	void eraseAll(); // 모두 지운다.
	int getCnt(); // 현재 입력된 글자의 수를 리턴한다.
	void copyText(hangulChar); // 매개변수 hangulChar의 내용을 복사해 가져온다
};


class korInput {
	static bool isKor; // 한영키(ALT키 누르는게 안되서 Tab키로 설정) 이 눌렸는지를 저장하는 bool
	static hangulChar* hanguls; // 조합이 완료된 한글을 저장하는 배열
	static int hangulCnt; // 조합이 완료된 한글의 개수
	static int cursor; // 문자열을 가리키는 커서
	const static int maxCount; // 최대 문자열
	static void cursorRight(); // 커서를 오른쪽으로 옮긴다.
	static void cursorLeft(); // 커서를 왼쪽으로 옮긴다.
	static int combineHangul(wchar_t, int, wchar_t&); // combineMap에 기반하여 한글을 조합한다.
	static int detachJong(wchar_t); // 종성에 모음을 입력했을때 detachMap에 기반하여 분리시키기
	static void setCurrCho(wchar_t); // 현재 커서가 가리키는 한글문자의 초성을 변경한다.
	static void setCurrJoong(wchar_t); // 현재 커서가 가리키는 한글문자의 중성을 변경한다.
	static void setCurrJong(wchar_t); // 현재 커서가 가리키는 한글문자의 종성을 변경한다.
	static int insertNextSlot(wchar_t _cho = NULL, wchar_t _joong = NULL, wchar_t _jong = NULL); // 커서를 한칸 옮기고 새로운 글자를 삽입, 매개변수로 넘어온 초,중,종성으로 채운다.
	static int chkCombine(int); // 입력받은 문자가 한글 조합이 가능한지를 체크하고 가능하면 CombineHangul을 실행해 조합을 수행한다.
	static int chkDetach(int); // 입력받은 문자와 입력된 종성의 분리가 가능한지를 체크하고 가능하면 detachJong을 실행해 분리를 수행한다.
	static int chkInsert(int); // 초성,중성,종성의 입력이 가능한지 확인한다.
	static int insertKor(int); // 한글의 입력을 수행한다.
	static int insertAscii(wchar_t); // 아스키코드의 입력을 수행한다.
	static int rightShift(); // 문자들을 우측으로 시프트한다.
	static int leftShift(int); // 문자들을 좌측으로 시프트한다
	static void eraseCursor(); // 백스페이스 기능
	static void deleteCursor(); // Delete 기능
	static bool isKorMode(); // 한영 켜져있는지 확인
	static void altEngKor(); // 한영 토글기능
public:
	static int inputBuffer(int); // 버퍼에 키 입력하기, 이것을 루프형태로 호출하는 동안 키입력을 받을 수 있다.
	static void printBuffer(); // 입력된 모든 문자들을 출력한다.
	static void printInfo(); // 디버깅 정보 호출
	static std::wstring getWString(); // 입력된 텍스트를 wstring형태로 반환한다
	static void eraseTexts();
};

void textcolor(int, int);