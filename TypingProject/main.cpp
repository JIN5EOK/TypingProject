#include <iostream>
#include <string>
#include "words.h"
int main()
{
	Words word;
	std::cout << "�ܾ� �߰��ϱ�" << std::endl;
	word.addWord("���");
	word.addWord("��");
	word.addWord("����");
	word.addWord("����");
	word.addWord("����"); // �ߺ��ܾ� �߰� X
	word.addWord("����");
	word.addWord("����");
	word.addWord("��");
	word.addWord("������");
	word.addWord("�Ѷ��");
	word.addWord("�ٳ���");
	word.addWord("�θ���");
	word.addWord("Ű��");


	word.printWords();

	std::cout << std::endl;
	std::cout << "2�� �ε��� �ܾ� �����" << std::endl;

	word.delWord(13);
	word.printWords();

	std::cout << std::endl;
	std::cout << "�ܾ� ���� ����ϱ�" << std::endl;
	std::cout << word.getWord() << std::endl;
	std::cout << word.getWord() << std::endl;
	std::cout << word.getWord() << std::endl;
	std::cout << word.getWord() << std::endl;
	std::cout << word.getWord() << std::endl;
	std::cout << word.getWord() << std::endl;
	std::cout << word.getWord() << std::endl;
}