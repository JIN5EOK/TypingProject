#include <iostream>
#include <string>
#include "words.h"
#include <locale>
#include "koreanInput.h"
#include <Windows.h>


void krInputTester()
{
	setlocale(LC_ALL, "korean");

	Words words;
	words.addWord(L"백석대학교 컴퓨터공학부");
	words.addWord(L"남산위에 저 소나무");
	words.addWord(L"무궁화 삼천리 화려강산");
	words.addWord(L"대한사람 대한으로 길이 보전하세");
	words.addWord(L"이 기상과 이 맘으로 충성을 다 하여");
	words.addWord(L"동해물과 백두산이 마르고 닳도록");
	words.addWord(L"하느님이 보우하사 우리나라 만세");
	
	
	std::wstring s = words.getWord();

	korInput::printInfo();
	std::cout << std::endl;
	std::wcout << s << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	korInput::printBuffer();

	while (true)
	{
		if (_kbhit())
		{
			int input = _getch();

			if (input == 13)
			{
				std::wstring inputString = korInput::getWString();

				if (s == inputString)
					std::cout << "Perfect!" << std::endl;

				else
					std::cout << "Wrong.." << std::endl;

				Sleep(1000);
				s = words.getWord();
				system("cls");
				korInput::eraseTexts();
				korInput::printInfo();
				std::cout << std::endl;
				std::wcout << s << std::endl;
				std::cout << "--------------------------------------" << std::endl;
				korInput::printBuffer();
				continue;
			}
			if(korInput::inputBuffer(input) == 0)
			{
				std::wstring inputString = korInput::getWString();
				system("cls");
				korInput::printInfo();
				std::cout << std::endl;
				for (int i = 0; i < s.length(); i++)
				{
					if (i < inputString.length())
					{
						if(s[i] == inputString[i])
							textcolor(9, 0);
						else
							textcolor(4, 0);
					}

					std::wcout << s[i];
					textcolor(15, 0);
				}
				
				std::cout << std::endl;
				std::cout << "--------------------------------------" << std::endl;
				korInput::printBuffer();

			}
		}
	}
}
/*
int main()
{
	krInputTester();
}
*/
