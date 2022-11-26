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
	words.addWord(L"�鼮���б� ��ǻ�Ͱ��к�");
	words.addWord(L"�������� �� �ҳ���");
	words.addWord(L"����ȭ ��õ�� ȭ������");
	words.addWord(L"���ѻ�� �������� ���� �����ϼ�");
	words.addWord(L"�� ���� �� ������ �漺�� �� �Ͽ�");
	words.addWord(L"���ع��� ��λ��� ������ �⵵��");
	words.addWord(L"�ϴ����� �����ϻ� �츮���� ����");
	
	
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
