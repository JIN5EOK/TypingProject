#include <iostream>
#include <string>
#include "words.h"
#include <locale>
#include "koreanInput.h"
#include <Windows.h>
#include "mainscreen.h"
#include <time.h>
#include "gameLogic.h"


int gameLogic::chkPerfect() // 단어가 맞는지를 체크한다.
{
	std::wstring inputString = korInput::getWString(); // 현재 입력된 단어를 얻어온다.
	if (currWord == inputString) // 입력해야 하는 단어와 입력된 단어를 비교하여 맞으면 0 틀리면 -1 리턴
		return 0;
	else
		return -1;
}

void gameLogic::getNextWord()
{
	korInput::eraseTexts(); // 입력기에 입력된 글자들을 지움

	currWord = nextWord; // 다음 단어를 현재 단어로 옮긴다.
	if (playCnt == maxPlayCnt - 1)
		nextWord = L"----"; // 마지막 단어일 경우 ----
	else
		nextWord = words.getWord(); // 다음 단어를 미리 얻어온다.
}

void gameLogic::init()
{
	setlocale(LC_ALL, "korean");

	words.addWord(L"낄끼빠빠");
	words.addWord(L"악깡버");
	words.addWord(L"군싹");
	words.addWord(L"어쩔티비");
	words.addWord(L"갑분싸");
	words.addWord(L"임포스터");
	words.addWord(L"멍청비용");
	words.addWord(L"네카라쿠배당토");
	words.addWord(L"오히려좋아");
	words.addWord(L"갓생");
	words.addWord(L"알잘딱깔센");
	words.addWord(L"사바사");
	words.addWord(L"킹받네");
	words.addWord(L"졌잘싸");
	words.addWord(L"난죽택");
	words.addWord(L"가보자고");
	words.addWord(L"점메추");
	words.addWord(L"저메추");
	words.addWord(L"군싹");
	words.addWord(L"캘박");
	words.addWord(L"좋댓구알");
	words.addWord(L"깐부");
	words.addWord(L"반모");
	words.addWord(L"어서오고");
	words.addWord(L"웃수저");
	words.addWord(L"ㄴㅇㄱ");
	words.addWord(L"무야호");
	words.addWord(L"슬세권");
	words.addWord(L"임포스터");
	words.addWord(L"레게노");
	words.addWord(L"꾸안꾸");
	words.addWord(L"꾸꾸꾸");
	words.addWord(L"별다줄");
	words.addWord(L"잼민이");
	words.addWord(L"금쪽이");
	words.addWord(L"확찐자");
	words.addWord(L"자강두천");
	words.addWord(L"복세편살");
	words.addWord(L"멍청비용");
	words.addWord(L"자강두천");
	words.addWord(L"소확행");
	words.addWord(L"마기꾼");
	words.addWord(L"마해자");
	words.addWord(L"삼귀다");
	words.addWord(L"만반잘부");
	words.addWord(L"삼귀다");
	words.addWord(L"오놀아놈");
}

void gameLogic::timer()
{
	if (startTime == NULL)
		startTime = clock(); // startTime이 없을 경우 현재 시간을 얻어옴.

	currentTime = clock(); // 현재시간
	playTime = (currentTime - startTime) / CLOCKS_PER_SEC; // 현재 시간 - 시작시간 값을 초 단위로 변경함
	wordPlayTime = (currentTime - wordStartTime) / CLOCKS_PER_SEC; // 현재시간 - 현재단어를 받아온 시간을 초 단위로 변경함
}

