#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;

//int keyboardArray[3][10] =
//{
//    {'��', '��', '��', '��', '��', '��', '��', '��','��', '��'},
//    { '��', '��', '��', '��', '��', '��', '��', '��', '��' },
//    {'��', '��', '��', '��', '��', '��', '��'}
//};

void basicDraw();
void keyboardDraw();
void scoreManagerText();
void wordManagerDraw();
void wordText();
void gotoxy(int x, int y);