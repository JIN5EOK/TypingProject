#include <iostream>
#include <string>
#include "words.h"
int main()
{
	Words word;
	std::cout << "단어 추가하기" << std::endl;
	word.addWord("사과");
	word.addWord("감");
	word.addWord("포도");
	word.addWord("망고");
	word.addWord("망고"); // 중복단어 추가 X
	word.addWord("석류");
	word.addWord("수박");
	word.addWord("귤");
	word.addWord("오렌지");
	word.addWord("한라봉");
	word.addWord("바나나");
	word.addWord("두리안");
	word.addWord("키위");


	word.printWords();

	std::cout << std::endl;
	std::cout << "2번 인덱스 단어 지우기" << std::endl;

	word.delWord(13);
	word.printWords();

	std::cout << std::endl;
	std::cout << "단어 랜덤 출력하기" << std::endl;
	std::cout << word.getWord() << std::endl;
	std::cout << word.getWord() << std::endl;
	std::cout << word.getWord() << std::endl;
	std::cout << word.getWord() << std::endl;
	std::cout << word.getWord() << std::endl;
	std::cout << word.getWord() << std::endl;
	std::cout << word.getWord() << std::endl;
}