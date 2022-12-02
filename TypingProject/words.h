#ifndef __WORDS_H__
#define __WORDS_H__
#include <string>

#define MAXWORDLENGTH 30;

class Words {
	std::wstring *wordArr; // 단어 배열
	const int size = 50; // 단어장의 최대 사이즈	
	int count; // 현재 추가된 단어의 갯수
public:
	Words();
	~Words(); // 소멸자
	std::wstring getWord(); // 랜덤한 단어 하나 반환
	int addWord(std::wstring word); // 단어 추가하기
	int delWord(int num); // 단어 제거하기
	void printWords(); // 모든 단어 출력하기
};
#endif