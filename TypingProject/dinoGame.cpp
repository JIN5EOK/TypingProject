#include "dinogame.h"
#include "gameLogic.h"
void typingGame() {
    system("cls");
    
    scoreDraw();
    basicDraw();
    dinousDraw();
    speechBubbleDraw();
    dinoGameLogic dgLogic;
    dgLogic.run();
    
}

void speechBubbleDraw()
{
    gotoxy(22, 2);
    cout << "∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥∥";
    gotoxy(21, 3);
    cout << "<                                                                          >";
    gotoxy(22, 4);
    cout << "                                                                            >";
    gotoxy(22, 5);
    cout << "                                                                            >";
    gotoxy(21, 6);
    cout << "<                                                                          >";
    gotoxy(22, 7); 
    cout << "∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣∣";
    gotoxy(15, 4);
    cout << "旨收收收收收旭";
    gotoxy(15, 5);
    cout << "早旨收收收收旬";
    gotoxy(16, 6);
    cout << "V";
}

void dinousDraw() {

    gotoxy(4, 8);
    cout << "         ###### " << endl;
    gotoxy(4, 9);
    cout << "         ## #####" << endl;
    gotoxy(4, 10);
    cout << "         #######" << endl;
    gotoxy(4, 11);
    cout << "     #   ####      " << endl;
    gotoxy(4, 12);
    cout << "     ##  #######  " << endl;
    gotoxy(4, 13);
    cout << "      ## ###### " << endl;
    gotoxy(4, 14);
    cout << "       ##########   " << endl;
    gotoxy(4, 15);
    cout << "        ########   " << endl;
    gotoxy(4, 16);
    cout << "         ######    " << endl;
    gotoxy(4, 17);
    cout << "          ##  #     " << endl;
    gotoxy(4, 18);
    cout << "              ##    ";


    // 夥款 斜葡
    gotoxy(2, 19);
    for (int i = 1; i < 50; i++)
        cout << "﹥";
}

void scoreDraw() {
    gotoxy(4, 1);
    cout << "score : 0";
}

void gameOver() {
    gotoxy(23, 5);
    cout << "﹥﹥﹥﹥﹥﹥  ﹥﹥﹥﹥﹥﹥  ﹥        ﹥  ﹥﹥﹥﹥﹥" << endl;
    gotoxy(23, 6);
    cout << "﹥            ﹥        ﹥  ﹥﹥    ﹥﹥  ﹥" << endl;
    gotoxy(23, 7);
    cout << "﹥    ﹥﹥﹥  ﹥﹥﹥﹥﹥﹥  ﹥ ﹥  ﹥ ﹥  ﹥﹥﹥﹥﹥" << endl;
    gotoxy(23, 8);
    cout << "﹥        ﹥  ﹥        ﹥  ﹥  ﹥﹥  ﹥  ﹥" << endl;
    gotoxy(23, 9);
    cout << "﹥﹥﹥﹥﹥﹥  ﹥        ﹥  ﹥   ﹥   ﹥  ﹥﹥﹥﹥﹥" << endl;

    gotoxy(25, 11);
    cout << "﹥﹥﹥﹥﹥﹥  ﹥      ﹥  ﹥﹥﹥﹥﹥  ﹥﹥﹥﹥﹥" << endl;
    gotoxy(25, 12);
    cout << "﹥        ﹥   ﹥    ﹥   ﹥          ﹥      ﹥" << endl;
    gotoxy(25, 13);
    cout << "﹥        ﹥    ﹥  ﹥    ﹥﹥﹥﹥﹥  ﹥﹥﹥﹥﹥" << endl;
    gotoxy(25, 14);
    cout << "﹥        ﹥     ﹥﹥     ﹥          ﹥﹥﹥" << endl;
    gotoxy(25, 15);
    cout << "﹥﹥﹥﹥﹥﹥      ﹥      ﹥﹥﹥﹥﹥  ﹥  ﹥﹥﹥";
}