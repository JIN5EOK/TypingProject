#include "words.h"
#include <iostream>
#include <time.h>

// 랜덤한 단어 하나 반환
std::wstring Words::getWord() { 
	int randNum = rand() % count; // 랜덤값을 단어 개수로 나눈 나머지값을 사용
	return wordArr[randNum];
}
Words::~Words() // 소멸자
{
	delete[] wordArr; // 메모리 해제
}
// 생성자
Words::Words() {
	srand((unsigned int)time(NULL)); // getWord에서 랜덤값을 뽑기 위해 현재 시간을 시드로 사용

	wordArr = new std::wstring[size];
	count = 0; // 현재 저장된 단어의 개수
}
// 단어 추가하기
int Words::addWord(std::wstring word) {
	if (count >= size)
		return -1; // 단어장의 최대 사이즈를 넘겨서 추가할 수 없음.

	for (int i = 0; i < count; i++)
	{
		if (wordArr[i] == word)
			return -2; // 이미 해당 단어가 존재함
	}
	wordArr[count] = word;
	count++;
	return 0; // 단어 추가 성공
}
// 단어 제거하기
int Words::delWord(int index) {
	index--; // 사용자가 입력하는 숫자는 1부터 시작하는데 배열은 0부터 시작하므로 1을 빼줌.

	if (0 > index || index >= count) // 범위 밖의 값이면 -1 리턴
		return -1;
	else
	{
		for (index; index < count - 1; index++)
			wordArr[index] = wordArr[index + 1]; // 뒤의 요소들을 하나씩 앞으로 당김
		count--;
		return 0;
	}

	
}
void Words::printWords()
{
	std::cout << "<<단어장에 저장된 단어 리스트>>" << std::endl;
	for(int i = 0; i < count; i++)
	{
		if (i % 10 == 0)
			std::cout << std::endl;

		std::wcout << "[" << i + 1 << "] " << wordArr[i] << " ";
	}
	std::cout << std::endl;
}