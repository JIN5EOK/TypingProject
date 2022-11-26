#pragma once
#include <iostream>
#include <string>
#include "words.h"
#include <locale>
#include "koreanInput.h"
#include <Windows.h>
#include "mainscreen.h"
#include <time.h>

class typingPracticeLogic
{
	int accuracy = 100; // 정확도, 맞은 개수 * 60 / 입력개수
	int speed = 0; // 타수
	clock_t playTime; // 전체 플레이 시간 몇초 지났는지
	clock_t startTime; // 전체 플레이 시작시간
	clock_t wordPlayTime; // 현재 단어를 치기 시작한지 몇초 지났는지
	clock_t wordStartTime; // 현재 단어 타이핑을 시작한 시간
	clock_t currentTime; // 현재 시간
	wstring nextWord; // 다음단어




	void printing(wstring _target); // 화면표시 프린팅

	int chkPerfect(wstring _target); // 맞았는지 체크

	void timer(); // 플레이 시간 계산기

	void calcSpeed(); // 타수 계산기
public:
	void playPractice(); // 타자연습 메인함수, 현재 테스트 중

};

