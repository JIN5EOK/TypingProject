
#pragma once
#include <iostream>
#include <string>
#include "words.h"
#include <locale>
#include "koreanInput.h"
#include <Windows.h>
#include "mainscreen.h"
#include <time.h>

class gameLogic
{
public:
	Words words;
	int maxPlayCnt = 0; // 최대 몇개의 단어까지 플레이 가능한지
	int playCnt = 0; // 몇개 단어를 플레이 했는지
	wstring currWord; // 현재단어
	wstring nextWord; // 다음단어

	clock_t playTime; // 전체 플레이 시간이 얼마나 지났는지를 저장
	clock_t startTime; // 게임 플레이를 시작한 시간
	clock_t currentTime; // 현재 시간을 저장
	clock_t wordPlayTime; // 현재 단어를 치기 시작한지 몇초 지났는지
	clock_t wordStartTime; // 현재 단어 타이핑을 시작한 시간

	void init(); // 실행 직후 초기화 할 것
	int chkPerfect(); // 단어가 맞았는지 체크
	void getNextWord(); // 랜덤한 다음 단어 얻어오기
	void timer(); // 플레이 시간 계산기
	virtual void update() = 0; // 화면정보등 업데이트 함수, 가상함수
	virtual void updateSecond() = 0; // 1초마다 업데이트, 가상함수
	virtual void pressEnter() = 0; // 엔터 눌렀을때 실행되는 것
	virtual void run() = 0; // 게임 메인 함수
};



class typingPracticeLogic : protected gameLogic
{
	int answerCnt = 0; // 몇개를 맞췄는지
	int speedAvg = 0; // 스피드 평균
	int accuracyAvg = 0; // 스피드 평균
	int accuracy = 100; // 정확도, 맞은 개수 * 60 / 입력개수
	int speed = 0; // 타수
	
	void calcSpeed(); // 타수 계산기
	void calcAvg();
	void update(); // 업데이트
	void updateSecond(); // 1초마다 자동갱신
	void pressEnter();
public:
	void run(); // 타자연습 메인함수
};

class dinoGameLogic : protected gameLogic
{
	int defaultXPos = 95;
	int xPos = defaultXPos; // 현재 단어의 x축 
	int score = 0; //현재 점수
	void legUpdate();
	void moveWord();
	void update();
	void updateSecond();
	void scorePlus();
	void pressEnter();
	void gameOver();
	int isDead();
public:
	void run(); // 타자연습 메인함수
};
