#include "typingpractice.h"
#include "koreanInput.h"
#include "gameLogic.h"

void positionPractice() {
    system("cls"); // 화면 모두 지우기
    basicDraw();
    wordManagerDraw();
    keyboardDraw();

    typingPracticeLogic game;
    game.run();
}