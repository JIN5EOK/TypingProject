#include "typingpractice.h"
#include "koreanInput.h"
#include "gameLogic.h"

void positionPractice() {
    system("cls"); // ȭ�� ��� �����
    basicDraw();
    wordManagerDraw();
    keyboardDraw();

    typingPracticeLogic game;
    game.run();
}