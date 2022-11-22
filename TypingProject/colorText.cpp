#include <Windows.h>
#include "koreanInput.h"

void textcolor(int _foreground, int _background)
{
	int color = _foreground + _background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}