#include "words.h"
#include <iostream>
#include <time.h>

// ������ �ܾ� �ϳ� ��ȯ
std::wstring Words::getWord() { 
	int randNum = rand() % count; // �������� �ܾ� ������ ���� ���������� ���
	return wordArr[randNum];
}
Words::~Words() // �Ҹ���
{
	delete[] wordArr; // �޸� ����
}
// ������
Words::Words() {
	srand((unsigned int)time(NULL)); // getWord���� �������� �̱� ���� ���� �ð��� �õ�� ���

	wordArr = new std::wstring[size];
	count = 0; // ���� ����� �ܾ��� ����
}
// �ܾ� �߰��ϱ�
int Words::addWord(std::wstring word) {
	if (count >= size)
		return -1; // �ܾ����� �ִ� ����� �Ѱܼ� �߰��� �� ����.

	for (int i = 0; i < count; i++)
	{
		if (wordArr[i] == word)
			return -2; // �̹� �ش� �ܾ ������
	}
	wordArr[count] = word;
	count++;
	return 0; // �ܾ� �߰� ����
}
// �ܾ� �����ϱ�
int Words::delWord(int index) {
	index--; // ����ڰ� �Է��ϴ� ���ڴ� 1���� �����ϴµ� �迭�� 0���� �����ϹǷ� 1�� ����.

	if (0 > index || index >= count) // ���� ���� ���̸� -1 ����
		return -1;
	else
	{
		for (index; index < count - 1; index++)
			wordArr[index] = wordArr[index + 1]; // ���� ��ҵ��� �ϳ��� ������ ���
		count--;
		return 0;
	}

	
}
void Words::printWords()
{
	std::cout << "<<�ܾ��忡 ����� �ܾ� ����Ʈ>>" << std::endl;
	for(int i = 0; i < count; i++)
	{
		if (i % 10 == 0)
			std::cout << std::endl;

		std::wcout << "[" << i + 1 << "] " << wordArr[i] << " ";
	}
	std::cout << std::endl;
}