#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;

//int keyboardArray[3][10] =
//{
//    {'げ', 'じ', 'ぇ', 'ぁ', 'さ', 'に', 'づ', 'ち','だ', 'つ'},
//    { 'け', 'い', 'し', 'ぉ', 'ぞ', 'で', 'っ', 'た', 'び' },
//    {'せ', 'ぜ', 'ず', 'そ', 'ば', 'ぬ', 'ぱ'}
//};

void basicDraw();
void keyboardDraw();
void scoreManagerText();
void wordManagerDraw();
void wordText();
void gotoxy(int x, int y);